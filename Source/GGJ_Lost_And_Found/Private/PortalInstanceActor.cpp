// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalInstanceActor.h"

// Sets default values
APortalInstanceActor::APortalInstanceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APortalInstanceActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APortalInstanceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

