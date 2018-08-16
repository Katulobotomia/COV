// Fill out your copyright notice in the Description page of Project Settings.

#include "COVSmoothAnimationComponent.h"
#include <UnrealNetwork.h>
#include <GameFramework/Character.h>
#include <GameFramework/CharacterMovementComponent.h>
#include "COVBlueprintFunctionLibrary.h"
#include <Kismet/KismetMathLibrary.h>
#include <Camera/CameraComponent.h>
#include <Components/SkeletalMeshComponent.h>
#include <Kismet/KismetSystemLibrary.h>
#include <DrawDebugHelpers.h>
#include <GameFramework/Pawn.h>
#include <GameFramework/PlayerController.h>

DEFINE_LOG_CATEGORY(COVSmoothAnimation)

#define IS_LOCALLY_CONTROLLED Cast<ACharacter>(GetOwner())->IsLocallyControlled()

// Sets default values for this component's properties
UCOVSmoothAnimationComponent::UCOVSmoothAnimationComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//PrimaryComponentTick.TickGroup = ETickingGroup::TG_PostUpdateWork;	//	IMPORTANT FOR TICK TO NOT LAG BEHIND IF DRAWING DEBUG THINGS
	AddTickPrerequisiteActor(GetOwner());
	bReplicates = true;
	//	Initialize the variable. Will be set properly in the BeginPlay	
	_defaultMaximumWalkingSpeed = _defaultMaximumWalkingSpeed;
}

// Called when the game starts
void UCOVSmoothAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	if (IS_LOCALLY_CONTROLLED)
		SetCurrentWalkingSpeed(_defaultMaximumWalkingSpeed);
}

void UCOVSmoothAnimationComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	//	Add replicated variables to list using this macro
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _cachedYaw, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, cachedPitch, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _aimingLocation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, cachedHipRotation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _bShouldBeRotatingHips, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _specialInterestLocation, COND_SkipOwner);
	DOREPLIFETIME_CONDITION(UCOVSmoothAnimationComponent, _currentMaximumMovementSpeed, COND_SkipOwner);
}

bool UCOVSmoothAnimationComponent::Server_SetAimingLocation_Validate(FVector aimingVector)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetAimingLocation_Implementation(FVector aimLoc)
{
	_aimingLocation = aimLoc;
}

bool UCOVSmoothAnimationComponent::Server_SetActorRotation_Validate(FRotator actorRotation)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetActorRotation_Implementation(FRotator actorRotation)
{
	cachedHipRotation = actorRotation;
}

bool UCOVSmoothAnimationComponent::Server_SetPitch_Validate(float pitch)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetPitch_Implementation(float pitch)
{
	cachedPitch = pitch;
}

bool UCOVSmoothAnimationComponent::Server_SetYaw_Validate(float yaw)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetYaw_Implementation(float yaw)
{
	_cachedYaw = yaw;
}

bool UCOVSmoothAnimationComponent::Server_SetCurrentWalkingSpeed_Validate(float currentWalkingSpeed)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetCurrentWalkingSpeed_Implementation(float currentWalkingSpeed)
{
	_currentMaximumMovementSpeed = currentWalkingSpeed;
	OnRep_currentMaximumMovementSpeed();
	//UE_LOG(XYZCharacter, Log, TEXT("%s: SERVER FUNCTION CALLED!."), PRINT_FUNCTION);
}

bool UCOVSmoothAnimationComponent::Server_SetLocationOfSpecialInterest_Validate(FVector loc)
{
	return true;
}

void UCOVSmoothAnimationComponent::Server_SetLocationOfSpecialInterest_Implementation(FVector location)
{
	_specialInterestLocation = location;
}

void UCOVSmoothAnimationComponent::OnRep_currentMaximumMovementSpeed()
{
	//UE_LOG(XYZCharacter, Log, TEXT("%s: ONREP!."), PRINT_FUNCTION);
	TWeakObjectPtr<UCharacterMovementComponent> charMove = Cast<ACharacter>(GetOwner())->GetCharacterMovement();

	if (charMove.IsValid())
	{
		Cast<ACharacter>(GetOwner())->GetCharacterMovement()->MaxWalkSpeed = _currentMaximumMovementSpeed;
	}
}

float UCOVSmoothAnimationComponent::GetYaw() const
{
	if (IS_LOCALLY_CONTROLLED)
	{
		return CalculateYaw();
	}
	return _cachedYaw;
}

float UCOVSmoothAnimationComponent::GetPitch() const
{
	if (IS_LOCALLY_CONTROLLED)
	{
		return CalculatePitch();
	}
	return cachedPitch;
}

