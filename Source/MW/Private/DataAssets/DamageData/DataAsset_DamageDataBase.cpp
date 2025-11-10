// JIH


#include "DataAssets/DamageData/DataAsset_DamageDataBase.h"

float UDataAsset_DamageDataBase::GetSpecialAbilityDamageAtLevel(FGameplayTag InTag, int32 InLevel)
{
	check(InTag.IsValid());

	for (const FMWDamageData& DamageData : DamageDatas)
	{
		if (DamageData.PlayerSpecialAbilityTag == InTag)
		{
			return DamageData.SpecialAbilityDamage.GetValueAtLevel(InLevel);
		}
	}

	ensureMsgf(false, TEXT("Damage Data 설정 안함"));

	return 0.f;
}
