// JIH

#pragma once

#include "NativeGameplayTags.h"

namespace MWGameplayTags
{
	/* Input Tags */
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Move);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Look);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_Jump);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_LightAttack);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(InputTag_SpecialAbility_ForcePush);

	/* Player Tags */
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Light);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_Attack_Recovery);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Ability_SpecialAbility_ForcePush);

	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_SaveAttack);
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Event_ResetAttack);

	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Status_IsAttacking);

	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Player_Cooldown_SpecialAbility_ForcePush);

	/* Shared Tags */
	MW_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Shared_Event_MeleeHit);
	
}

