// JIH


#include "DataAssets/StartUpData/DataAsset_HeroStartUpData.h"
#include "AbilitySystem/Abilities/MWGameplayAbility.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"


void UDataAsset_HeroStartUpData::GiveToAbilitySystemComponent(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel)
{
	Super::GiveToAbilitySystemComponent(InASCToGive, ApplyLevel);

	for (const FMWHeroAbilitySet& AbilitySet : HeroDefaultAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec Spec(AbilitySet.AbilityToGrant);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		Spec.Level = ApplyLevel;
		Spec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(Spec);
	}

	for (const FMWHeroAbilitySet& AbilitySet : HeroSpecialAbilitySets)
	{
		if (!AbilitySet.IsValid()) continue;

		FGameplayAbilitySpec Spec(AbilitySet.AbilityToGrant);
		Spec.SourceObject = InASCToGive->GetAvatarActor();
		Spec.Level = ApplyLevel;
		Spec.DynamicAbilityTags.AddTag(AbilitySet.InputTag);

		InASCToGive->GiveAbility(Spec);
	}
}