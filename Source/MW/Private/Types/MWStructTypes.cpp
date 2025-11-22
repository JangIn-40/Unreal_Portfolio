// JIH


#include "Types/MWStructTypes.h"
#include "AbilitySystem/Abilities/MWGameplayAbility.h"

bool FMWHeroAbilitySet::IsValid() const
{
	return AbilityToGrant && InputTag.IsValid();
}
