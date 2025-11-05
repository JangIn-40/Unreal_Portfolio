// JIH


#include "DataAssets/DamageData/DataAsset_DamageDataBase.h"

float UDataAsset_DamageDataBase::GetSpecialAbilityDamageAtLevel(FGameplayTag InTag, int32 InLevel)
{
	for (const FMWDamageData& DamageData : DamageDatas)
	{
		if (DamageData.InputTag == InTag)
		{
			return DamageData.SpecialAbilityDamage.GetValueAtLevel(InLevel);
		}
	}

	return 0.f;
}
