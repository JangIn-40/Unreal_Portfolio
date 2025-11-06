// JIH


#include "Components/Combat/HeroCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MWGameplayTags.h"
#include "DataAssets/DamageData/DataAsset_DamageDataBase.h"

float UHeroCombatComponent::GetHeroSpecialAbilityDamageAtLevel(FGameplayTag InTag, float InLevel) const
{
	checkf(SpecialAbilityDamageData, TEXT("SpecialAbilityDamageData 할당하지 않음"));
	check(InTag.IsValid());

	return SpecialAbilityDamageData->GetSpecialAbilityDamageAtLevel(InTag, InLevel);
}

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor)
{
    Super::OnHitTargetActor(HitActor);

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		MWGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}

void UHeroCombatComponent::OnWeaponPulledTargetActor(AActor* InteractedActor)
{
	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		MWGameplayTags::Player_Event_HitPause,
		FGameplayEventData()
	);
}
