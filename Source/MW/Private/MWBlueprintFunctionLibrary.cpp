// JIH


#include "MWBlueprintFunctionLibrary.h"
#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "GenericTeamAgentInterface.h"
#include "Interfaces/PawnCombatInterface.h"
#include "Kismet/KismetMathLibrary.h"
#include "MWGameplayTags.h"
#include "Types/MWCountDown.h"
#include "Characters/MWHeroCharacter.h"
#include "Components/UI/HeroUIComponent.h"
#include "MWGameInstance.h"

#include "MWDebugHelper.h"

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

void UMWBlueprintFunctionLibrary::BP_DoesActorHaveTag(AActor* InActor, FGameplayTag TagToCheck, EMWConfirmType& OutConfirmType)
{
	OutConfirmType = NativeDoesActorHaveTag(InActor, TagToCheck) ? EMWConfirmType::Yes : EMWConfirmType::No;
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

FActiveGameplayEffectHandle UMWBlueprintFunctionLibrary::ApplyGameplayEffectSpecHandleToTarget(AActor* InInstigator, AActor* InTargetActor, const FGameplayEffectSpecHandle& InSpecHandle)
{
	UMWAbilitySystemComponent* SourceASC = NativeGetMWASCFromActor(InInstigator);
	UMWAbilitySystemComponent* TargetASC = NativeGetMWASCFromActor(InTargetActor);

	FActiveGameplayEffectHandle ActiveGameplayHandle = SourceASC->ApplyGameplayEffectSpecToTarget(*InSpecHandle.Data, TargetASC);

	return ActiveGameplayHandle;
}

bool UMWBlueprintFunctionLibrary::RemoveActiveGameplayEffect(AActor* InTargetActor, FActiveGameplayEffectHandle EffectHandle)
{
	UMWAbilitySystemComponent* TargetASC = NativeGetMWASCFromActor(InTargetActor);

	return TargetASC->RemoveActiveGameplayEffect(EffectHandle);
}

void UMWBlueprintFunctionLibrary::CountDown(const UObject* WorldContextObject, float TotalTime, float UpdateInterval, float& OutRemainingTime, EMWCountdownActionInput CountDownInput, UPARAM(DisplayName = "Output") EMWCountdownActionOutput& CountDownOutput, FLatentActionInfo LatentInfo)
{
	UWorld* World = nullptr;

	if (GEngine)
	{
		World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull);
	}

	if (!World)
	{
		return;
	}

	FLatentActionManager& LatentActionManager = World->GetLatentActionManager();

	FMWCountDownAction* FoundAction = LatentActionManager.FindExistingAction<FMWCountDownAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);

	if (CountDownInput == EMWCountdownActionInput::Start)
	{
		if (!FoundAction)
		{
			LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID,
				new FMWCountDownAction(TotalTime, UpdateInterval, OutRemainingTime, CountDownOutput, LatentInfo)
			);
		}
	}

	if (CountDownInput == EMWCountdownActionInput::Cancel)
	{
		if (FoundAction)
		{
			FoundAction->CancelAction();
		}
	}
}

bool UMWBlueprintFunctionLibrary::DoesAbilityRemainingCooldownExistByTag(AActor* InActor, FGameplayTag InCooldownTag)
{
	check(InCooldownTag.IsValid() && InActor);

	FGameplayEffectQuery CooldownQuery = FGameplayEffectQuery::MakeQuery_MatchAnyOwningTags(InCooldownTag.GetSingleTagContainer());

	TArray<TPair<float, float>> TimeRemainingDuration = NativeGetMWASCFromActor(InActor)->GetActiveEffectsTimeRemainingAndDuration(CooldownQuery);

	float RemainingCooldownTime = 0.f;

	if (!TimeRemainingDuration.IsEmpty())
	{
		RemainingCooldownTime = TimeRemainingDuration[0].Key;
	}

	return RemainingCooldownTime > 0.f;
}

void UMWBlueprintFunctionLibrary::SendAbilityActivateableToUI(AActor* InActor, FGameplayTag InInputTag, FGameplayTag InCooldownTag)
{
	check(InActor && InInputTag.IsValid() && InCooldownTag.IsValid());

	if (!DoesAbilityRemainingCooldownExistByTag(InActor, InCooldownTag))
	{
		if(AMWHeroCharacter* HeroCharacter = Cast<AMWHeroCharacter>(InActor))
		{
			UHeroUIComponent* HeroUIComponent = HeroCharacter->GetHeroUIComponent();

			check(HeroUIComponent);

			HeroUIComponent->OnAbilityActivatable.Broadcast(InInputTag);
		}
	}
}

void UMWBlueprintFunctionLibrary::SendAbilityDisableToUI(AActor* InActor, FGameplayTag InInputTag)
{
	check(InActor && InInputTag.IsValid());

	if (AMWHeroCharacter* HeroCharacter = Cast<AMWHeroCharacter>(InActor))
	{
		UHeroUIComponent* HeroUIComponent = HeroCharacter->GetHeroUIComponent();

		check(HeroUIComponent);

		HeroUIComponent->OnAbilityDisable.Broadcast(InInputTag);
	}
}

UMWGameInstance* UMWBlueprintFunctionLibrary::GetMWGameInstance(const UObject* WorldContextObject)
{
	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			return World->GetGameInstance<UMWGameInstance>();
		}
	}

	return nullptr;
}

void UMWBlueprintFunctionLibrary::ToggleInputMode(const UObject* WorldContextObject, EMWInputMode InInputMode)
{
	APlayerController* PlayerController = nullptr;

	if (GEngine)
	{
		if (UWorld* World = GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::LogAndReturnNull))
		{
			PlayerController = World->GetFirstPlayerController();
		}
	}

	if (!PlayerController)
	{
		return;
	}

	FInputModeGameOnly GameOnly;
	FInputModeUIOnly UIOnly;

	switch (InInputMode)
	{
	case EMWInputMode::GameOnly:
		PlayerController->SetInputMode(GameOnly);
		PlayerController->bShowMouseCursor = false;
		break;

	case EMWInputMode::UIOnly:
		PlayerController->SetInputMode(UIOnly);
		PlayerController->bShowMouseCursor = true;
		break;

	}
}
