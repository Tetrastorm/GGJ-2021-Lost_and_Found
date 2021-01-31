// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NPCCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/AudioComponent.h"
#include "PortalActor.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class GGJ_LOST_AND_FOUND_API APlayerCharacter : public ANPCCharacter
{
	GENERATED_BODY()
	
public:
	APlayerCharacter();

	UFUNCTION()
		bool GetSprintStatus();
	UFUNCTION()
		bool GetPickupStatus();
	UFUNCTION()
		bool GetJumpStatus();
	UFUNCTION()
		bool GetDeathStatus();
	UFUNCTION()
		bool GetTargetingStatus();

	UFUNCTION()
		void SetHaveGravityGun(bool value);
	UFUNCTION()
		bool GetHaveGravityGun();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

	void MoveX(float value);
	void MoveY(float value);

	void Jump();

	void Sprint();

	void Aim();
	void Shot();

	UPROPERTY(EditDefaultsOnly, Category = "PlayerProperty|Component")
		UCameraComponent* Camera;
	UPROPERTY(EditDefaultsOnly, Category = "PlayerProperty|Component")
		UAudioComponent* Speaker;

	UPROPERTY(EditDefaultsOnly, Category = "Weapon Property")
		TSubclassOf<class APortalActor> PortalClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		float fHealth;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		float fStamina;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		bool bHaveGravityGun;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		bool bSprintAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		bool bPickupAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		bool bTargetingAction;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "PlayerProperty|Status")
		bool bDeath;
};