FRotator UCOVSmoothAnimationComponent::GetHipRotation(float deltaTime) const
{
	if(IS_LOCALLY_CONTROLLED)
	{
		return CalculateHipRotation(deltaTime);
	}
	return cachedHipRotation;
}

bool UCOVSmoothAnimationComponent::GetShouldBeRotatingHips() const
{
	return _bShouldBeRotatingHips;
}

FVector UCOVSmoothAnimationComponent::GetAimingLocation() const
{
	return _aimingLocation;
}

FVector UCOVSmoothAnimationComponent::CalculateHeadLocation() const
{
	TWeakObjectPtr<USkeletalMeshComponent> ownerSkeletalMeshComp = Cast<USkeletalMeshComponent>(GetOwner()->GetComponentByClass(USkeletalMeshComponent::StaticClass()));

	ensureMsgf(ownerSkeletalMeshComp.IsValid(), TEXT("Owner (%s) did not have a SkeletalMeshComponent."), *UKismetSystemLibrary::GetDisplayName(GetOwner()));

	if (ownerSkeletalMeshComp.IsValid())
	{
		bool socketDoesExist = ownerSkeletalMeshComp->DoesSocketExist("Head");
		if (!socketDoesExist)
		{
			ensureMsgf(socketDoesExist, TEXT("Owner (%s) did not have a socket named 'head'."), *UKismetSystemLibrary::GetDisplayName(GetOwner()));
			return FVector(0, 0, 0);
		}

		FVector headLoc = ownerSkeletalMeshComp->GetSocketLocation("Head");
		return headLoc;
	}

	return FVector(0, 0, 0);
}

void UCOVSmoothAnimationComponent::SetYaw(float yaw)
{
	_cachedYaw = yaw;
	Server_SetYaw(yaw);
}

void UCOVSmoothAnimationComponent::SetPitch(float pitch)
{
	cachedPitch = pitch;
	Server_SetPitch(pitch);
}

void UCOVSmoothAnimationComponent::SetHipRotation(FRotator rot)
{
	cachedHipRotation = rot;
	Server_SetActorRotation(rot);
}

void UCOVSmoothAnimationComponent::SetShouldRotateHips(float inputAmount)
{
	_bShouldBeRotatingHips = inputAmount != 0.0f;
}

void UCOVSmoothAnimationComponent::SetCurrentWalkingSpeed(float currentWalkingSpeed)
{
	if (IS_LOCALLY_CONTROLLED)
	{
		_currentMaximumMovementSpeed = currentWalkingSpeed;
		OnRep_currentMaximumMovementSpeed();
		Server_SetCurrentWalkingSpeed(_currentMaximumMovementSpeed);
	}
}

void UCOVSmoothAnimationComponent::SetAimingLocation(FVector loc)
{
	_aimingLocation = loc;
	Server_SetAimingLocation(loc);
}

void UCOVSmoothAnimationComponent::SetLocationOfSpecialInterest(FVector location)
{
	_specialInterestLocation = location;
	Server_SetLocationOfSpecialInterest(location);
}

FVector UCOVSmoothAnimationComponent::GetCameraViewLocation() const
{
	APawn* pawn = Cast<APawn>(GetOwner());
	AController* controller = pawn->GetController();
	APlayerController* playerController = Cast<APlayerController>(controller);
	AActor* playerCameraManagerActor = Cast<AActor>(playerController->PlayerCameraManager);

	//	Ray starting point
	return playerCameraManagerActor->GetActorLocation();
}

FVector UCOVSmoothAnimationComponent::CalculateAimingLocation() const
{
	FHitResult RV_Hit(ForceInit);

	//	THIS FINALLY FIXED THE WHOLE CODE!!!! EVERYTHING IS WORKING PERFECTLY NOW AND IS FRAME ACCURATE AND NO LAG WHATSOEVER!!
	//	TRAIN CRASH! CHOOO CHOOO!

	//	Ray starting point
	FVector playerViewWorldLocation = GetCameraViewLocation();
	//	end point target direction
	FVector controllerForwardVector = Cast<AActor>(Cast<APawn>(GetOwner())->GetController())->GetActorForwardVector();
	
	float lineTraceLength = _aimingLocationTraceLength;

	RV_Hit = UCOVBlueprintFunctionLibrary::SimpleTraceByChannel(
		GetOwner(),
		playerViewWorldLocation + (controllerForwardVector),
		playerViewWorldLocation + (controllerForwardVector * lineTraceLength));

	if (RV_Hit.bBlockingHit)
	{
		FVector result = RV_Hit.ImpactPoint;
		return result;
	}
	else
	{
		FVector result = RV_Hit.TraceEnd;
		return result;
	}
}

