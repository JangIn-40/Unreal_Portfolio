// JIH


#include "MWGameplayTags.h"

namespace MWGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack, "InputTag.LightAttack");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SpecialAbility_ForcePush, "InputTag.SpecialAbility.ForcePush");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light, "Player.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Recovery, "Player.Ability.Attack.Recovery");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_SpecialAbility_ForcePush, "Player.Ability.SpecialAbility.ForcePush");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SaveAttack, "Player.Event.SaveAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ResetAttack, "Player.Event.ResetAttack");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsAttacking, "Player.Status.IsAttacking");

	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialAbility_ForcePush, "Player.Cooldown.SpecialAbility.ForcePush");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
}
