// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/UI/TitleMenu.h"
#include "SpaceIncremental/Gameplay/Core/GlobalEventsManager.h"

void UTitleMenu::NativeConstruct()
{
	Super::NativeConstruct();
	/*UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("UTitleMenu::NativeConstruct: World is invalid!"));
		return;
	}

	UGlobalEventsManager* EventsManager = Cast<UGlobalEventsManager>(World->GetSubsystem<UGlobalEventsManager>());
	if (!IsValid(EventsManager))
	{
		UE_LOG(LogTemp, Error, TEXT("UTitleMenu::NativeConstruct: UGlobalEventsManager is invalid!"));
		return;
	}

	EventsManager->ChangeGameState(EGameState::InTitleMenu);*/

}

void UTitleMenu::NativeDestruct()
{
	Super::NativeDestruct();
	/*UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("UTitleMenu::NativeConstruct: World is invalid!"));
		return;
	}

	UGlobalEventsManager* EventsManager = Cast<UGlobalEventsManager>(World->GetSubsystem<UGlobalEventsManager>());
	if (!IsValid(EventsManager))
	{
		UE_LOG(LogTemp, Error, TEXT("UTitleMenu::NativeConstruct: UGlobalEventsManager is invalid!"));
		return;
	}

	EventsManager->ChangeGameState(EGameState::Chill);*/
}
