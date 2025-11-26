// JIH


#include "Components/Combat/HeroCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MWGameplayTags.h"

void UHeroCombatComponent::OnHitTargetActor(AActor* HitActor, UPrimitiveComponent* OverlappedComponent)
{
    Super::OnHitTargetActor(HitActor, OverlappedComponent);

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
