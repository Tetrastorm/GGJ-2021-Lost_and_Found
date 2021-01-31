// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "PortalProjectileActor.generated.h"

UCLASS()
class GGJ_LOST_AND_FOUND_API APortalProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APortalProjectileActor(const FObjectInitializer& ObjectInitializer);

protected:

	UFUNCTION()
		void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

	UPROPERTY(VisibleAnywhere, Category = Physics)
		USphereComponent* CollisionSphere;
	UPROPERTY(VisibleAnywhere, Category = "Projectile")
		UProjectileMovementComponent *ProjectileMovement;

	UPROPERTY(EditDefaultsOnly, Category="Projectile")
		UParticleSystem* ProjectileParticle;
};
