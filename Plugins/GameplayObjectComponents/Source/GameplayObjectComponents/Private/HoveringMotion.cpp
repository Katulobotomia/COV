// Fill out your copyright notice in the Description page of Project Settings.


#include "HoveringMotion.h"
#include <Components/MeshComponent.h>
#include <MessageLog.h>
#include <UObjectToken.h>
#include <Kismet/KismetMathLibrary.h>
#include <Kismet/GameplayStatics.h>

DEFINE_LOG_CATEGORY(LogHoveringMotion)

#define IS_DEDICATED_SERVER GetNetMode() == ENetMode::NM_DedicatedServer
#define IS_LISTEN_SERVER GetNetMode() == ENetMode::NM_ListenServer
#define IS_CLIENT GetNetMode() == ENetMode::NM_Client
#define IS_STANDALONE GetNetMode() == ENetMode::NM_Standalone

// Sets default values for this component's properties
UHoveringMotion::UHoveringMotion()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = true;
}

// Called when the game starts
void UHoveringMotion::BeginPlay()
{
	Super::BeginPlay();
}

void UHoveringMotion::DefaultToRootComponentAnimation_Internal()
{
	UE_LOG(LogHoveringMotion, Log, TEXT("No mesh set to hover. Defaulting to hovering the root component's position."));

	//	Make sure the owner has a root component
	check(Cast<USceneComponent>(GetOwner()->GetRootComponent()));

	//	The root component as the hovering component
	SetHoveringComponent(GetOwner()->GetRootComponent());

	bool bShouldAnimate = false;

	UE_LOG(LogHoveringMotion, Warning, TEXT("HoverMotionComponent is set to rotate the owner's root component. reminder that this is expensive when movement is replicated over the network ."));

	AActor* owner = GetOwner();

	if (owner->GetIsReplicated() && owner->bReplicateMovement)
	{
		//	The actor is set to replicate its movement over the network. Only authority should now animate the root motion as it then replicates its movement to the listening clients
		bool bAnimationAllowedOnDedicatedServers = (IS_DEDICATED_SERVER && !bAnimateOnlyLocally);
		bool bIsLocalOrListenServer = (IS_LISTEN_SERVER || IS_STANDALONE || IS_CLIENT);
		bShouldAnimate = (bAnimationAllowedOnDedicatedServers) || (bIsLocalOrListenServer);
	}
	else
	{
		//	Just hover on both client and server independently
		bShouldAnimate = true;
	}

	SetAnimating(bShouldAnimate);
}

void UHoveringMotion::RandomizeInitialRotation_Internal()
{
	FRotator randRot = UKismetMathLibrary::RandomRotator();
	ComponentToHover->SetRelativeRotation(randRot);
}

void UHoveringMotion::DefaultToDefaultInitialization_Internal()
{
	ensure(!bInitialized);

	//	If the animated mesh is not set, default to hovering the root component if it is a mesh itself
	if (!IsValid(ComponentToHover))
	{
		DefaultToRootComponentAnimation_Internal();
	}
}

void UHoveringMotion::SetHoveringComponent(USceneComponent* _componentToHover)
{
	if (IsValid(_componentToHover))
	{
		ComponentToHover = _componentToHover;
		bIsRotatingRootComponent = IsHoverComponentRootComponent();
		UE_LOG(LogHoveringMotion, Log, TEXT("Mesh to rotate set to (%s)"), *GetNameSafe(ComponentToHover));

		//	If enabled and possible, randomize initial rotation
		if (!bIsRotatingRootComponent && bRandomizeInitialRotation)
		{
			RandomizeInitialRotation_Internal();
		}

		if (bRandomizeHoverFrequencyInitialStartPhase && bHoverMovement)
		{
			InitialHoverOffset = (FMath::FRandRange(0.0f, (6.2831852f)) / HoverRepeatFrequency);
		}
	}
	else
	{
		UE_LOG(LogHoveringMotion, Error, TEXT("Could not set hovering mesh. The mesh was invalid."));
		FMessageLog("PIE").Error(FText::FromString("Could not set hovering mesh. The mesh was invalid."))->AddToken(FUObjectToken::Create(GetOwner()));
	}
}

void UHoveringMotion::SetAnimating(bool bShouldAnimate)
{
	bIsAnimating = bShouldAnimate;
	PrimaryComponentTick.SetTickFunctionEnable(bShouldAnimate);

	UE_LOG(LogHoveringMotion, Log, TEXT("%s animate (%s)."), *GetNameSafe(ComponentToHover), (bShouldAnimate)?(TEXT("Beginning")):(TEXT("Stopping")));
}

void UHoveringMotion::UpdateMeshTransform(float deltaTime)
{
	if (bRotate)
	{
		FRotator toRotateWith = FRotator(XAxisRotationSpeed, YAxisRotationSpeed, ZAxisRotationSpeed);
		ComponentToHover->AddLocalRotation(toRotateWith);
	}

	if (bHoverMovement)
	{
		float time = UGameplayStatics::GetRealTimeSeconds(this) * (6.2831852f) * (HoverRepeatFrequency);
		time = time + InitialHoverOffset;
		float sinValue = (UKismetMathLibrary::Sin(time));

		//	If we are rotating the root mesh, record the offset so we can calculate the original location of the mesh if it had not hovered at all
		if (bIsRotatingRootComponent)
		{
			FVector offset = FVector(HoverXMovementDistance, HoverYMovementDistance, HoverZMovementDistance) * deltaTime * sinValue;
			GetOwner()->SetActorLocation(GetOwner()->GetActorLocation() + offset);
		}
		else
		{
			ComponentToHover->SetRelativeLocation(FVector(HoverXMovementDistance * sinValue, HoverYMovementDistance * sinValue, HoverZMovementDistance * sinValue), false);
		}
	}
}

// Called every frame
void UHoveringMotion::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//	We initialize the component on first tick. BeginPlay is reserved for BP initialization if the user wants to do something there.
	if (!bInitialized)
	{
		//	Initialize using default configurations
		DefaultToDefaultInitialization_Internal();
	}

	//	Update the mesh transform
	UpdateMeshTransform(DeltaTime);
}