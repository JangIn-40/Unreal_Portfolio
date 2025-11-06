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
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Player_SpecialAbility_ForcePush, "Player.SpecialAbility.ForcePush");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SaveAttack, "Player.Event.SaveAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ResetAttack, "Player.Event.ResetAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause, "Player.Event.HitPause");

	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_ComboCount, "Player.SetByCaller.ComboCount");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsAttacking, "Player.Status.IsAttacking");

	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialAbility_ForcePush, "Player.Cooldown.SpecialAbility.ForcePush");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Knockback, "Shared.Ability.Knockback");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Knockback, "Shared.Event.Knockback");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Death, "Shared.Event.Death");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_SpecialAbilityDamage, "Shared.SetByCaller.SpecialAbilityDamage");
		
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Front, "Shared.Status.HitReact.Front");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Back, "Shared.Status.HitReact.Back");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Right, "Shared.Status.HitReact.Right");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Left, "Shared.Status.HitReact.Left");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death, "Shared.Status.Death");
}
