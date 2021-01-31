// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "ItemActor.generated.h"

UCLASS()
class GGJ_LOST_AND_FOUND_API AItemActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemActor();

	virtual void PickUp(AActor* OtherActor);
	
	UFUNCTION()
		void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult);

	virtual void Use();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Item Property|Collision")
		UBoxComponent* TriggerComponent;
};
