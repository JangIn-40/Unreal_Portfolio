// JIH


#include "DataAssets/StartUpData/DataAsset_EnemyStartUpData.h"
#include "AbilitySystem/Abilities/MWEnemyGameplayAbility.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"

void UDataAsset_EnemyStartUpData::GiveToAbilitySystemComponent(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	if (!EnemyCombatAbilities.IsEmpty())
	{
		for (const TSubclassOf<UMWEnemyGameplayAbility>& AbilityClass : EnemyCombatAbilities)
		{
			if (!AbilityClass) continue;

			FGameplayAbilitySpec Spec(AbilityClass);
			Spec.SourceObject = InASCToGive->GetAvatarActor();
			Spec.Level = ApplyLevel;

			InASCToGive->GiveAbility(Spec);
		}
	}
}
