// JIH

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_GetGroundLocToTarget.generated.h"

/**
 * 
 */
UCLASS()
class MW_API UBTService_GetGroundLocToTarget : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
	UBTService_GetGroundLocToTarget();

	//~ Begin UBTNode Interface
	virtual FString GetStaticDescription() const override;
	//~ End UBTNode Interface

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	struct FBlackboardKeySelector OutGroundLoc;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	float LineTraceDistance;

	UPROPERTY(EditAnywhere, Category = "Blackboard")
	bool bDebugLineTrace = false;
};
