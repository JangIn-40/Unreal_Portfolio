// JIH


#include "AnimInstance/Hero/MWHeroAnimInstance.h"
#include "Characters/MWHeroCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"


void UMWHeroAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwningCharacter)
	{
		OwningHeroCharacter = Cast<AMWHeroCharacter>(OwningCharacter);
	}
}

void UMWHeroAnimInstance::NativeThreadSafeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeThreadSafeUpdateAnimation(DeltaSeconds);

	if (!OwningHeroCharacter || !OwningMovementComponent)
	{
		return;
	}

	FRotator RawRotationDelta = UKismetMathLibrary::NormalizedDeltaRotator(OwningHeroCharacter->GetActorRotation(), RotationLastTick);

	float RawYawDelta = RawRotationDelta.Yaw;

	float ScaledTargetYawDelta = (RawYawDelta / DeltaSeconds) / 7.f;

	YawDelta = UKismetMathLibrary::FInterpTo(YawDelta, ScaledTargetYawDelta, DeltaSeconds, 6.f);

	RotationLastTick = OwningHeroCharacter->GetActorRotation();

	bIsInAir = OwningMovementComponent->IsFalling();

	bIsDefaultSectionPlaying = DefaultSlotName == Montage_GetCurrentSection();

	if (bHasAcceleration || bIsInAir || !bIsDefaultSectionPlaying)
	{
		IdleElapsedTime = 0.f;
		bShouldEnterRelaxState = false;
	}
	else
	{
		IdleElapsedTime += DeltaSeconds;

		bShouldEnterRelaxState = IdleElapsedTime >= EnterRelaxStateThreshold;
	}
}
