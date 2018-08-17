// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "COVPlayerInput.h"
#include "COVCharacter.generated.h"

class UCameraComponent;
class ACOVPlayerController;
class UCOVSmoothAnimationComponent;

DECLARE_LOG_CATEGORY_EXTERN(COVCharacter, Log, All)

UCLASS()
class COV_API ACOVCharacter : public ACharacter, public ICOVPlayerInput
{
	GENERATED_BODY()
public:
	UPROPERTY(Category = "Animation", VisibleAnywhere)
		UCOVSmoothAnimationComponent* SmoothMotionComponent;

public:
	UPROPERTY(Category = "Interaction", EditDefaultsOnly)
		//	How far away can the player interact with things?
		float _maximumInteractionDistance = 200.0f;

	//	Constructor
	ACOVCharacter(const class FObjectInitializer& PCIP);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//	Registers replicated variables to the engine
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	//	PLAYERINPUT INTERFACE IMPLEMENTATIONS
	virtual void Input_E_Pressed_Implementation() override;
	virtual void Input_E_Released_Implementation() override;
	virtual void Input_W_Implementation(float amount) override;
	virtual void Input_D_Implementation(float amount) override;
	virtual void Input_Spacebar_Pressed_Implementation() override;
	virtual void Input_Spacebar_Released_Implementation() override;
	virtual void Input_LeftShift_Pressed_Implementation() override;
	virtual void Input_LeftShift_Released_Implementation() override;
	virtual void Input_LeftMouseButton_Pressed_Implementation() override;
	virtual void Input_LeftMouseButton_Released_Implementation() override;
	virtual void Input_MovementInput_Implementation(float amount) override;
	virtual void Input_MouseMovementY_Implementation(float amount) override;
	virtual void Input_MouseMovementX_Implementation(float amount) override;

private:
	//	INPUTS	#############################################################################################
	UFUNCTION(Category = "Movement", BLueprintCallable)
		//	Move character forward/back
		void Input_MoveForward(float amount);
	UFUNCTION(Category = "Movement", BlueprintCallable)
		//	Move character left/right
		void Input_MoveRight(float amount);
	//	#####################################################################################################

public:

	//	GETTERS	############################################################################################
	UFUNCTION(Category = "COVCharacter", BlueprintPure)
		//	Get the character's camera
		UCameraComponent* GetCharacterCamera() const;
	UFUNCTION(Category = "COVCharacter", BlueprintPure)
		//	Get the XYZCharacterController of this character
		ACOVPlayerController* GetCOVPlayerController() const;
	//	GETTERS	############################################################################################

private:
	UPROPERTY()
		bool _bDebugModeIsOn = false;
public:
	UFUNCTION(Category = "Console", Exec)
		void ShowAimingVectors(bool bOn);

	void DebugHelpers_TICK() const;
};
