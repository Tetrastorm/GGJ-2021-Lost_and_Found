// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalGunActor.h"


APortalGunActor::APortalGunActor()
{
	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Portal Gun"));
	GunMesh->bNoSkeletonUpdate = true;
	GunMesh->SetupAttachment(RootComponent);
}

void APortalGunActor::Use()
{

}
