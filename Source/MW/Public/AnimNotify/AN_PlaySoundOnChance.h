// JIH

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlaySound.h"
#include "AN_PlaySoundOnChance.generated.h"

/**
 * 
 */
UCLASS(const, hidecategories = Object, collapsecategories, meta = (DisplayName = "AN_Play Sound On Chance"))
class MW_API UAN_PlaySoundOnChance : public UAnimNotify_PlaySound
{
	GENERATED_BODY()

public:
	virtual void Notify(class USkeletalMeshComponent* MeshComp, class UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

	
protected:
	UPROPERTY(EditAnywhere, Category = "MW | Sound", meta = (ClampMin = "0", ClampMax = "1"))
	float SuccessChanceMin;

	UPROPERTY(EditAnywhere, Category = "MW | Sound", meta = (ClampMin = "0", ClampMax = "1"))
	float SuccessChanceMax;
};
