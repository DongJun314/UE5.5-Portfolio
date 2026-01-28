// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTService_Detect.h"
#include "IVAI.h"
#include "AIController.h"
#include "Interface/IVCharacterAIInterface.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Physics/IVCollision.h"
#include "Engine/OverlapResult.h"
#include "DrawDebugHelpers.h"
#include "Player/IVPlayerController.h"
#include "UI/IVHUDWidget.h"

UBTService_Detect::UBTService_Detect()
{
	NodeName = TEXT("Detect");
	Interval = 1.0f;
}

void UBTService_Detect::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (nullptr == ControllingPawn)
	{
		return;
	}

	FVector Center = ControllingPawn->GetActorLocation();
	UWorld* World = ControllingPawn->GetWorld();
	if (nullptr == World)
	{
		return;
	}

	IIVCharacterAIInterface* AIPawn = Cast<IIVCharacterAIInterface>(ControllingPawn);
	if (nullptr == AIPawn)
	{
		return;
	}

	float DetectRadius = AIPawn->GetAIDetectRange();

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(SCENE_QUERY_STAT(Detect), false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		CCHANNEL_IVACTION,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			APawn* Pawn = Cast<APawn>(OverlapResult.GetActor());
			if (Pawn && Pawn->GetController()->IsPlayerController())
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(BBKEY_TARGET, Pawn);
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
				DrawDebugPoint(World, Pawn->GetActorLocation(), 10.0f, FColor::Red, false, 0.2f);
				DrawDebugLine(World, ControllingPawn->GetActorLocation(), Pawn->GetActorLocation(), FColor::Red, false, 0.27f);
				
				UIVHUDWidget* IVHUDWidget = Cast<AIVPlayerController>(Pawn->GetController())->GetHUDWidget();
				if (IVHUDWidget)
				{
					IVHUDWidget->ShowAIHpHUD(AIPawn);
					AIPawn->ShowWidgetComp(false);
				}
				return;
			}
		}
	}
	
	OwnerComp.GetBlackboardComponent()->SetValueAsObject(BBKEY_TARGET, nullptr);
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Green, false, 0.2f);
}
