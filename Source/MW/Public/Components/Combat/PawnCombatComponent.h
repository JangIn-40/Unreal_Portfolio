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
class UParticleSystem;
class UPrimitiveComponent;
class USoundBase;

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

	virtual void OnHitTargetActor(AActor* HitActor, UPrimitiveComponent* OverlappedComponent);
	virtual void OnWeaponPulledTargetActor(AActor* InteractedActor);

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MW | Combat")
	UParticleSystem* MeleeHitImpactFX;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MW | Combat")
	bool bDebugLineTrace = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "MW | Combat")
	USoundBase* MeleeHitSound;

protected:
	TArray<AActor*> OverlappedActors;

private:
	void SpawnMeleeHitImpactFXSound(AActor* HitActor, UPrimitiveComponent* OverlappedComponent);
};
