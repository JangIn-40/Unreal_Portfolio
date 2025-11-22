// JIH

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MWGameplayAbility.h"
#include "MWHeroGameplayAbility.generated.h"

class AMWHeroCharacter;
class AMWHeroController;
class UHeroCombatComponent;

/**
 * 
 */
UCLASS()
class MW_API UMWHeroGameplayAbility : public UMWGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	AMWHeroCharacter* GetHeroCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	AMWHeroController* GetHeroControllerFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	UHeroCombatComponent* GetHeroCombatComponent();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	UCharacterMovementComponent* GetHeroMovementComponent();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	FGameplayEffectSpecHandle MakeHeroBaseDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, int32 InUsedComboCount);

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	FGameplayEffectSpecHandle MakeHeroSpecialAbilityDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& SpecialAbilityDamage);

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	bool GetAbilityRemainingCooldownByTag(FGameplayTag InCooldownTag, float& TotalCooldownTime, float& RemainingCooldownTime);

private:
	TWeakObjectPtr<AMWHeroCharacter> CachedMWHeroCharacter;
	TWeakObjectPtr<AMWHeroController> CachedMWHeroController;
};
