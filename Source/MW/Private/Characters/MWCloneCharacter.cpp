// JIH


#include "Characters/MWCloneCharacter.h"
#include "MWBlueprintFunctionLibrary.h"
#include "Components/Combat/PawnCombatComponent.h"
#include "Engine/AssetManager.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/Combat/PawnCombatComponent.h"

#include "MWDebugHelper.h"

AMWCloneCharacter::AMWCloneCharacter()
{
	GetCapsuleComponent()->SetCollisionObjectType(ECollisionChannel::ECC_GameTraceChannel1);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel4, ECR_Ignore);

	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_GameTraceChannel2, ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECC_GameTraceChannel4, ECR_Ignore);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bUseControllerDesiredRotation = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 1000.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 0.f;

	PawnCombatComponent = CreateDefaultSubobject<UPawnCombatComponent>(TEXT("PawnCombatComponent"));
}

UPawnCombatComponent* AMWCloneCharacter::GetPawnCombatComponent() const
{
    return PawnCombatComponent;
}

void AMWCloneCharacter::BeginPlay()
{
	Super::BeginPlay();

	Debug::Print(TEXT("Beginplay Active"));

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(MWAbilitySystemComponent, AbilityLevel);
		}
	}
}

void AMWCloneCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	Debug::Print("Call PossessedBy");


}

void AMWCloneCharacter::OnWeaponCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (UMWBlueprintFunctionLibrary::IsTargetPawnHostile(this, HitPawn))
		{
			PawnCombatComponent->OnHitTargetActor(HitPawn, OverlappedComponent);
		}
	}
}


