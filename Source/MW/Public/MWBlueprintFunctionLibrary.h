// JIH

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayTagContainer.h"
#include "MWBlueprintFunctionLibrary.generated.h"

class UMWAbilitySystemComponent;

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

};
