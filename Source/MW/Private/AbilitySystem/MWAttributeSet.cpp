// JIH


#include "AbilitySystem/MWAttributeSet.h"

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

}
