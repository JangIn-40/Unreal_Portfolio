// JIH


#include "AnimNotify/AN_PlayParticleEffectWithTag.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"
#include "Particles/ParticleSystem.h"

UParticleSystemComponent* UAN_PlayParticleEffectWithTag::SpawnParticleSystem(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	UParticleSystemComponent* ParticleSystem = nullptr;

	UWorld* World = MeshComp->GetWorld();
	EWorldType::Type WorldType = World->WorldType;

	if (WorldType == EWorldType::EditorPreview)
	{
		ParticleSystem = Super::SpawnParticleSystem(MeshComp, Animation);
	}
	else
	{
		if (UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(MeshComp->GetOwner(), TagToCheck))
		{
			ParticleSystem = Super::SpawnParticleSystem(MeshComp, Animation);
		}
	}

	return ParticleSystem;
}
