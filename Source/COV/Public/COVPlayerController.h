// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "COVPlayerController.generated.h"

/**
 * 
 */

class ACOVCharacter;
class UScreenStack;

DECLARE_LOG_CATEGORY_EXTERN(COVPlayerController, All, Log)

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPawnPossessed, APawn*, OldPawn, APawn*, NewPawn);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPawnUnPossessed, APawn*, OldPawn);

UCLASS()
class COV_API ACOVPlayerController : public APlayerController
{
	GENERATED_BODY()

		ACOVPlayerController(const class FObjectInitializer& PCIP);

		//	Virtual function from APlayerController that allows custom input bindings
		virtual void SetupInputComponent() override;

public:

	UPROPERTY(EditAnywhere)
	//	X axis sensitivity
	float _XSensitivity = 1;

	UPROPERTY(EditAnywhere)
	//	Y axis sensitivity
	float _YSensitivity = 1;


	UFUNCTION(BlueprintPure)
	//	Get the AXYZ_Character this controller should be controlling
	ACOVCharacter* GetControlledCOVCharacter();

	UPROPERTY(BlueprintAssignable)
	FOnPawnPossessed OnPawnPossessed;
	UPROPERTY(BlueprintAssignable)
	FOnPawnUnPossessed OnPawnUnPossessed;
	
	virtual void OnPossess(APawn* InPawn) override;
	virtual void OnUnPossess() override;
	
	//	These are used to pipe the key events to the pawn itself. The pawn is supposed to implement the interface COVPlayerInput
	UFUNCTION(BlueprintNativeEvent)
		void Input_E_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_E_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_F_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_F_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Spacebar_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Spacebar_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftShift_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_Key_W(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_Key_D(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftShift_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftMouseButton_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftMouseButton_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_RightMouseButton_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_RightMouseButton_Released();
	UFUNCTION(BlueprintNativeEvent)
		void Input_MovementInput(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseMovementY(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseMovementX(float amount);
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseWheelUp();
	UFUNCTION(BlueprintNativeEvent)
		void Input_MouseWheelDown();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftControl_Pressed();
	UFUNCTION(BlueprintNativeEvent)
		void Input_LeftControl_Released();
};
