// JIH


#include "Characters/MWBaseCharacter.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystem/MWAttributeSet.h"
#include "Components/BoxComponent.h"
#include "MotionWarpingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AMWBaseCharacter::AMWBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	GetCapsuleComponent()->SetCollisionProfileName(TEXT("MWCapsule"));

	MWAbilitySystemComponent = CreateDefaultSubobject<UMWAbilitySystemComponent>(TEXT("MWAbilitySystemComponent"));

	MWAttributeSet = CreateDefaultSubobject<UMWAttributeSet>(TEXT("MWAttributeSet"));

	MotionWarpingComponent = CreateDefaultSubobject<UMotionWarpingComponent>(TEXT("MotionWarpingComponent"));

	LeftWeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftWeaponCollisionBox"));
	LeftWeaponCollisionBox->SetupAttachment(GetMesh());
	LeftWeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftWeaponCollisionBox->SetCollisionProfileName(TEXT("MWWeapon"));
	LeftWeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxBeginOverlap);
	LeftWeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxEndOverlap);

	RightWeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeaponCollisionBox"));
	RightWeaponCollisionBox->SetupAttachment(GetMesh());
	RightWeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWeaponCollisionBox->SetCollisionProfileName(TEXT("MWWeapon"));
	RightWeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxBeginOverlap);
	RightWeaponCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxEndOverlap);

	GetCharacterMovement()->BrakingDecelerationFlying = 1500.f;
}

UAbilitySystemComponent* AMWBaseCharacter::GetAbilitySystemComponent() const
{
	return GetMWAbilitySystemComponent();
}

UPawnCombatComponent* AMWBaseCharacter::GetPawnCombatComponent() const
{
	return nullptr;
}

UPawnUIComponent* AMWBaseCharacter::GetPawnUIComponent() const
{
	return nullptr;
}

void AMWBaseCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (MWAbilitySystemComponent)
	{
		MWAbilitySystemComponent->InitAbilityActorInfo(this, this);
	}
}

#if WITH_EDITOR
void AMWBaseCharacter::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, LeftWeaponCollisionBoxAttachBoneName))
	{
		LeftWeaponCollisionBox->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, LeftWeaponCollisionBoxAttachBoneName);
	}

	if (PropertyChangedEvent.GetMemberPropertyName() == GET_MEMBER_NAME_CHECKED(ThisClass, RightWeaponCollisionBoxAttachBoneName))
	{
		RightWeaponCollisionBox->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, RightWeaponCollisionBoxAttachBoneName);
	}
}
#endif

void AMWBaseCharacter::OnWeaponCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}

void AMWBaseCharacter::OnWeaponCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
