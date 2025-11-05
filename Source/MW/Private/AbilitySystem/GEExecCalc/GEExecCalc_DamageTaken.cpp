// JIH


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/MWAttributeSet.h"

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
}
