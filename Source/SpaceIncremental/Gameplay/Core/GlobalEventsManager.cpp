// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/GlobalEventsManager.h"
#include "SIGenericGameObject.h"


void UGlobalEventsManager::ChangeGameState(EGameState InGameState)
{
	CurrentGameState = InGameState;
	OnGameStateChanged.Broadcast(CurrentGameState);
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
