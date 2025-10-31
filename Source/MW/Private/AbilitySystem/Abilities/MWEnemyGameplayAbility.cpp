// JIH


#include "AbilitySystem/Abilities/MWEnemyGameplayAbility.h"
#include "Characters/MWEnemyCharacter.h"

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
