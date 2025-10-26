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

private:
	TWeakObjectPtr<AMWHeroCharacter> CachedMWHeroCharacter;
	TWeakObjectPtr<AMWHeroController> CachedMWHeroController;
};
