// JIH

#pragma once

#include "CoreMinimal.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "HeroCombatComponent.generated.h"

/**
 * 
 */
UCLASS()
class MW_API UHeroCombatComponent : public UPawnCombatComponent
{
	GENERATED_BODY()
	
public:
	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledTargetActor(AActor* InteractedActor) override;
};
