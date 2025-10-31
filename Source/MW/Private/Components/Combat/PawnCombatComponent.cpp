// JIH


#include "Components/Combat/PawnCombatComponent.h"
#include "Characters/MWBaseCharacter.h"
#include "Components/BoxComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MWGameplayTags.h"

void UPawnCombatComponent::ToggleWeaponCollision(bool bShouldEnable, EToggleDamagetype ToggleDamageType)
{
	AMWBaseCharacter* OwningCharacter = GetOwningPawn<AMWBaseCharacter>();

	check(OwningCharacter);

	UBoxComponent* LeftWeaponCollision = OwningCharacter->GetLeftWeaponCollisioinBox();
	UBoxComponent* RightWeaponCollision = OwningCharacter->GetRightWeaponCollisioinBox();

	check(LeftWeaponCollision && RightWeaponCollision);

	switch (ToggleDamageType)
	{
	case EToggleDamagetype::LeftWeapon:
		LeftWeaponCollision->SetCollisionEnabled(bShouldEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
		break;

	case EToggleDamagetype::RightWeapon:
		RightWeaponCollision->SetCollisionEnabled(bShouldEnable ? ECollisionEnabled::QueryOnly : ECollisionEnabled::NoCollision);
		break;

	default:
		break;
	}

	if (!bShouldEnable)
	{
		OverlappedActors.Empty();
	}
}

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	OverlappedActors.AddUnique(HitActor);

	FGameplayEventData Data;
	Data.Instigator = GetOwningPawn();
	Data.Target = HitActor;

	UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
		GetOwningPawn(),
		MWGameplayTags::Shared_Event_MeleeHit,
		Data
	);
}

void UPawnCombatComponent::OnWeaponPulledTargetActor(AActor* InteractedActor)
{
}
