// JIH


#include "AbilitySystem/Abilities/MWEnemyGameplayAbility.h"
#include "Characters/MWEnemyCharacter.h"
#include "MWGameplayTags.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"

AMWEnemyCharacter* UMWEnemyGameplayAbility::GetEnemyCharacterFromActorInfo()
{
	if (!CachedMWEnemyCharacter.IsValid())
	{
		CachedMWEnemyCharacter = Cast<AMWEnemyCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedMWEnemyCharacter.IsValid() ? CachedMWEnemyCharacter.Get() : nullptr;
}

UEnemyCombatComponent* UMWEnemyGameplayAbility::GetEnemyCombatComponentFromActorInfo()
{
	return GetEnemyCharacterFromActorInfo()->GetEnemyCombatComponent();
}

FGameplayEffectSpecHandle UMWEnemyGameplayAbility::MakeEnemyBaseDamageSpecHandle(TSubclassOf<UGameplayEffect> EffectClass)
{
	check(EffectClass);

	FGameplayEffectSpecHandle SpecHandle = MakeGameplayEffectSpecHandle(EffectClass);
	
	SpecHandle.Data->SetSetByCallerMagnitude(
		FGameplayTag(),
		0
	);

	return SpecHandle;
}
