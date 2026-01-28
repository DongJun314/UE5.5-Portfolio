// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interface/IVGameInterface.h"
#include "IVGameMode.generated.h"

/**
 * 
 */
UCLASS()
class INTERVERSE_API AIVGameMode : public AGameModeBase, public IIVGameInterface
{
	GENERATED_BODY()
	
public:
	AIVGameMode();

	virtual void OnPlayerScoreChanged(int32 NewPlayerScore) override;
	virtual void OnPlayerDead() override;
	virtual bool IsGameCleared() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Game")
	int32 ClearScore;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Game")
	int32 CurrentScore;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Category = "Game")
	uint8 bIsCleared : 1;

};
