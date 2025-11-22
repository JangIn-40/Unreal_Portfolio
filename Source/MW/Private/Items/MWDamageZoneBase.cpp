// JIH


#include "Items/MWDamageZoneBase.h"
#include "Components/BoxComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "MWBlueprintFunctionLibrary.h"
#include "MWGameplayTags.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "ActiveGameplayEffectHandle.h"

#include "MWDebugHelper.h"

// Sets default values
AMWDamageZoneBase::AMWDamageZoneBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DamageZoneCollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("DamageZoneCollisionBox"));
	SetRootComponent(DamageZoneCollisionBox);
	DamageZoneCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	DamageZoneCollisionBox->OnComponentBeginOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageZoneBeginOverlap);
	DamageZoneCollisionBox->OnComponentEndOverlap.AddUniqueDynamic(this, &ThisClass::OnDamageZoneEndOverlap);

	DamageZoneParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("DamageZoneParticleSystem"));
	DamageZoneParticleSystem->SetupAttachment(GetRootComponent());

	InitialLifeSpan = 10.f;
}

// Called when the game starts or when spawned
void AMWDamageZoneBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AMWDamageZoneBase::OnDamageZoneBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OverlappedActors.Contains(OtherActor))
	{
		return;
	}

	OverlappedActors.AddUnique(OtherActor);

	APawn* OverlapPawn = Cast<APawn>(OtherActor);
	if (OverlapPawn && UMWBlueprintFunctionLibrary::IsTargetPawnHostile(GetInstigator(), OverlapPawn))
	{
		FGameplayEventData Data;
		Data.Instigator = GetInstigator();
		Data.Target = OverlapPawn;

		HandleApplyDamage(OverlapPawn, Data);
	}
}


void AMWDamageZoneBase::OnDamageZoneEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OverlappedActors.Contains(OtherActor))
	{
		return;
	}

	OverlappedActors.Remove(OtherActor);

	APawn* OverlapPawn = Cast<APawn>(OtherActor);
	if (OverlapPawn && UMWBlueprintFunctionLibrary::IsTargetPawnHostile(GetInstigator(), OverlapPawn))
	{
		UMWBlueprintFunctionLibrary::RemoveActiveGameplayEffect(OtherActor, GameplayEffectHandle);
	}
}

void AMWDamageZoneBase::HandleApplyDamage(APawn* InOverlappedPawn, const FGameplayEventData& InPayload)
{
	checkf(DamageZoneEffectSpecHandle.IsValid(), TEXT("Forgot to assgin valid spec handle : %s"), *GetActorNameOrLabel());

	GameplayEffectHandle = UMWBlueprintFunctionLibrary::ApplyGameplayEffectSpecHandleToTarget(GetInstigator(), InOverlappedPawn, DamageZoneEffectSpecHandle);
}