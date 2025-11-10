// JIH

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "GameplayTagContainer.h"
#include "AN_PlayParticleEffectWithTag.generated.h"

/**
 * 
 */
UCLASS(const, hidecategories = Object, collapsecategories, meta = (DisplayName = "Play Particle Effect When Actor Have Tag"))
class MW_API UAN_PlayParticleEffectWithTag : public UAnimNotify_PlayParticleEffect
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = "AnimNotify")
	FGameplayTag TagToCheck;

protected:
	virtual UParticleSystemComponent* SpawnParticleSystem(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;
};
