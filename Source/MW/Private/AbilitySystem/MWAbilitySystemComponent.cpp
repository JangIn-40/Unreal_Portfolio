// JIH


#include "AbilitySystem/MWAbilitySystemComponent.h"

void UMWAbilitySystemComponent::OnAbilityInputPressed(const FGameplayTag& InInputTag)
{
	if (!InInputTag.IsValid())
	{
		return;
	}

	for (const FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities())
	{
		if (!AbilitySpec.DynamicAbilityTags.HasTagExact(InInputTag)) continue;

		TryActivateAbility(AbilitySpec.Handle);
	}
}

void UMWAbilitySystemComponent::OnAbilityInputReleased(const FGameplayTag& InInputTag)
{

}
