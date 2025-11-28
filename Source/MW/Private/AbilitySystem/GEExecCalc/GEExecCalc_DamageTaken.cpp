// JIH


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/MWAttributeSet.h"
#include "MWGameplayTags.h"

struct FMWDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken);

	FMWDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMWAttributeSet, AttackPower, Source, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMWAttributeSet, DefensePower, Target, false);
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMWAttributeSet, DamageTaken, Target, false);
	}
};

static const FMWDamageCapture& GetMWDamageCapture()
{
	static FMWDamageCapture MWDamageCapture;
	return MWDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	RelevantAttributesToCapture.Add(GetMWDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetMWDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetMWDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMWDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);

	int32 ComboCount = -1;
	float SpecialAbilityDamage = 0.f;

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(MWGameplayTags::Player_SetByCaller_ComboCount))
		{
			ComboCount = TagMagnitude.Value;
		}
		else if (TagMagnitude.Key.MatchesTagExact(MWGameplayTags::Shared_SetByCaller_SpecialAbilityDamage))
		{
			SpecialAbilityDamage = TagMagnitude.Value;
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetMWDamageCapture().DefensePowerDef, EvaluateParameters, TargetDefensePower);

	float FinalDamage = 0.f;

	if (ComboCount != -1)
	{
		const float DamageIncreasePercent = ComboCount * 0.05f + 1.f;

		SourceAttackPower *= DamageIncreasePercent;
	}

	FinalDamage = (SourceAttackPower + SpecialAbilityDamage) / TargetDefensePower;

	if (FinalDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetMWDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamage
			)
		);
	}
}
