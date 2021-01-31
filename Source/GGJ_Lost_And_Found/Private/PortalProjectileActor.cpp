// Fill out your copyright notice in the Description page of Project Settings.


#include "PortalProjectileActor.h"
#include "UObject/UObjectGlobals.h"

// Sets default values
APortalProjectileActor::APortalProjectileActor(const FObjectInitializer& ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	FScriptDelegate CollisionHit;
	CollisionHit.BindUFunction(this, TEXT("OnHit"));

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Collision Sphere"));
	CollisionSphere->InitSphereRadius(5.0f);
	CollisionSphere->SetGenerateOverlapEvents(true);
	CollisionSphere->BodyInstance.SetCollisionProfileName("BlockAll");
	CollisionSphere->OnComponentBeginOverlap.Add(CollisionHit);
	//CollisionSphere->OnComponentHit.AddDynamic(this, &APortalProjectileActor::OnHit);
	CollisionSphere->SetHiddenInGame(false);

	RootComponent = CollisionSphere;


	

	ProjectileMovement = ObjectInitializer.CreateDefaultSubobject<UProjectileMovementComponent>(this, TEXT("Projectile Movement"));
	ProjectileMovement->UpdatedComponent = CollisionSphere;
	ProjectileMovement->InitialSpeed = 3400.0f;
	ProjectileMovement->MaxSpeed = ProjectileMovement->InitialSpeed;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.5f;
}

void APortalProjectileActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{

}
