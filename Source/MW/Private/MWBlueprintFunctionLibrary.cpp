// JIH


#include "MWBlueprintFunctionLibrary.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

UMWAbilitySystemComponent* UMWBlueprintFunctionLibrary::NativeGetMWASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UMWAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

bool UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UMWAbilitySystemComponent* MWASC = NativeGetMWASCFromActor(InActor);

	return MWASC->HasMatchingGameplayTag(TagToCheck);
}
