// JIH

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/MWCharacterAnimInstance.h"
#include "MWHeroAnimInstance.generated.h"

class AMWHeroCharacter;

/**
 * 
 */
UCLASS()
class MW_API UMWHeroAnimInstance : public UMWCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

	FORCEINLINE bool GetIsInAir() { return bIsInAir; };

protected:
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | References")
	AMWHeroCharacter* OwningHeroCharacter;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	FRotator RotationLastTick = FRotator::ZeroRotator;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	float YawDelta;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	bool bIsInAir;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	FName NoneSlotName;

	bool bIsPlayingAnyMontageSection;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	FName StopRelaxingCurveName;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	bool bShouldEnterRelaxState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	float EnterRelaxStateThreshold = 5.f;

	float IdleElapsedTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	FName FullBodyCurveName;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	bool bIsFullBody;
};
