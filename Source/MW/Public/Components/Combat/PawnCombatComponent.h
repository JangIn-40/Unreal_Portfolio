// JIH

#pragma once

#include "CoreMinimal.h"
#include "Components/PawnExtensionComponentBase.h"
#include "PawnCombatComponent.generated.h"

UENUM(BlueprintType)
enum class EToggleDamagetype : uint8
{
	LeftWeapon,
	RightWeapon
};

class UDataAsset_DamageDataBase;

/**
 * 
 */
UCLASS()
class MW_API UPawnCombatComponent : public UPawnExtensionComponentBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "MW | Combat")
	void ToggleWeaponCollision(bool bShouldEnable, EToggleDamagetype ToggleDamageType);

	UFUNCTION(BlueprintCallable, Category = "MW | Combat")
	float GetSpecialAbilityDamageAtLevel(FGameplayTag InTag, int32 InLevel);

	virtual void OnHitTargetActor(AActor* HitActor);
	virtual void OnWeaponPulledTargetActor(AActor* InteractedActor);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "CharacterData")
	UDataAsset_DamageDataBase* SpecialAbilityDamageData;

	TArray<AActor*> OverlappedActors;
};
