// JIH


#include "MWGameplayTags.h"

namespace MWGameplayTags
{
	/* Input Tags */
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Move, "InputTag.Move");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Look, "InputTag.Look");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Jump, "InputTag.Jump");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_LightAttack, "InputTag.LightAttack");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light, "Player.Ability.Attack.Light");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SaveAttack, "Player.Event.SaveAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ResetAttack, "Player.Event.ResetAttack");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsAttacking, "Player.Status.IsAttacking");
}