FRotator UCOVSmoothAnimationComponent::GetRotationToTargetDirection() const
{
	if (AimOffsetMode == EAimOffsetCalculationMode::ControlRotation)
	{
		FRotator targetRot = Cast<ACharacter>(GetOwner())->GetControlRotation();
		return targetRot;
	}

	if (AimOffsetMode == EAimOffsetCalculationMode::AimLocation)
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(CalculateHeadLocation(), CalculateAimingLocation());
		return targetRot;
	}

	return FRotator(0, 0, 0);
}

float UCOVSmoothAnimationComponent::CalculateYaw() const
{
	float angleToStartRotatingHips = 125.0f;
	float angleToStopRotatingHips = 20.0f;
	float torsoMaxRotation = 140.0f;

	FRotator targetRot = GetRotationToTargetDirection();
	FRotator playerRot = Cast<ACharacter>(GetOwner())->GetActorRotation();
	FRotator deltaRot = UKismetMathLibrary::NormalizedDeltaRotator(playerRot, targetRot);

	//	If hips turn over too much...
	if (FMath::Abs(deltaRot.Yaw) > angleToStartRotatingHips)
	{
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw - 360.0f, -torsoMaxRotation, torsoMaxRotation);
		return -clampedYaw;
	}
	else   //	Need to rotate character towards _aimingVector
	{
		float clampedYaw = UKismetMathLibrary::ClampAngle(deltaRot.Yaw, -torsoMaxRotation, torsoMaxRotation);
		return -clampedYaw;
	}
}

float UCOVSmoothAnimationComponent::CalculatePitch() const
{
	FRotator controlRot = GetRotationToTargetDirection();

	if (controlRot.Pitch > 90)
	{
		return (controlRot.Pitch - 360.0f);
	}
	else
	{
		return controlRot.Pitch;
	}
}

FRotator UCOVSmoothAnimationComponent::CalculateHipRotation(float deltaTime) const
{
	FRotator goalRotation = GetRotationToTargetDirection();
	FRotator startRotation = cachedHipRotation;

	float absAngle = FMath::Abs(_cachedYaw);

	if (absAngle > _angleToStartRotatingHips || _bShouldBeRotatingHips)
	{
		float rotSpeed;
		float rotExp = 5.5f;	//	Hip rotation angle exponent

		_bShouldBeRotatingHips ? rotSpeed = _movementInputRotationSpeed : rotSpeed = (FMath::Pow((absAngle / _angleToStartRotatingHips), rotExp) * 0.25f);
		FRotator result = UKismetMathLibrary::RInterpTo(startRotation, goalRotation, deltaTime, rotSpeed);
		result.Pitch = 0;
		result.Roll = 0;
		return result;
	}

	return startRotation;
}

FVector UCOVSmoothAnimationComponent::GetLocationOfSpecialInterest() const
{
	return _specialInterestLocation;
}

FVector UCOVSmoothAnimationComponent::CalculateHeadLookAtLocation() const
{
	if (bAllowLocationOfInterestHeadRotation)
	{
		return GetLocationOfSpecialInterest();
	}
	else
	{
		return CalculateAimingLocation();
	}
}

FRotator UCOVSmoothAnimationComponent::CalculateHeadRotation() const
{
	FVector headLoc = CalculateHeadLocation();
	FVector targetLoc = CalculateHeadLookAtLocation();
	FRotator tempRot = UKismetMathLibrary::FindLookAtRotation(headLoc, targetLoc);
	FRotator headRot = FRotator(90.0f, 0, 90.0f);
	headRot += tempRot;

	return headRot;
}

void UCOVSmoothAnimationComponent::Update_AllAnimationVariables_TICK(float deltaTime)
{
	SetHipRotation(CalculateHipRotation(deltaTime));
	SetAimingLocation(CalculateAimingLocation());
	SetYaw(CalculateYaw());
	SetPitch(CalculatePitch());
}

// Called every frame
void UCOVSmoothAnimationComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Cast<APawn>(GetOwner())->IsLocallyControlled())
	{
		//	Creates cached variable values and sends them to the server
		Update_AllAnimationVariables_TICK(DeltaTime);
	}

	DrawDebugSphere(GetWorld(), GetAimingLocation(), 5.0f, 4, FColor(255, 0, 255, 1), false, 0.0f, 1, 1.0f);
	DrawDebugLine(GetWorld(), CalculateHeadLocation(), GetAimingLocation(), FColor(255, 0, 255, 1), false, 0.0f, 1, 0.5f);
}

