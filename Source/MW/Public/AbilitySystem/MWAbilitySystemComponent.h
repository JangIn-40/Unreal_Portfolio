// JIH

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "MWAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class MW_API UMWAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityInputPressed(const FGameplayTag& InInputTag);
	void OnAbilityInputReleased(const FGameplayTag& InInputTag);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Combat")
	bool bShouldProceedToNextCombo = false;
};
