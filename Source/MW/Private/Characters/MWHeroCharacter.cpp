// JIH


#include "Characters/MWHeroCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/Controller.h"
#include "DataAssets/Input/DataAsset_InputConfig.h"
#include "Components/Input/MWInputComponent.h"
#include "MWGameplayTags.h"
#include "DataAssets/StartUpData/DataAsset_StartUpDataBase.h"
#include "Components/Combat/HeroCombatComponent.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "MWBlueprintFunctionLibrary.h"
#include "Components/UI/HeroUIComponent.h"
#include "AnimInstance/Hero/MWHeroAnimInstance.h"

#include "MWDebugHelper.h"

AMWHeroCharacter::AMWHeroCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 400.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 470.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 1000.f;

	HeroCombatComponent = CreateDefaultSubobject<UHeroCombatComponent>(TEXT("HeroCombatComponent"));

	HeroUIComponent = CreateDefaultSubobject<UHeroUIComponent>(TEXT("HeroUIComponent"));
}

void AMWHeroCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (!CharacterStartUpData.IsNull())
	{
		if (UDataAsset_StartUpDataBase* LoadedData = CharacterStartUpData.LoadSynchronous())
		{
			LoadedData->GiveToAbilitySystemComponent(MWAbilitySystemComponent);
		}
	}
}

void AMWHeroCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	checkf(InputConfigDataAsset, TEXT("Input Config Data Asset에 유효한 에셋 할당 안함"));

	ULocalPlayer* LocalPlayer = GetController<APlayerController>()->GetLocalPlayer();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);

	check(Subsystem);

	Subsystem->AddMappingContext(InputConfigDataAsset->DefaultMappingContext, 0);

	UMWInputComponent* MWInputComponent = CastChecked<UMWInputComponent>(PlayerInputComponent);

	MWInputComponent->BindNativeInputAction(InputConfigDataAsset, MWGameplayTags::InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	MWInputComponent->BindNativeInputAction(InputConfigDataAsset, MWGameplayTags::InputTag_Look, ETriggerEvent::Triggered, this, &ThisClass::Input_Look);

	MWInputComponent->BindAbilityInputAction(InputConfigDataAsset, this, &ThisClass::Input_AbilityInputPressed, &ThisClass::Input_AbilityInputReleased);
}

void AMWHeroCharacter::BeginPlay()
{
	Super::BeginPlay();

	CachedHeroAnimInstance = Cast<UMWHeroAnimInstance>(GetMesh()->GetAnimInstance());


}

void AMWHeroCharacter::Tick(float DeltaSeconds)
{
	if (CachedHeroAnimInstance)
	{
		if (CachedHeroAnimInstance->GetIsInAir())
		{
			UMWBlueprintFunctionLibrary::RemoveGameplayTagIfFound(this, MWGameplayTags::Player_Status_IsGrounded);
			UMWBlueprintFunctionLibrary::AddGameplayTagIfNone(this, MWGameplayTags::Player_Status_IsFalling);
		}
		else if (!UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(this, MWGameplayTags::Player_Status_OnDoubleJumping))
		{
			UMWBlueprintFunctionLibrary::RemoveGameplayTagIfFound(this, MWGameplayTags::Player_Status_IsFalling);
			UMWBlueprintFunctionLibrary::AddGameplayTagIfNone(this, MWGameplayTags::Player_Status_IsGrounded);
		}
	}
}

UPawnCombatComponent* AMWHeroCharacter::GetPawnCombatComponent() const
{
	return HeroCombatComponent;
}

UPawnUIComponent* AMWHeroCharacter::GetPawnUIComponent() const
{
	return HeroUIComponent;
}

UHeroUIComponent* AMWHeroCharacter::GetHeroUIComponent() const
{
	return HeroUIComponent;
}

void AMWHeroCharacter::OnWeaponCollisionBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (UMWBlueprintFunctionLibrary::IsTargetPawnHostile(this, HitPawn))
		{
			HeroCombatComponent->OnHitTargetActor(HitPawn);
		}
	}
}

void AMWHeroCharacter::OnWeaponCollisionBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (APawn* HitPawn = Cast<APawn>(OtherActor))
	{
		if (UMWBlueprintFunctionLibrary::IsTargetPawnHostile(this, HitPawn))
		{
			HeroCombatComponent->OnWeaponPulledTargetActor(OtherActor);
		}
	}
}

void AMWHeroCharacter::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D MovementVector = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.f, GetController()->GetControlRotation().Yaw, 0.f);

	if (!FMath::IsNearlyZero(MovementVector.Y))
	{
		const FVector ForwardDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(ForwardDirection, MovementVector.Y);
	}

	if (!FMath::IsNearlyZero(MovementVector.X))
	{
		const FVector RightDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(RightDirection, MovementVector.X);
	}
}

void AMWHeroCharacter::Input_Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (!FMath::IsNearlyZero(LookAxisVector.Y))
	{
		AddControllerPitchInput(LookAxisVector.Y);
	}

	if (!FMath::IsNearlyZero(LookAxisVector.X))
	{
		AddControllerYawInput(LookAxisVector.X);
	}
}

void AMWHeroCharacter::Input_AbilityInputPressed(FGameplayTag InInputTag)
{
	MWAbilitySystemComponent->OnAbilityInputPressed(InInputTag);
}

void AMWHeroCharacter::Input_AbilityInputReleased(FGameplayTag InInputTag)
{
	MWAbilitySystemComponent->OnAbilityInputReleased(InInputTag);
}
