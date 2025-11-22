// JIH

#pragma once

#include "CoreMinimal.h"
#include "Components/UI/PawnUIComponent.h"
#include "GameplayTagContainer.h"
#include "HeroUIComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeroPortraitIconUpdateDelegate, TSoftObjectPtr<UTexture2D>, SoftHeroPortraitIcon);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHeroAbilityIconUpdateDelegate, FGameplayTag, AbilityInputTag, TSoftObjectPtr<UMaterialInterface>, SoftHeroAbilityIconMaterial);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAbilityCooldownBeginDelegate, FGameplayTag, AbilityInputTag, float, TotalCooldownTime, float, RemainingCooldownTime);

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
	
};
