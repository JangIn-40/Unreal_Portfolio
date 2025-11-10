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

UENUM(BlueprintType)
enum class EMWSuccessType : uint8
{
	Successful,
	Failed
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

	FGameplayEffectSpecHandle MakeGameplayEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass);

	FActiveGameplayEffectHandle NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "MW | Ability", meta = (DisplayName = "Apply Gameplay Effect Spec Handle To Target Actor", ExpandEnumAsExecs = "OutSuccessType"))
	FActiveGameplayEffectHandle BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EMWSuccessType& OutSuccessType);

	UFUNCTION(BlueprintCallable, Category = "MW | Ability")
	void ApplyEffectSpecHandleToHitResult(const FGameplayEffectSpecHandle& InSpecHandle, const TArray<FHitResult> InHitResults);
};
