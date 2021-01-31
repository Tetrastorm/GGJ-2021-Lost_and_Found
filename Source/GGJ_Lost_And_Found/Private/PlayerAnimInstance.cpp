// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"
#include "PlayerCharacter.h"
#include "GameFramework/PawnMovementComponent.h"

UPlayerAnimInstance::UPlayerAnimInstance()
{
	bIsFalling = false;
	bIsDeath = false;
	bIsIronsight = false;

	MovementSpeed = 0.0;
	MovementDirection = 0.0;
}

void UPlayerAnimInstance::UpdateStatement()
{
	if (!bIsDeath && this->GetOwningActor() != nullptr) {
		APlayerCharacter* Player = Cast<APlayerCharacter>(this->GetOwningActor());

		if (Player != nullptr) {
			bIsFalling = Player->GetMovementComponent()->IsFalling();
			bCanJump = Player->GetJumpStatus();
			bIsDeath = Player->GetDeathStatus();
			bIsIronsight = Player->GetTargetingStatus();

			MovementSpeed = Player->GetVelocity().Size();
			MovementDirection = CalculateDirection(Player->GetVelocity(), Player->GetActorRotation());
		}
	}
}