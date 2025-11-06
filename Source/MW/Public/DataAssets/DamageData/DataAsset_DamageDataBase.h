// JIH

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ScalableFloat.h"
#include "GameplayTagContainer.h"
#include "DataAsset_DamageDataBase.generated.h"

USTRUCT(BlueprintType)
struct FMWDamageData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Player.SpecialAbility"))
	FGameplayTag PlayerSpecialAbilityTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FScalableFloat SpecialAbilityDamage;
};

/**
 * 
 */
UCLASS()
class MW_API UDataAsset_DamageDataBase : public UDataAsset
{
	GENERATED_BODY()

public:
	virtual float GetSpecialAbilityDamageAtLevel(FGameplayTag InTag, int32 InLevel);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (TitleProperty = "Player.SpecialAbility"))
	TArray<FMWDamageData> DamageDatas;
};
