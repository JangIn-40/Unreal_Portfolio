// JIH


#include "AbilitySystem/Abilities/MWHeroGameplayAbility.h"
#include "Characters/MWHeroCharacter.h"
#include "Controllers/MWHeroController.h"

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
