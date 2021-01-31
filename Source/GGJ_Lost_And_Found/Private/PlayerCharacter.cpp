// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"

APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	bSprintAction = false;
	bPickupAction = false;
	bTargetingAction = false;
	bDeath = false;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player FPS Camera"));
	Camera->SetupAttachment(GetMesh(), FName("headSocket"));
	Camera->bUsePawnControlRotation = true;
	Camera->PostProcessSettings.bOverride_MotionBlurAmount = true;

	Speaker = CreateDefaultSubobject<UAudioComponent>(TEXT("Player Speaker"));
	Speaker->AttachTo(RootComponent);

	bHaveGravityGun = false;
}

bool APlayerCharacter::GetSprintStatus()
{
	return bSprintAction;
}

bool APlayerCharacter::GetPickupStatus()
{
	return bPickupAction;
}

bool APlayerCharacter::GetJumpStatus()
{
	return bPressedJump;
}

bool APlayerCharacter::GetDeathStatus()
{
	return bDeath;
}

bool APlayerCharacter::GetTargetingStatus()
{
	return bTargetingAction;
}

void APlayerCharacter::SetHaveGravityGun(bool value)
{
	bHaveGravityGun = value;
}

bool APlayerCharacter::GetHaveGravityGun()
{
	return bHaveGravityGun;
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveX);
	PlayerInputComponent->BindAxis("MoveLateral", this, &APlayerCharacter::MoveY);

	PlayerInputComponent->BindAxis("LookYaw", this, &APlayerCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookPitch", this, &APlayerCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &APlayerCharacter::Jump);
	
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::Sprint);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &APlayerCharacter::Aim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &APlayerCharacter::Aim);

	PlayerInputComponent->BindAction("Shot", IE_Pressed, this, &APlayerCharacter::Shot);
}

void APlayerCharacter::MoveX(float value)
{
	if (!bTargetingAction) {
		FVector vDirection = FRotationMatrix(this->GetController()->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(vDirection, value);
	}
}

void APlayerCharacter::MoveY(float value)
{
	if (!bTargetingAction) {
		FVector vDirection = FRotationMatrix(this->GetController()->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(vDirection, value);
	}
}

void APlayerCharacter::Jump()
{
	bPressedJump = true;
}

void APlayerCharacter::Sprint()
{
	bSprintAction = !bSprintAction;

	if (bSprintAction) {
		GetCharacterMovement()->MaxWalkSpeed = 750.f;
	} else {
		GetCharacterMovement()->MaxWalkSpeed = 500.f;
	}
}

void APlayerCharacter::Aim()
{
	bTargetingAction = !bTargetingAction;
}

void APlayerCharacter::Shot()
{
	if (bHaveGravityGun) {
		FHitResult Hit;
		float fLenght = 5000.0;
		FCollisionQueryParams CollisionParams;
		CollisionParams.AddIgnoredActor(this);
		FVector StartLocation = Camera->GetComponentLocation();
		FVector EndLocation = Camera->GetComponentLocation() + ((Camera->GetComponentRotation()).Vector() * fLenght);

		GetWorld()->LineTraceSingleByChannel(Hit, StartLocation, EndLocation, ECollisionChannel::ECC_WorldStatic, CollisionParams);
		GLog->Log(Hit.ToString());
		if (Hit.bBlockingHit) {
			GetWorld()->SpawnActor<APortalActor>(PortalClass, Hit.Location, FRotator::ZeroRotator);
		} else {
			GLog->Log(this->GetName() + " : Raytracing -No Actor Hit-");
		}
	}
}
