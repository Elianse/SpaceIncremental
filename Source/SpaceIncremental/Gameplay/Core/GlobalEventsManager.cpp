// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/GlobalEventsManager.h"
#include "SIGenericGameObject.h"


void UGlobalEventsManager::ChangeGameState(EGameState InGameState)
{
	PreviousGameState = CurrentGameState;
	CurrentGameState = InGameState;

	UE_LOG(LogTemp, Log, TEXT("[GameState] game state changed to %s"), *GameStateToString(InGameState));
	OnGameStateChanged.Broadcast(CurrentGameState);
}

EGameState UGlobalEventsManager::GetCurrentGameState()
{
	return CurrentGameState;
}

EGameState UGlobalEventsManager::GetPreviousGameState()
{
	return PreviousGameState;
}

void UGlobalEventsManager::RegisterGameObject(ASIGenericGameObject* InGameObject, EGameObjectType InObjectType)
{
	FGameObjectContainer& ObjectContainer = GameObjects.FindOrAdd(InObjectType);
	ObjectContainer.GameObjects.Emplace(InGameObject);
}

void UGlobalEventsManager::HideObjectsOfType(EGameObjectType InObjectType)
{
	FGameObjectContainer& ObjectContainer = GameObjects.FindOrAdd(InObjectType);
	for (auto Object : ObjectContainer.GameObjects)
	{
		if (!IsValid(Object))
		{
			continue;
		}

		Object->HideObject();
	}
}

void UGlobalEventsManager::ShowObjectsOfType(EGameObjectType InObjectType)
{
	FGameObjectContainer& ObjectContainer = GameObjects.FindOrAdd(InObjectType);
	for (auto& Object : ObjectContainer.GameObjects)
	{
		if (!IsValid(Object))
		{
			continue;
		}

		Object->ShowObject();
	}
}

FString UGlobalEventsManager::GameStateToString(EGameState InGameState)
{
	switch (InGameState)
	{
	case EGameState::InBattle:
		return TEXT("In Battle");
	case EGameState::Chill:
		return TEXT("Chill");
	case EGameState::InPauseMenu:
		return TEXT("In Pause Menu");
	case EGameState::InScoreMenu:
		return TEXT("In Score Menu");
	case EGameState::InTitleMenu:
		return TEXT("In Title Menu");
	}
	return FString();
}
