// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ItemActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "PortalGunActor.generated.h"


UCLASS()
class GGJ_LOST_AND_FOUND_API APortalGunActor : public AItemActor
{
	GENERATED_BODY()

public:
	APortalGunActor();

	virtual void Use() override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Portal Gun Property|Visual")
		USkeletalMeshComponent* GunMesh;
};
