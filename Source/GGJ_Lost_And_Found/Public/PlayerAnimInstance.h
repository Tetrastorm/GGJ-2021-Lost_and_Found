// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class GGJ_LOST_AND_FOUND_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPlayerAnimInstance();

protected:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		bool bIsFalling;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		bool bIsDeath;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		bool bCanJump;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		bool bIsIronsight;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		float MovementSpeed;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Statement")
		float MovementDirection;

	UFUNCTION(BlueprintCallable, Category = "Animation")
		void UpdateStatement();
};
