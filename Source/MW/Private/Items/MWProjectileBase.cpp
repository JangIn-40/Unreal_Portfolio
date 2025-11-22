// JIH


#include "Items/MWProjectileBase.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
AMWProjectileBase::AMWProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	ProjectileCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ProjectileCollisionBox"));
	SetRootComponent(ProjectileCollisionBox);
	ProjectileCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	ProjectileCollisionBox->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	ProjectileCollisionBox->OnComponentHit.AddUniqueDynamic(this, &ThisClass::OnProjectileHit);

	ProjectileParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ProjectileParticleSystem"));
	ProjectileParticleSystem->SetupAttachment(GetRootComponent());
	
	ProjectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComp"));
	ProjectileMovementComp->InitialSpeed = 400.f;
	ProjectileMovementComp->MaxSpeed = 500.f;
	ProjectileMovementComp->Velocity = FVector(1.f, 0.f, 0.f);
	ProjectileMovementComp->ProjectileGravityScale = 0.f;

	InitialLifeSpan = 4.f;
}

// Called when the game starts or when spawned
void AMWProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMWProjectileBase::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	APawn* HitPawn = Cast<APawn>(OtherActor);

	if (HitPawn)
	{
		BP_OnSpawnProjectileHitCharacterFX(Hit.ImpactPoint);
	}
	else if (HitPawn->ActorHasTag(TEXT("Shared.Object.DamageZone")))
	{
		return;
	}
	else
	{
		BP_OnSpawnProjectileHitWolrdFX(Hit.ImpactPoint);
	}

	if (HitPawn && UMWBlueprintFunctionLibrary::IsTargetPawnHostile(GetInstigator(), HitPawn))
	{
		FGameplayEventData Data;
		Data.Instigator = GetInstigator();
		Data.Target = HitPawn;

		HandleApplyDamage(HitPawn, Data);
	}

	Destroy();
}

void AMWProjectileBase::HandleApplyDamage(APawn* InHitPawn, const FGameplayEventData& InPayload)
{
	checkf(ProjectileEffectSpecHandle.IsValid(), TEXT("Forgot to assgin valid spec handle : %s"), *GetActorNameOrLabel());

	FActiveGameplayEffectHandle ActiveEffectHandle = UMWBlueprintFunctionLibrary::ApplyGameplayEffectSpecHandleToTarget(GetInstigator(), InHitPawn, ProjectileEffectSpecHandle);

	if (ActiveEffectHandle.WasSuccessfullyApplied())
	{
		UAbilitySystemBlueprintLibrary::SendGameplayEventToActor(InHitPawn, MWGameplayTags::Shared_Event_HitReact, InPayload);
	}
}

