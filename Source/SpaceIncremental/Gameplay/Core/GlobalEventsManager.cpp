// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/GlobalEventsManager.h"
#include "SIGenericGameObject.h"

void UGlobalEventsManager::StartGame()
{
	if (bGameIsInProgress)
	{
		return;
	}

	HideObjectsOfType(EGameObjectType::GameStartVolume);
	HideObjectsOfType(EGameObjectType::HubObject);

	ShowObjectsOfType(EGameObjectType::BattleObject);
	ShowObjectsOfType(EGameObjectType::EnemySpawner);

	bGameIsInProgress = true;

	OnGameStateChanged.Broadcast(EGameState::InBattle);
}

void UGlobalEventsManager::FinishGame()
{
	if (!bGameIsInProgress)
	{
		return;
	}

	HideObjectsOfType(EGameObjectType::BattleObject);
	HideObjectsOfType(EGameObjectType::EnemySpawner);

	ShowObjectsOfType(EGameObjectType::GameStartVolume);
	ShowObjectsOfType(EGameObjectType::HubObject);

	bGameIsInProgress = false;

	OnGameStateChanged.Broadcast(EGameState::Chill);
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
