// JIH

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "Types/MWEnumTypes.h"
#include "MWBlueprintFunctionLibrary.generated.h"

class UMWAbilitySystemComponent;
class UPawnCombatComponent;
struct FActiveGameplayEffectHandle;


/**
 * 
 */
UCLASS()
class MW_API UMWBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	static UMWAbilitySystemComponent* NativeGetMWASCFromActor(AActor* InActor);

	static bool NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary", meta = (DisplayName = "Does Actor Have Tag", ExpandEnumAsExecs = "OutConfirmType"))
	static void BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EMWConfirmType& OutConfirmType);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary")
	static void AddGameplayTagIfNone(AActor* InActor, FGameplayTag TagToAdd);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary")
	static void RemoveGameplayTagIfFound(AActor* InActor, FGameplayTag TagToRemove);

	static bool IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn);

	static UPawnCombatComponent* NativeGetPawnCombatComponentFromActor(AActor* InActor);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary", meta = (DisplayName = "Get Pawn Combat Component From Actor", ExpandEnumAsExecs = "OutValidType"))
	static UPawnCombatComponent* BP_GetPawnCombatComponentFromActor(AActor* InActor, EMWValidType& OutValidType);

	UFUNCTION(BlueprintPure, Category = "MW | FunctionLibrary")
	static FGameplayTag ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim);

	UFUNCTION(BlueprintPure, Category = "MW | FunctionLibrary")
	static FGameplayTag ComputeHitReactOnlyFwdBwdDirectionTag(AActor* InAttacker, AActor* InVictim);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary")
	static FActiveGameplayEffectHandle ApplyGameplayEffectSpecHandleToTarget(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary")
	static bool RemoveActiveGameplayEffect(AActor* InTargetActor, FActiveGameplayEffectHandle EffectHandle);

	UFUNCTION(BlueprintCallable, Category = "MW | FunctionLibrary", meta = (Latent, WorldContext = "WorldContextObject", LatentInfo = "LatentInfo", ExpandEnumAsExecs = "CountdownInput|CountdownOutput", TotalTime = "1.0", UpdateInterval = "0.1"))
	static void CountDown(const UObject* WorldContextObject, float TotalTime, float UpdateInterval, float& OutRemainingTime,
		EMWCountdownActionInput CountdownInput, UPARAM(DisplayName = "Output") EMWCountdownActionOutput& CountdownOutput,
		FLatentActionInfo LatentInfo);
};
