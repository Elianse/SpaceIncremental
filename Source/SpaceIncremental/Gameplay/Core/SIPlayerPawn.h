// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SIPlayerPawn.generated.h"

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

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
