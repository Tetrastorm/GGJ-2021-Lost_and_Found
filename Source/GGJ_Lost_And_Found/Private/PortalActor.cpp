// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalActor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.h"
#include "EngineUtils.h"

APortalActor::APortalActor()
{
	PrimaryActorTick.bCanEverTick = false;

	FScriptDelegate CollisionBeginOverlap;
	FScriptDelegate CollisionEndOverlap;

	CollisionBeginOverlap.BindUFunction(this, TEXT("TriggerEnter"));
	CollisionEndOverlap.BindUFunction(this, TEXT("TriggerExit"));

	TriggerComponent = CreateDefaultSubobject <UBoxComponent>(TEXT("Trigger Component"));
	TriggerComponent->SetRelativeLocation(FVector::ZeroVector);
	TriggerComponent->SetGenerateOverlapEvents(true);
	TriggerComponent->OnComponentBeginOverlap.Add(CollisionBeginOverlap);
	TriggerComponent->OnComponentEndOverlap.Add(CollisionEndOverlap);
	TriggerComponent->SetCollisionObjectType(ECC_Pawn);
	TriggerComponent->SetHiddenInGame(false);

	RootComponent = TriggerComponent;

	PrimaryPortalParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Portal Particle Primary"));
	PrimaryPortalParticle->SetupAttachment(RootComponent);
	PrimaryPortalParticle->SetRelativeLocation(FVector::ZeroVector);
	PrimaryPortalParticle->SetHiddenInGame(false);

	SecondaryPortalParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Portal Particle Secondary"));
	SecondaryPortalParticle->SetupAttachment(RootComponent);
	SecondaryPortalParticle->SetRelativeLocation(FVector::ZeroVector);
	SecondaryPortalParticle->SetHiddenInGame(false);

	Speaker = CreateDefaultSubobject<UAudioComponent>(TEXT("Player Speaker"));
	Speaker->SetupAttachment(RootComponent);
	Speaker->SetRelativeLocationAndRotation(FVector::ZeroVector, FRotator::ZeroRotator);
	Speaker->bAutoActivate = false;
	Speaker->SetHiddenInGame(false);

	bCanTrigger = true;
}

void APortalActor::TriggerEnter(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult)
{
	if (bCanTrigger) {
		if (LevelToLoad != "") {
			UGameplayStatics::OpenLevel(this, LevelToLoad, true);
			GLog->Log("Level Load");
		}
		else {
			APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);
			TArray<AActor*> Portals;

			UGameplayStatics::GetAllActorsOfClass(GetWorld(), APortalActor::StaticClass(), Portals);
			if (PlayerCharacter != nullptr && Portals.Num() > 0) {
				while (true) {
					int i = FMath::RandRange(0, Portals.Num() - 1);
					GLog->Log(FString::FromInt(i));
					APortalActor* PortalActor = Cast<APortalActor>(Portals[i]);

					if (PortalActor != this && PortalActor[i].LevelToLoad == "") {
						PortalActor->bCanTrigger = false;
						Speaker->Play();
						PlayerCharacter->SetActorLocation(PortalActor->GetActorLocation());
						break;
					}
				}
				GLog->Log("Teleport Player");
			}
		}
	}
}

void APortalActor::TriggerExit(class UPrimitiveComponent* HitComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComponent, int32 OtherBodyIdex, bool dFromSweep, const FHitResult& SweepResult)
{
	bCanTrigger = true;
}
