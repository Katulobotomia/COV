// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/EngineTypes.h"
#include "COVBlueprintFunctionLibrary.generated.h"







//	MACROS	#######################################################################################################################################
#define PRINT_FUNCTION *FString(__FUNCTION__).Append(":(").Append(FString::FormatAsNumber(__LINE__)).Append(")")

#define IS_SERVER GetNetMode() == ENetMode::NM_DedicatedServer || GetNetMode() == ENetMode::NM_ListenServer
//#define XYZLOG(category, log category, msg, ...) UE_LOG(category, log category, TEXT("%s: %s"), PRINT_FUNCTION, TEXT(msg), ##__VA_ARGS__)

#define IS_NOT_LOCALLY_CONTROLLED_WARNING if(!IsLocallyControlled()){UE_LOG(LogTemp, Warning, TEXT("%s: Should a non-client be calling this function?"), PRINT_FUNCTION)}


//	BEGINNING OF USE INTERFACE MAKRO	###############################################################################
#define USE_INTERFACE(_objectwithinterface, _interface, _functionname, ...) TWeakObjectPtr<UObject> interfaceObject = _objectwithinterface;\
if (interfaceObject.IsValid())\
{\
	if (interfaceObject->GetClass()->ImplementsInterface(U##_interface::StaticClass()))\
	{\
		I##_interface::Execute_##_functionname(interfaceObject.Get(), ##__VA_ARGS__);\
	}\
	else\
	{\
		UE_LOG(LogTemp, Log, TEXT("Using interface failed! The object (%s) does not implement such."), *UKismetSystemLibrary::GetDisplayName(_objectwithinterface));\
	}\
}\
//	END OF USING INTERFACE MAKRO	###################################################################################
//	###############################################################################################################################################






UCLASS()
class COV_API UCOVBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	//	Simplified line trace function. Parameters: 1) Starting position, 2) end position and 3) an actor in the world that will be "casting" this line trace
		static FHitResult SimpleTraceByChannel(FVector startPos, FVector endPos, UObject* InObj);
};

/*
Timer example
	FTimerHandle smallDelay;
	FTimerDelegate TimerCallback;
	TimerCallback.BindLambda([&]
	{
		SetActorTickEnabled(true);
	});

	GetWorld()->GetTimerManager().SetTimer(smallDelay, TimerCallback, 0.4f, false, 0.5f);
*/