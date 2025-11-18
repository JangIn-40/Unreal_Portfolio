// JIH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "MWDamageZoneBase.generated.h"

class UBoxComponent;
class UParticleSystemComponent;
struct FGameplayEventData;
struct FActiveGameplayEffectHandle;

UCLASS()
class MW_API AMWDamageZoneBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMWDamageZoneBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "DamageZone")
	UBoxComponent* DamageZoneCollisionBox;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "DamageZone")
	UParticleSystemComponent* DamageZoneParticleSystem;

	UPROPERTY(BlueprintReadOnly, Category = "DamageZone", meta = (ExposeOnSpawn = "true"))
	FGameplayEffectSpecHandle DamageZoneEffectSpecHandle;

	UFUNCTION()
	virtual void OnDamageZoneBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	UFUNCTION()
	virtual void OnDamageZoneEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	void HandleApplyDamage(APawn* InOverlappedPawn, const FGameplayEventData& InPayload);

	TArray<AActor*> OverlappedActors;

	FActiveGameplayEffectHandle GameplayEffectHandle;
};
