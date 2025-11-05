// JIH


#include "AbilitySystem/MWAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"

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
	if (Data.EvaluatedData.Attribute == GetCurrentHealthAttribute())
	{
		const float NewCurrentHealth = FMath::Clamp(GetCurrentHealth(), 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);
	}

	if (Data.EvaluatedData.Attribute == GetCurrentManaAttribute())
	{
		const float NewCurrentMana = FMath::Clamp(GetCurrentMana(), 0.f, GetMaxMana());

		SetCurrentMana(NewCurrentMana);
	}

	if (Data.EvaluatedData.Attribute == GetDamageTakenAttribute())
	{
		const float OldHealth = GetCurrentHealth();
		const float DamageDone = GetDamageTaken();

		const float NewCurrentHealth = FMath::Clamp(OldHealth - DamageDone, 0.f, GetMaxHealth());

		SetCurrentHealth(NewCurrentHealth);

		if (GetCurrentHealth() <= 0.f)
		{
			UMWBlueprintFunctionLibrary::AddGameplayTagIfNone(Data.Target.GetAvatarActor(), MWGameplayTags::Shared_Status_Death);
		}
	}
}
