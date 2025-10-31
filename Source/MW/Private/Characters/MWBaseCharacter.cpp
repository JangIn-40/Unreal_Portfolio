// JIH


#include "Characters/MWBaseCharacter.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystem/MWAttributeSet.h"
#include "Components/BoxComponent.h"

// Sets default values
AMWBaseCharacter::AMWBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetMesh()->bReceivesDecals = false;

	MWAbilitySystemComponent = CreateDefaultSubobject<UMWAbilitySystemComponent>(TEXT("MWAbilitySystemComponent"));

	MWAttributeSet = CreateDefaultSubobject<UMWAttributeSet>(TEXT("MWAttributeSet"));

	LeftWeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("LeftWeaponCollisionBox"));
	LeftWeaponCollisionBox->SetupAttachment(GetMesh());
	LeftWeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	LeftWeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxBeginOverlap);

	RightWeaponCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("RightWeaponCollisionBox"));
	RightWeaponCollisionBox->SetupAttachment(GetMesh());
	RightWeaponCollisionBox->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RightWeaponCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnWeaponCollisionBoxBeginOverlap);
}

UAbilitySystemComponent* AMWBaseCharacter::GetAbilitySystemComponent() const
{
	return GetMWAbilitySystemComponent();
}

UPawnCombatComponent* AMWBaseCharacter::GetPawnCombatComponent() const
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
