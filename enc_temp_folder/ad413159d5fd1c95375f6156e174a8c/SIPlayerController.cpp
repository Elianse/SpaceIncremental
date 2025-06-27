// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/SIPlayerController.h"
#include "SpaceIncremental/Gameplay/Core/SIPLayerPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "GlobalEventsManager.h"

void ASIPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	InPawn->OnDestroyed.RemoveAll(this);
	InPawn->OnDestroyed.AddUniqueDynamic(this, &ASIPlayerController::OnPawnDestroyed);
}

void ASIPlayerController::OnPawnDestroyed(AActor* DestroyedActor)
{
	UWorld* World = GetWorld();
	if (!IsValid(World))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerController::OnPawnDestroyed: World is invalid!"));
		return;
	}

	TArray<AActor*> ActorList;
	UGameplayStatics::GetAllActorsOfClass(World, APlayerStart::StaticClass(), ActorList);

	if (ActorList.Num() > 0)
	{
		const FTransform SpawnTransform = ActorList[0]->GetActorTransform();

		if (ASIPlayerPawn* RespawnedCharacter = World->SpawnActor<ASIPlayerPawn>(CharacterClass, SpawnTransform))
		{
			Possess(RespawnedCharacter);
		}
	}

	UGlobalEventsManager* EventsManager = Cast<UGlobalEventsManager>(World->GetSubsystem<UGlobalEventsManager>());
	if (!IsValid(EventsManager))
	{
		UE_LOG(LogTemp, Error, TEXT("ASIPlayerController::OnPawnDestroyed: UGlobalEventsManager is invalid!"));
		return;
	}

	EventsManager->ChangeGameState(EGameState::InScoreMenu);
}