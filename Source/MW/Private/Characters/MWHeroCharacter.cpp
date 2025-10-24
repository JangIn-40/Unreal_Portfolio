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

#include "MWDebugHelper.h"

AMWHeroCharacter::AMWHeroCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 200.f;
	CameraBoom->SocketOffset = FVector(0.f, 55.f, 65.f);
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 500.f, 0.f);
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;
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
	MWInputComponent->BindNativeInputAction(InputConfigDataAsset, MWGameplayTags::InputTag_Jump, ETriggerEvent::Started, this, &ACharacter::Jump);
	MWInputComponent->BindNativeInputAction(InputConfigDataAsset, MWGameplayTags::InputTag_Jump, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
}

void AMWHeroCharacter::BeginPlay()
{
	Super::BeginPlay();
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
