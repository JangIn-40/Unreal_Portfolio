// JIH


#include "MWBlueprintFunctionLibrary.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/PawnCombatInterface.h"

UMWAbilitySystemComponent* UMWBlueprintFunctionLibrary::NativeGetMWASCFromActor(AActor* InActor)
{
	check(InActor);

	return CastChecked<UMWAbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(InActor));
}

bool UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck)
{
	UMWAbilitySystemComponent* ASC = NativeGetMWASCFromActor(InActor);

	return ASC->HasMatchingGameplayTag(TagToCheck);
}

void UMWBlueprintFunctionLibrary::AddGameplayTagIfNone(AActor* InActor, FGameplayTag TagToAdd)
{
	UMWAbilitySystemComponent* ASC = NativeGetMWASCFromActor(InActor);

	if (!ASC->HasMatchingGameplayTag(TagToAdd))
	{
		ASC->AddLooseGameplayTag(TagToAdd);
	}
}

void UMWBlueprintFunctionLibrary::RemoveGameplayTagIfFound(AActor* InActor, FGameplayTag TagToRemove)
{
	UMWAbilitySystemComponent* ASC = NativeGetMWASCFromActor(InActor);

	if (ASC->HasMatchingGameplayTag(TagToRemove))
	{
		ASC->RemoveLooseGameplayTag(TagToRemove);
	}
}

bool UMWBlueprintFunctionLibrary::IsTargetPawnHostile(APawn* QueryPawn, APawn* TargetPawn)
{
	check(QueryPawn && TargetPawn);

	IGenericTeamAgentInterface* QueryTeamAgent = Cast<IGenericTeamAgentInterface>(QueryPawn->GetController());
	IGenericTeamAgentInterface* TargetTeamAgent = Cast<IGenericTeamAgentInterface>(TargetPawn->GetController());

	if (QueryTeamAgent && TargetTeamAgent)
	{
		return QueryTeamAgent->GetGenericTeamId() != TargetTeamAgent->GetGenericTeamId();
	}

	return false;
}

UPawnCombatComponent* UMWBlueprintFunctionLibrary::NativeGetPawnCombatComponentFromActor(AActor* InActor)
{
	check(InActor);

	if (IPawnCombatInterface* PawnCombatInterface = Cast<IPawnCombatInterface>(InActor))
	{
		return PawnCombatInterface->GetPawnCombatComponent();
	}

	return nullptr;
}

UPawnCombatComponent* UMWBlueprintFunctionLibrary::BP_GetPawnCombatComponentFromActor(AActor* InActor, EMWValidType& OutValidType)
{
	UPawnCombatComponent* CombatComponent = NativeGetPawnCombatComponentFromActor(InActor);

	OutValidType = CombatComponent ? EMWValidType::Valid : EMWValidType::InValid;

	return CombatComponent;
}
