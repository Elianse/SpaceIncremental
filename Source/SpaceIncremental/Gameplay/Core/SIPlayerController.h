// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SIPlayerController.generated.h"

class ASIPlayerPawn;

UCLASS()
class SPACEINCREMENTAL_API ASIPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void OnPawnDestroyed(AActor* DestroyedActor);

public:

	UPROPERTY(EditAnywhere, Category = "Respawn")
	TSubclassOf<ASIPlayerPawn> CharacterClass;
	
};
