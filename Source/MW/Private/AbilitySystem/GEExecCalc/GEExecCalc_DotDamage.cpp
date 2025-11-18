// JIH


#include "AbilitySystem/GEExecCalc/GEExecCalc_DotDamage.h"
#include "AbilitySystem/MWAttributeSet.h"
#include "MWGameplayTags.h"

struct FMWDotDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken);

	FMWDotDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UMWAttributeSet, DamageTaken, Target, false);
	}
};

static const FMWDotDamageCapture& GetMWDotDamageCapture()
{
	static FMWDotDamageCapture MWDamageCapture;
	return MWDamageCapture;
}

UGEExecCalc_DotDamage::UGEExecCalc_DotDamage()
{
	RelevantAttributesToCapture.AddUnique(GetMWDotDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DotDamage::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	float DotDamage = 0.f;

	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(MWGameplayTags::Shared_SetByCaller_DotDamage))
		{
			DotDamage = TagMagnitude.Value;
		}
	}

	if (DotDamage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetMWDotDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				DotDamage
			)
		);
	}
}
