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

		if (UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(GetOwner(), MWGameplayTags::Player_Status_IsAttacking) && AbilitySpec.IsActive())
		{
			bShouldProceedToNextCombo = true;
		}

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UMWAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

}
