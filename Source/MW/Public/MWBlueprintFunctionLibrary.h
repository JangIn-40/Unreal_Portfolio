// JIH

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "MWBlueprintFunctionLibrary.generated.h"

class UMWAbilitySystemComponent;
class UPawnCombatComponent;

UENUM()
enum class EMWValidType : uint8
{
	Valid,
	InValid
};

UENUM()
enum class EMWConfirmType : uint8
{
	Yes,
	No
};

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

};
