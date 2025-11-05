// JIH

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "MWAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class MW_API UMWAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UMWAttributeSet();

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, CurrentHealth);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, MaxHealth);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, CurrentMana);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, MaxMana);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, AttackPower);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, DefensePower);
	ATTRIBUTE_ACCESSORS_BASIC(UMWAttributeSet, DamageTaken);

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData CurrentHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Health")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, Category = "Mana")
	FGameplayAttributeData CurrentMana;

	UPROPERTY(BlueprintReadOnly, Category = "Mana")
	FGameplayAttributeData MaxMana;

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData AttackPower;

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DefensePower;

	UPROPERTY(BlueprintReadOnly, Category = "Damage")
	FGameplayAttributeData DamageTaken;
};
