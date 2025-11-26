// JIH


#include "AnimNotify/AN_PlaySoundOnChance.h"
#include "Kismet/KismetMathLibrary.h"

void UAN_PlaySoundOnChance::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	const float SuccessChance = UKismetMathLibrary::RandomFloatInRange(SuccessChanceMin, SuccessChanceMax);
	const bool bIsSucceded = UKismetMathLibrary::RandomBoolWithWeight(SuccessChance);

	if (bIsSucceded)
	{
		Super::Notify(MeshComp, Animation, EventReference);
	}
}
