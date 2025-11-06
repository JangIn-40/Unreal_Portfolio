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
	UFUNCTION(BlueprintCallable, Category = "MW | Combat")
	float GetHeroSpecialAbilityDamageAtLevel(UPARAM(meta = (Categories = "Player.SpecialAbility")) FGameplayTag InTag, float InLevel) const;

	virtual void OnHitTargetActor(AActor* HitActor) override;
	virtual void OnWeaponPulledTargetActor(AActor* InteractedActor) override;
};
