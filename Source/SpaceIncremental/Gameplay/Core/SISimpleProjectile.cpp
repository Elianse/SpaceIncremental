// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/SISimpleProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ASISimpleProjectile::ASISimpleProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MovementComponent"));

}

// Called when the game starts or when spawned
void ASISimpleProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASISimpleProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ProjectileLifetime -= DeltaTime;
	if (ProjectileLifetime <= 0)
	{
		Destroy();
	}
}

