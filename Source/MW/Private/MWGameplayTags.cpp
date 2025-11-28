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
	UE_DEFINE_GAMEPLAY_TAG(InputTag_SpecialAbility_Slam, "InputTag.SpecialAbility.Slam");

	/* Player Tags */
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Light, "Player.Ability.Attack.Light");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Attack_Recovery, "Player.Ability.Attack.Recovery");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_HitPause, "Player.Ability.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Jump, "Player.Ability.Jump");

	UE_DEFINE_GAMEPLAY_TAG(Player_SpecialAbility_ForcePush, "Player.SpecialAbility.ForcePush");
	UE_DEFINE_GAMEPLAY_TAG(Player_SpecialAbility_DoubleJump, "Player.SpecialAbility.DoubleJump");
	UE_DEFINE_GAMEPLAY_TAG(Player_SpecialAbility_Slam, "Player.SpecialAbility.Slam");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_SaveAttack, "Player.Event.SaveAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ResetAttack, "Player.Event.ResetAttack");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_HitPause, "Player.Event.HitPause");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindow_Start, "Player.Event.ComboWindow.Start");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_ComboWindow_End, "Player.Event.ComboWindow.End");

	UE_DEFINE_GAMEPLAY_TAG(Player_SetByCaller_ComboCount, "Player.SetByCaller.ComboCount");

	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsAttacking, "Player.Status.IsAttacking");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsFalling, "Player.Status.IsFalling");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_IsGrounded, "Player.Status.IsGrounded");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_OnDoubleJumping, "Player.Status.OnDoubleJumping");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_LowMana, "Player.Status.LowMana");
	UE_DEFINE_GAMEPLAY_TAG(Player_Status_ComboWindow_Start, "Player.Status.ComboWindow.Start");

	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialAbility_ForcePush, "Player.Cooldown.SpecialAbility.ForcePush");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialAbility_DoubleJump, "Player.Cooldown.SpecialAbility.DoubleJump");
	UE_DEFINE_GAMEPLAY_TAG(Player_Cooldown_SpecialAbility_Slam, "Player.Cooldown.SpecialAbility.Slam");

	/* Enemy Tags */
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Melee, "Enemy.Ability.Melee");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SpawnDamageZone, "Enemy.Ability.SpawnDamageZone");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_UpperCut, "Enemy.Ability.UpperCut");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_SmallCombo, "Enemy.Ability.SmallCombo");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_BigSmash, "Enemy.Ability.BigSmash");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Ability_Ranged, "Enemy.Ability.Ranged");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Event_SpawnDamageZone, "Enemy.Event.SpawnDamageZone");

	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_Strafing, "Enemy.Status.Strafing");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_UnderAttack, "Enemy.Status.UnderAttack");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_DamageZone_Activating, "Enemy.Status.DamageZone.Activating");
	UE_DEFINE_GAMEPLAY_TAG(Enemy_Status_AttackWarning, "Enemy.Status.AttackWarning");

	/* Shared Tags */
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_HitReact, "Shared.Ability.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Knockback, "Shared.Ability.Knockback");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Death, "Shared.Ability.Death");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Ability_Stun, "Shared.Ability.Stun");

	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_MeleeHit, "Shared.Event.MeleeHit");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_HitReact, "Shared.Event.HitReact");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Knockback, "Shared.Event.Knockback");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Death, "Shared.Event.Death");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_AOE, "Shared.Event.AOE");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_Stun, "Shared.Event.Stun");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Event_SpawnProjectile, "Shared.Event.SpawnProjectile");

	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_BaseDamage, "Shared.SetByCaller.BaseDamage");
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_SpecialAbilityDamage, "Shared.SetByCaller.SpecialAbilityDamage");
	UE_DEFINE_GAMEPLAY_TAG(Shared_SetByCaller_DotDamage, "Shared.SetByCaller.DotDamage");
		
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Front, "Shared.Status.HitReact.Front");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Back, "Shared.Status.HitReact.Back");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Right, "Shared.Status.HitReact.Right");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_HitReact_Left, "Shared.Status.HitReact.Left");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Death, "Shared.Status.Death");
	UE_DEFINE_GAMEPLAY_TAG(Shared_Status_Stun, "Shared.Status.Stun");

	/* GameData Tags */
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_SurvivalGameModeMap, "GameData.Level.SurvivalGameModeMap");
	UE_DEFINE_GAMEPLAY_TAG(GameData_Level_MainMenuMap, "GameData.Level.MainMenuMap");

	UE_DEFINE_GAMEPLAY_TAG(GameData_SaveGame_Slot_1, "GameData.SaveGame.Slot.1");
	UE_DEFINE_GAMEPLAY_TAG(GameData_SaveGame_Slot_2, "GameData.SaveGame.Slot.2");

	/* GameplayCue Tags */
	UE_DEFINE_GAMEPLAY_TAG(GameplayCue_FX_LevelUp, "GameplayCue.FX.LevelUp");
}
