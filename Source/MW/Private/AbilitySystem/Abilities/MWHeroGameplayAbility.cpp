// JIH


#include "AbilitySystem/Abilities/MWHeroGameplayAbility.h"
#include "Characters/MWHeroCharacter.h"
#include "Controllers/MWHeroController.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "MWGameplayTags.h"

AMWHeroCharacter* UMWHeroGameplayAbility::GetHeroCharacterFromActorInfo()
{
	if (!CachedMWHeroCharacter.IsValid())
	{
		CachedMWHeroCharacter = Cast<AMWHeroCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedMWHeroCharacter.IsValid() ? CachedMWHeroCharacter.Get() : nullptr;
}

AMWHeroController* UMWHeroGameplayAbility::GetHeroControllerFromActorInfo()
{
	if (!CachedMWHeroController.IsValid())
	{
		CachedMWHeroController = Cast<AMWHeroController>(CurrentActorInfo->PlayerController);
	}

	return CachedMWHeroController.IsValid() ? CachedMWHeroController.Get() : nullptr;
}

UHeroCombatComponent* UMWHeroGameplayAbility::GetHeroCombatComponent()
{
	return GetHeroCharacterFromActorInfo()->GetHeroCombatComponent();
}

UCharacterMovementComponent* UMWHeroGameplayAbility::GetHeroMovementComponent()
{
	return GetHeroCharacterFromActorInfo()->GetCharacterMovement();
}

FGameplayEffectSpecHandle UMWHeroGameplayAbility::MakeHeroBaseDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, int32 InUsedComboCount)
{
	check(EffectClass);

	FGameplayEffectSpecHandle EffectSpecHandle = MakeGameplayEffectSpecHandle(EffectClass);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		MWGameplayTags::Player_SetByCaller_ComboCount,
		InUsedComboCount
	);

	return EffectSpecHandle;
}

FGameplayEffectSpecHandle UMWHeroGameplayAbility::MakeHeroSpecialAbilityDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass, const FScalableFloat& InSpecialAbilityDamage)
{
	check(EffectClass);

	FGameplayEffectSpecHandle EffectSpecHandle = MakeGameplayEffectSpecHandle(EffectClass);

	EffectSpecHandle.Data->SetSetByCallerMagnitude(
		MWGameplayTags::Shared_SetByCaller_SpecialAbilityDamage,
		InSpecialAbilityDamage.GetValueAtLevel(GetAbilityLevel())
	);

	return EffectSpecHandle;
}
