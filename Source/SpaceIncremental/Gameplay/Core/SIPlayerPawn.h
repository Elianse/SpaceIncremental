// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SISimpleProjectile.h"

#include "SIPlayerPawn.generated.h"

class UFloatingPawnMovement;

UCLASS()
class SPACEINCREMENTAL_API ASIPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASIPlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void MoveHorizontal(float InMovementDirection);

	UFUNCTION(BlueprintCallable)
	void MoveVertical(float InMovementDirection);

	UFUNCTION(BlueprintCallable)
	void Shoot();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float RotationSpeedMultiplyer = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	UFloatingPawnMovement* MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	TSubclassOf<ASISimpleProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FVector ProjectileOffset = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	float ShootSpeed = 0.25;
};
