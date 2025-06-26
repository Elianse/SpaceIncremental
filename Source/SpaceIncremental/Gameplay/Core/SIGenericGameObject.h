// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SIGenericGameObject.generated.h"

UCLASS()
class SPACEINCREMENTAL_API ASIGenericGameObject : public AActor
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent)
	void HideObject();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
