// JIH

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "GameplayTagContainer.h"
#include "Types/MWStructTypes.h"
#include "DataAsset_HeroStartUpData.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class MW_API UDataAsset_HeroStartUpData : public UDataAsset_StartUpDataBase
{
	GENERATED_BODY()

public:
	virtual void GiveToAbilitySystemComponent(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FMWHeroAbilitySet> HeroDefaultAbilitySets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StartUpData", meta = (TitleProperty = "InputTag"))
	TArray<FMWHeroSpecialAbilitySets> HeroSpecialAbilitySets;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "StartUpData")
	FMWHeroUIData HeroUIData;
};
