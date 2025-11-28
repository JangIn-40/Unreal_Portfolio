// JIH


#include "AbilitySystem/MWAbilitySystemComponent.h"
#include "MWGameplayTags.h"
#include "MWBlueprintFunctionLibrary.h"

#include "MWDebugHelper.h"

void UMWAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InInputTag)) continue;

		if (UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(GetOwner(), MWGameplayTags::Player_Status_ComboWindow_Start) && AbilitySpec.IsActive())
		{
			bShouldProceedToNextCombo = true;
		}

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UMWAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

}

bool UMWAbilitySystemComponent::TryActivateAbilityByTag(FGameplayTag AbilityTagToActivate)
{
	check(AbilityTagToActivate.IsValid());

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.Ability->GetAssetTags().HasTagExact(AbilityTagToActivate)) continue;

		return TryActivateAbility(AbilitySpec.Handle);
	}

	Debug::Print("Ability Activate failed");

	return false;
}
