// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SISimpleProjectile.generated.h"

class UProjectileMovementComponent;

UCLASS()
class SPACEINCREMENTAL_API ASISimpleProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASISimpleProjectile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(EditAnywhere, BLueprintReadWrite)
	float ProjectileLifetime = 3.0f;

};
