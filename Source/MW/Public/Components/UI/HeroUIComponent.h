// JIH

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "GameplayTagContainer.h"
#include "HeroUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroPortraitIconUpdateDelegate, UTexture2D*, HeroPortraitIcon);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeroAbilityIconUpdateDelegate, FGameplayTag, AbilityInputTag, UMaterialInterface*, HeroAbilityIconMaterial);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAbilityCooldownBeginDelegate, FGameplayTag, AbilityInputTag, float, TotalCooldownTime, float, RemainingCooldownTime);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityActivatableDelegate, FGameplayTag, AbilityInputTag);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAbilityDisableDelegate, FGameplayTag, AbilityInputTag);

/**
 * 
 */
UCLASS()
class MW_API UHeroUIComponent : public UPawnUIComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPercentChangedDelegate OnCurrentManaChanged;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnHeroPortraitIconUpdateDelegate OnHeroPortraitIconUpdated;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnHeroAbilityIconUpdateDelegate OnHeroAbilityIconUpdated;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnAbilityCooldownBeginDelegate OnAbilityCooldownBegin;
	
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnAbilityActivatableDelegate OnAbilityActivatable;

	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnAbilityActivatableDelegate OnAbilityDisable;
};
