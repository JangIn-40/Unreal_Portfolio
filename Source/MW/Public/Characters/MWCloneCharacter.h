// JIH

#pragma once

#include "CoreMinimal.h"
#include "Characters/MWBaseCharacter.h"
#include "MWCloneCharacter.generated.h"

class UPawnCombatComponent;

/**
 * 
 */
UCLASS()
class MW_API AMWCloneCharacter : public AMWBaseCharacter
{
	GENERATED_BODY()
	
public:
	AMWCloneCharacter();

	//~ Begin IPawnCombatInterface Interface.
	virtual UPawnCombatComponent* GetPawnCombatComponent() const override;
	//~ End IPawnCombatInterface Interface.

protected:
	virtual void OnWeaponCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void BeginPlay() override;

	//~ Begin APawn Interface.
	virtual void PossessedBy(AController* NewController) override;
	//~ End APawn Interface.

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true"))
	UPawnCombatComponent* PawnCombatComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Combat", meta = (AllowPrivateAccess = "true", ExposeOnSpawn = "true"))
	int32 AbilityLevel;

};
