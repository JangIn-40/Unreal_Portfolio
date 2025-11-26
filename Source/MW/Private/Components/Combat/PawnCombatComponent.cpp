// JIH


#include "Components/Combat/PawnCombatComponent.h"
#include "Characters/MWBaseCharacter.h"
#include "Components/BoxComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MWGameplayTags.h"
#include "Particles/ParticleSystem.h"
#include "Kismet/GameplayStatics.h"

#include "MWDebugHelper.h"

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

void UPawnCombatComponent::OnHitTargetActor(AActor* HitActor, UPrimitiveComponent* OverlappedComponent)
{
	if (OverlappedActors.Contains(HitActor))
	{
		return;
	}

	SpawnMeleeHitImpactFXSound(HitActor, OverlappedComponent);

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

void UPawnCombatComponent::SpawnMeleeHitImpactFXSound(AActor* HitActor, UPrimitiveComponent* OverlappedComponent)
{
	if (!MeleeHitImpactFX && !MeleeHitSound)
	{
		return;
	}

	FVector Start = OverlappedComponent->GetComponentLocation();

	FVector End = (HitActor->GetActorLocation() - Start) + HitActor->GetActorLocation();

	TArray<FHitResult> HitResults;

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn));

	UKismetSystemLibrary::LineTraceMultiForObjects(
		GetOwner(),
		Start,
		End,
		ObjectTypes,
		false,
		OverlappedActors,
		bDebugLineTrace ? EDrawDebugTrace::Persistent : EDrawDebugTrace::None,
		HitResults,
		true
	);
		
	for (FHitResult& HitResult : HitResults)
	{
		if (HitActor == HitResult.GetActor())
		{
			if (MeleeHitImpactFX)
			{
				UGameplayStatics::SpawnEmitterAtLocation(this, MeleeHitImpactFX, HitResult.ImpactPoint, FRotator::ZeroRotator, true);
			}			

			if (MeleeHitSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, MeleeHitSound, HitResult.ImpactPoint);
			}
		}
	}
	
}
