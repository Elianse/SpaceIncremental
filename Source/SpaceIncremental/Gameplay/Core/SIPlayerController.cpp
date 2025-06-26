// Copyright Vladislav Loginov 2025 SpaceIncremental game


#include "SpaceIncremental/Gameplay/Core/SIPlayerController.h"
#include "SpaceIncremental/Gameplay/Core/SIPLayerPawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

void ASIPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	InPawn->OnDestroyed.AddDynamic(this, &ASIPlayerController::OnPawnDestroyed);
}

void ASIPlayerController::OnPawnDestroyed(AActor* DestroyedActor)
{
	TArray<AActor*> ActorList;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), ActorList);

	if (ActorList.Num() > 0)
	{
		const FTransform SpawnTransform = ActorList[0]->GetActorTransform();

		if (ASIPlayerPawn* RespawnedCharacter = GetWorld()->SpawnActor<ASIPlayerPawn>(CharacterClass, SpawnTransform))
		{
			Possess(RespawnedCharacter);
		}
	}
}