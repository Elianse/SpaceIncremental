// Copyright Vladislav Loginov 2025 SpaceIncremental game

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "TitleMenu.generated.h"

/**
 * 
 */
UCLASS()
class SPACEINCREMENTAL_API UTitleMenu : public UCommonUserWidget
{
	GENERATED_BODY()

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
};
