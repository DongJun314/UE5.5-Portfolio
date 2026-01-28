// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/IVGameMode.h"
#include "Player/IVPlayerController.h"

AIVGameMode::AIVGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Game/ArenaBattle/Blueprint/BP_IVCharacterPlayer.BP_IVCharacterPlayer_C"));
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}
	
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/Interverse.IVPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}	

	ClearScore = 1;
	CurrentScore = 0;
	bIsCleared = false;
}

void AIVGameMode::OnPlayerScoreChanged(int32 NewPlayerScore)
{
	AIVPlayerController* IVPlayerController = Cast<AIVPlayerController>(GetWorld()->GetFirstPlayerController());
	if (IVPlayerController)
	{
		IVPlayerController->GameScoreChanged(NewPlayerScore);
	}

	if (IVPlayerController->GetCurKilledScore() >= ClearScore)
	{
		IVPlayerController->GameClear();
	}
}

void AIVGameMode::OnPlayerDead()
{
	AIVPlayerController* IVPlayerController = Cast<AIVPlayerController>(GetWorld()->GetFirstPlayerController());
	if (IVPlayerController)
	{
		IVPlayerController->GameOver();
	}
}

bool AIVGameMode::IsGameCleared()
{
	return bIsCleared;
}

/*
실패->플레이어 죽음->GameMode에서 플레이어 죽어는지 체크->실패했다
성공->몬스터 죽었음->GameMode 함수 호출(***가 나를 죽였어)->GameMode는 해당*** 에 AddKill같은 함수 호출->해당*** 객체 내부에 몇명 죽였는지 카운트->플레이어가 죽인 몬스터 처치 수 달성(플레이어가 몬스터 처치 개수)->GameMode에 있는 PlayerController->성공했다
*/
