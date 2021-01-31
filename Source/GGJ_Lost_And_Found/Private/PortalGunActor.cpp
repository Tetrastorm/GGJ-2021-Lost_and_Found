// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalGunActor.h"
#include "PlayerCharacter.h"


APortalGunActor::APortalGunActor()
{
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Portal Gun"));
	GunMesh->bNoSkeletonUpdate = true;
	GunMesh->SetupAttachment(RootComponent);
}

void APortalGunActor::Use()
{

}

void APortalGunActor::PickUp(AActor* OtherActor)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	GLog->Log("Picking up");

	if (Player) {
		GunMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		TriggerComponent->SetGenerateOverlapEvents(false);
		GunMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
		GunMesh->AttachToComponent(Player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("Weapon_Socket"));
		RootComponent->SetRelativeLocation(FVector::ZeroVector);
		GLog->Log(Player->GetName() + " Picking up : " + this->GetName());
	}
}