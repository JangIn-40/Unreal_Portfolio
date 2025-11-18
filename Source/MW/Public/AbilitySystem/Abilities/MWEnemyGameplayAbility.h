// JIH

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Abilities/MWGameplayAbility.h"
#include "MWEnemyGameplayAbility.generated.h"

class AMWEnemyCharacter;
class UEnemyCombatComponent;
/**
 * 
 */
UCLASS()
class MW_API UMWEnemyGameplayAbility : public UMWGameplayAbility
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	AMWEnemyCharacter* GetEnemyCharacterFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	UEnemyCombatComponent* GetEnemyCombatComponentFromActorInfo();

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	FGameplayEffectSpecHandle MakeEnemyBaseDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass);

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	FGameplayEffectSpecHandle MakeEnemySpecialDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, FGameplayTag InSetByCallerTag, const FScalableFloat& InDamageScalableFloat);


private:
	TWeakObjectPtr<AMWEnemyCharacter> CachedMWEnemyCharacter;
};
