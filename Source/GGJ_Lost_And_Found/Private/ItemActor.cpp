// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemActor.h"
#include "PlayerCharacter.h"


AItemActor::AItemActor()
{
	PrimaryActorTick.bCanEverTick = false;

	FScriptDelegate CollisionBeginOverlap;
	CollisionBeginOverlap.BindUFunction(this, TEXT("TriggerEnter"));

	TriggerComponent = CreateDefaultSubobject <UBoxComponent>(TEXT("Trigger Component"));
	TriggerComponent->SetupAttachment(RootComponent);
	TriggerComponent->SetRelativeLocation(FVector::ZeroVector);
	TriggerComponent->SetGenerateOverlapEvents(true);
	TriggerComponent->OnComponentBeginOverlap.Add(CollisionBeginOverlap);
	TriggerComponent->SetCollisionObjectType(ECC_Pawn);
	TriggerComponent->SetHiddenInGame(false);
	TriggerComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	TriggerComponent->SetSimulatePhysics(false);

	RootComponent = TriggerComponent;
}

void AItemActor::PickUp(AActor* OtherActor)
{
	APlayerCharacter* Player = Cast<APlayerCharacter>(OtherActor);
	GLog->Log("Picking up");

	if (Player) {
		if (Player->GetPickupStatus()) {
			TriggerComponent->SetGenerateOverlapEvents(false);
			Player->AddToHands(this);
			GLog->Log(Player->GetName() + " Picking up : " + this->GetName());
		}
	}
}

void AItemActor::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult)
{
	GLog->Log(this->GetName() + " : Trigerring");
	PickUp(OtherActor);
}

void AItemActor::Use()
{

}
