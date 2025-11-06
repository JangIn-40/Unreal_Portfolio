// JIH


#include "MWBlueprintFunctionLibrary.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "MWGameplayTags.h"

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

FGameplayTag UMWBlueprintFunctionLibrary::ComputeHitReactDirectionTag(AActor* InAttacker, AActor* InVictim)
{
	check(InAttacker && InVictim);

	const FVector VictimForward = InVictim->GetActorForwardVector();
	const FVector VictimToAttackerNoramlized = (InAttacker->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();

	const float DotResult = FVector::DotProduct(VictimForward, VictimToAttackerNoramlized);
	float OutAngleDiff = UKismetMathLibrary::DegAcos(DotResult);

	const FVector CrossResult = FVector::CrossProduct(VictimForward, VictimToAttackerNoramlized);

	if (CrossResult.Z < 0.f)
	{
		OutAngleDiff *= -1.f;
	}

	if (OutAngleDiff <= 45.f && OutAngleDiff >= -45.f)
	{
		return MWGameplayTags::Shared_Status_HitReact_Front;
	}
	else if (OutAngleDiff <= 135.f && OutAngleDiff > 45.f)
	{
		return MWGameplayTags::Shared_Status_HitReact_Right;
	}
	else if (OutAngleDiff < -135.f || OutAngleDiff > 135.f)
	{
		return MWGameplayTags::Shared_Status_HitReact_Back;
	}
	else if (OutAngleDiff < -45.f && OutAngleDiff >= -135.f)
	{
		return MWGameplayTags::Shared_Status_HitReact_Left;
	}

	return MWGameplayTags::Shared_Status_HitReact_Front;
}

FGameplayTag UMWBlueprintFunctionLibrary::ComputeHitReactOnlyFwdBwdDirectionTag(AActor* InAttacker, AActor* InVictim)
{
	check(InAttacker && InVictim);

	const FVector VictimForward = InVictim->GetActorForwardVector();
	const FVector VictimToAttackerNoramlized = (InAttacker->GetActorLocation() - InVictim->GetActorLocation()).GetSafeNormal();

	const float DotResult = FVector::DotProduct(VictimForward, VictimToAttackerNoramlized);

	if (DotResult >= 0.f)
	{
		return MWGameplayTags::Shared_Status_HitReact_Front;
	}
	else
	{
		return MWGameplayTags::Shared_Status_HitReact_Back;
	}
}
