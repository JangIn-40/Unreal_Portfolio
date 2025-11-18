// JIH


#include "AbilitySystem/Abilities/MWGameplayAbility.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"
#include "Characters/MWBaseCharacter.h"

void UMWGameplayAbility::OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec)
{
	Super::OnGiveAbility(ActorInfo, Spec);

	if (AbilityActivationPolicy == EMWAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo && !Spec.IsActive())
		{
			ActorInfo->AbilitySystemComponent->TryActivateAbility(Spec.Handle);
		}
	}
}

void UMWGameplayAbility::EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled)
{
	Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility, bWasCancelled);

	if (AbilityActivationPolicy == EMWAbilityActivationPolicy::OnGiven)
	{
		if (ActorInfo)
		{
			ActorInfo->AbilitySystemComponent->ClearAbility(Handle);
		}
	}
}

UPawnCombatComponent* UMWGameplayAbility::GetPawnCombatComponentFromActorInfo() const
{
	return GetAvatarActorFromActorInfo()->FindComponentByClass<UPawnCombatComponent>();
}

UMWAbilitySystemComponent* UMWGameplayAbility::GetMWAbilitySystemComponentFromActorInfo() const
{
	return Cast<UMWAbilitySystemComponent>(CurrentActorInfo->AbilitySystemComponent);
}

AMWBaseCharacter* UMWGameplayAbility::GetCharacterFromActorInfo()
{
	if (!CachedMWCharacter.IsValid())
	{
		CachedMWCharacter = Cast<AMWBaseCharacter>(CurrentActorInfo->AvatarActor);
	}

	return CachedMWCharacter.IsValid() ? CachedMWCharacter.Get() : nullptr;
}

FGameplayEffectSpecHandle UMWGameplayAbility::MakeGameplayEffectSpecHandle(TSubclassOf<UGameplayEffect> EffectClass)
{
	FGameplayEffectContextHandle ContextHandle = GetMWAbilitySystemComponentFromActorInfo()->MakeEffectContext();
	ContextHandle.SetAbility(this);
	ContextHandle.AddSourceObject(GetAvatarActorFromActorInfo());
	ContextHandle.AddInstigator(GetAvatarActorFromActorInfo(), GetAvatarActorFromActorInfo());

	return GetMWAbilitySystemComponentFromActorInfo()->MakeOutgoingSpec(EffectClass, GetAbilityLevel(), ContextHandle);
}

FActiveGameplayEffectHandle UMWGameplayAbility::NativeApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{
	UAbilitySystemComponent* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);

	checkf(TargetASC, TEXT("TargetActor에 ASC가 유효하지 않음"));

	return GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data, TargetASC);
}

FActiveGameplayEffectHandle UMWGameplayAbility::BP_ApplyEffectSpecHandleToTarget(AActor* TargetActor, const FGameplayEffectSpecHandle& InSpecHandle, EMWSuccessType& OutSuccessType)
{
	FActiveGameplayEffectHandle ActiveEffectHandle = NativeApplyEffectSpecHandleToTarget(TargetActor, InSpecHandle);

	OutSuccessType = ActiveEffectHandle.WasSuccessfullyApplied() ? EMWSuccessType::Successful : EMWSuccessType::Failed;

	return ActiveEffectHandle;
}

void UMWGameplayAbility::ApplyEffectSpecHandleToHitResult(const FGameplayEffectSpecHandle& InSpecHandle, const TArray<FHitResult> InHitResults)
{
	if (InHitResults.IsEmpty())
	{
		return;
	}

	APawn* OwningPawn = CastChecked<APawn>(GetAvatarActorFromActorInfo());

	for (const FHitResult& HitResult : InHitResults)
	{
		if (APawn* HitPawn = Cast<APawn>(HitResult.GetActor()))
		{
			if (UMWBlueprintFunctionLibrary::IsTargetPawnHostile(OwningPawn, HitPawn))
			{
				NativeApplyEffectSpecHandleToTarget(HitPawn, InSpecHandle);

				FGameplayEventData Data;
				Data.Instigator = OwningPawn;
				Data.Target = HitPawn;

				UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(HitPawn, MWGameplayTags::Shared_Event_HitReact, Data);
			}
		}
	}
}
