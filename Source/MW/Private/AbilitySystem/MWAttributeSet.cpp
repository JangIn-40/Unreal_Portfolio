// JIH


#include "AbilitySystem/MWAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "Interfaces/PawnUIInterface.h"
#include "Components/UI/HeroUIComponent.h"

#include "MWDebugHelper.h"

UMWAttributeSet::UMWAttributeSet()
{
	InitCurrentHealth(1.f);
	InitMaxHealth(1.f);
	InitCurrentMana(1.f);
	InitMaxMana(1.f);
	InitAttackPower(1.f);
	InitDefensePower(1.f);
}

void UMWAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (!CachedPawnUIInterface.IsValid())
	{
		CachedPawnUIInterface = TWeakInterfacePtr<IPawnUIInterface>(Data.Target.GetAvatarActor());
	}

	checkf(CachedPawnUIInterface.IsValid(), TEXT("%s didn't implement IPawnUIInterface"), *Data.Target.GetAvatarActor()->GetActorNameOrLabel());

	UPawnUIComponent* PawnUIInterface = CachedPawnUIInterface->GetPawnUIComponent();

	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		PawnUIInterface->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());
	}

	if (Data.EvaluatedData.Attribute == GetCurrentManaAttribute())
	{
		const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.f, GetMaxMana());

		SetCurrentMana(NewCurrentMana);

		if (UHeroUIComponent* HeroUIComponent = CachedPawnUIInterface->GetHeroUIComponent())
		{
			HeroUIComponent->OnCurrentManaChanged.Broadcast(GetCurrentMana() / GetMaxMana());
		}
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		PawnUIInterface->OnCurrentHealthChanged.Broadcast(GetCurrentHealth() / GetMaxHealth());

		Debug::Print(TEXT("Final Damage is "), DamageDone);
		Debug::Print(TEXT("CurrentHealth is "), NewCurrentHealth);

		if (GetCurrentHealth() <= 0.f)
		{
			const FGameplayEffectContextHandle& ContextHandle = Data.EffectSpec.GetEffectContext();
			AActor* Instigator = ContextHandle.GetInstigator();

			FGameplayEventData EventData;
			EventData.Instigator = Instigator;
			EventData.Target = Data.Target.GetAvatarActor();
			
			UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(
				Data.Target.GetAvatarActor(),
				MWGameplayTags::Shared_Event_Death,
				EventData
			);

			UMWBlueprintFunctionLibrary::AddGameplayTagIfNone(Data.Target.GetAvatarActor(), MWGameplayTags::Shared_Status_Death);
		}
	}
}
