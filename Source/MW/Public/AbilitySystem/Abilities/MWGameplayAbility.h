// JIH

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "MWGameplayAbility.generated.h"

class UMWAbilitySystemComponent;
class UPawnCombatComponent;

UENUM(BlueprintType)
enum class EMWAbilityActivationPolicy : uint8
{
	OnTriggered,
	OnGiven
};

/**
 * 
 */
UCLASS()
class MW_API UMWGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
protected:
	//~ Begin UGameplayAbility Interface.
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) override;
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;
	//~ End UGameplayAbility Interface

	UPROPERTY(EditDefaultsOnly, Category = "MWAbility")
	EMWAbilityActivationPolicy AbilityActivationPolicy = EMWAbilityActivationPolicy::OnTriggered;

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	UPawnCombatComponent* GetPawnCombatComponentFromActorInfo() const;

	UFUNCTION(BlueprintPure, Category = "MW | Ability")
	UMWAbilitySystemComponent* GetMWAbilitySystemComponentFromActorInfo() const;

};
