// JIH

#pragma once

#include "CoreMinimal.h"
#include "AnimInstance/MWBaseAnimInstance.h"
#include "MWCharacterAnimInstance.generated.h"

class AMWBaseCharacter;
class UCharacterMovementComponent;

/**
 * 
 */
UCLASS()
class MW_API UMWCharacterAnimInstance : public UMWBaseAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY()
	AMWBaseCharacter* OwningCharacter;

	UPROPERTY()
	UCharacterMovementComponent* OwningMovementComponent;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	float GroundSpeed;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	bool bHasAcceleration;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "AnimData | LocmoitionData")
	float LocomotionDirection;
};
