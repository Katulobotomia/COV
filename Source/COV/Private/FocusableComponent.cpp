// Fill out your copyright notice in the Description page of Project Settings.


#include "FocusableComponent.h"
#include <Kismet/KismetSystemLibrary.h>
#include <GameFramework/Actor.h>
#include <UnrealNetwork.h>
#include "COVBlueprintFunctionLibrary.h"

DEFINE_LOG_CATEGORY(LogFocusable)

// Sets default values for this component's properties
UFocusableComponent::UFocusableComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

void UFocusableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty, FDefaultAllocator>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UFocusableComponent, bCanBeFocusedAt);
}

void UFocusableComponent::SetIsFocusable(bool bIsFocusable)
{
	bCanBeFocusedAt = bIsFocusable;
	COV_LOG(LogFocusable, Log, TEXT("(%s) set as %s."), *GetNameSafe(GetOwner()), (bCanBeFocusedAt ? (TEXT("FOCUSABLE")) : (TEXT("UNFOCUSABLE"))));
}

// Called when the game starts
void UFocusableComponent::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void UFocusableComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}