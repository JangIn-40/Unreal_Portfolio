// JIH

#pragma once

#include "CoreMinimal.h"
#include "Types/MWEnumTypes.h"

/**
 * 
 */
class FMWCountDownAction : public FPendingLatentAction
{
public:
	FMWCountDownAction(float InTotalCountdownTime, float InUpdateInterval, float& InOutRemainingTime, EMWCountdownActionOutput& InCountdownOutput, const FLatentActionInfo& LatentInfo)
		: bNeedToCancel(false),
		TotalCountdownTime(InTotalCountdownTime),
		UpdateInterval(InUpdateInterval),
		OutRemainingTime(InOutRemainingTime),
		CountdownOutput(InCountdownOutput),
		ExecutionFunction(LatentInfo.ExecutionFunction),
		OutputLink(LatentInfo.Linkage),
		CallbackTarget(LatentInfo.CallbackTarget),
		ElapsedInterval(0.f),
		ElapsedTimeSinceStart(0.f)
	{}

	virtual void UpdateOperation(FLatentResponse& Response) override;

	void CancelAction();

private:
	bool bNeedToCancel;
	float TotalCountdownTime;
	float UpdateInterval;
	float& OutRemainingTime;
	EMWCountdownActionOutput& CountdownOutput;
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	float ElapsedInterval;
	float ElapsedTimeSinceStart;
};
