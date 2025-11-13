// JIH


#include "AI/BTService_GetGroundLocToTarget.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetSystemLibrary.h"

UBTService_GetGroundLocToTarget::UBTService_GetGroundLocToTarget()
{
	NodeName = TEXT("Native Get Ground Location To Target");

	INIT_SERVICE_NODE_NOTIFY_FLAGS();

	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(ThisClass, BlackboardKey), AActor::StaticClass());
}

FString UBTService_GetGroundLocToTarget::GetStaticDescription() const
{
	const FString KeyDescription = BlackboardKey.SelectedKeyName.ToString();

	return FString::Printf(TEXT("Get Ground location to %s Key %s"), *KeyDescription, *GetStaticServiceDescription());
}

void UBTService_GetGroundLocToTarget::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	UObject* ActorObject = OwnerComp.GetBlackboardComponent()->GetValueAsObject(FName(BlackboardKey.SelectedKeyName));
	AActor* TargetActor = Cast<AActor>(ActorObject);

	if (TargetActor)
	{
		FVector Start = TargetActor->GetActorLocation() + FVector(0.f, 0.f, 50.f);
		FVector End = TargetActor->GetActorLocation() - FVector(0.f, 0.f, LineTraceDistance);

		FHitResult HitResult;

		TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldStatic));
		ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_WorldDynamic));

		bool bHitGround = UKismetSystemLibrary::LineTraceSingleForObjects(
			TargetActor, 
			Start, 
			End, 
			ObjectTypes, 
			false, 
			TArray<AActor*>(), 
			bDebugLineTrace ? EDrawDebugTrace::ForOneFrame : EDrawDebugTrace::None,
			HitResult,
			false
		);

		if (bHitGround)
		{
			OwnerComp.GetBlackboardComponent()->SetValueAsVector(OutGroundLoc.SelectedKeyName, HitResult.Location);
		}
	}
}
