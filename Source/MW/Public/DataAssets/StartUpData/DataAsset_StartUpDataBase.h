// JIH

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "DataAsset_StartUpDataBase.generated.h"

class UMWAbilitySystemComponent;
class UMWGameplayAbility;

/**
 * 
 */
UCLASS()
class MW_API UDataAsset_StartUpDataBase : public UDataAsset
{
	GENERATED_BODY()
	
public:
	virtual void GiveToAbilitySystemComponent(UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UMWGameplayAbility>> ActivateOnGivenAbilities;

	UPROPERTY(EditDefaultsOnly, Category = "StartUpData")
	TArray<TSubclassOf<UMWGameplayAbility>> ReactiveAbilities;

	void GrantAbilities(const TArray<TSubclassOf<UMWGameplayAbility>>& InAbilitiesToGive, UMWAbilitySystemComponent* InASCToGive, int32 ApplyLevel);
};
