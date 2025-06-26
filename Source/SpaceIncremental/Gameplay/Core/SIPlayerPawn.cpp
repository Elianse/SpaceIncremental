// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/SIPlayerPawn.h"
#include <GameFramework/FloatingPawnMovement.h>

// Sets default values
ASIPlayerPawn::ASIPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));

}

// Called when the game starts or when spawned
void ASIPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASIPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!IsValid(MovementComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerPawn::Tick: MovementComponent is invalid!"));
		return;
	}
	FVector LastInputVector = MovementComponent->GetLastInputVector();

	//Discard if there was no rcent input
	if (LastInputVector.IsNearlyZero())
	{
		return;
	}

	FRotator CurrentRotation = GetActorRotation();
	FRotator TargetRotation = LastInputVector.ToOrientationRotator();

	SetActorRotation(FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeedMultiplyer));
}

void ASIPlayerPawn::MoveHorizontal(float InMovementDirection)
{
	if (!IsValid(MovementComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerPawn::MoveHorizontal: MovementComponent is invalid!"));
		return;
	}
	MovementComponent->AddInputVector(FVector(0, InMovementDirection, 0));
}

void ASIPlayerPawn::MoveVertical(float InMovementDirection)
{
	if (!IsValid(MovementComponent))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerPawn::MoveVertical: MovementComponent is invalid!"));
		return;
	}
	MovementComponent->AddInputVector(FVector(InMovementDirection, 0, 0));
}

void ASIPlayerPawn::Shoot()
{
	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerPawn::Shoot: World is invalid!"));
		return;
	}

	FTransform ProjectileTransform = GetActorTransform();

	FVector ProjectileLocation = ProjectileTransform.GetLocation() + ProjectileTransform.GetRotation().RotateVector(FVector::ForwardVector * ProjectileOffset);
	ProjectileTransform.SetLocation(ProjectileLocation);

	ASISimpleProjectile* Projectile = World->SpawnActor<ASISimpleProjectile>(ProjectileClass, ProjectileTransform);
}

