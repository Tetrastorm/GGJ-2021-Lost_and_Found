// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "PortalActor.generated.h"

UCLASS()
class GGJ_LOST_AND_FOUND_API APortalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortalActor();

	UFUNCTION()
		void TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerExit(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Portal|Collision")
		UBoxComponent* TriggerComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Portal|Visual")
		UParticleSystemComponent* PrimaryPortalParticle;
	UPROPERTY(EditDefaultsOnly, Category = "Portal|Visual")
		UParticleSystemComponent* SecondaryPortalParticle;

	UPROPERTY(EditDefaultsOnly, Category = "Portal|Sound")
		UAudioComponent* Speaker;

	UPROPERTY(EditAnywhere, Category = "Portal|Gameplay")
		FName LevelToLoad;

private:
	bool bCanTrigger;
};
