// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"

#include "GlobalEventsManager.generated.h"

class ASIGeneticGameObject;

UENUM(BlueprintType, Blueprintable)
enum class EGameObjectType : uint8
{
	None,
	GameStartVolume,
	PlayerStart,
	EnemySpawner,
	HubObject,
	BattleObject,
};

UENUM(BlueprintType, Blueprintable)
enum class EGameState : uint8
{
	InTitleMenu,
	InScoreMenu,
	InPauseMenu,
	Chill,
	InBattle,
};

USTRUCT(BlueprintType, Blueprintable)
struct FGameObjectContainer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EGameObjectType ObjectsType = EGameObjectType::None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<ASIGenericGameObject>> GameObjects;
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGameStateChanged, EGameState, GameState);

UCLASS()
class SPACEINCREMENTAL_API UGlobalEventsManager : public UWorldSubsystem
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void ChangeGameState(EGameState InGameState);

	UFUNCTION(BlueprintCallable)
	EGameState GetCurrentGameState();

	UFUNCTION(BlueprintCallable)
	EGameState GetPreviousGameState();

	UFUNCTION(BlueprintCallable)
	void RegisterGameObject(ASIGenericGameObject* InGameObject, EGameObjectType InObjectType);

	UFUNCTION(BlueprintCallable)
	void HideObjectsOfType(EGameObjectType InObjectType);

	UFUNCTION(BlueprintCallable)
	void ShowObjectsOfType(EGameObjectType InObjectType);

public:

	UPROPERTY(BlueprintAssignable)
	FGameStateChanged OnGameStateChanged;

private:

	UPROPERTY(Transient)
	EGameState CurrentGameState = EGameState::InTitleMenu;

	UPROPERTY(Transient)
	EGameState PreviousGameState = EGameState::InTitleMenu;

	UPROPERTY(Transient)
	TMap<EGameObjectType, FGameObjectContainer> GameObjects;
	
};
