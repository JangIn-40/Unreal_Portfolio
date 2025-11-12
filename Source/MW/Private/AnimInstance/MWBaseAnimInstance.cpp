// JIH


#include "AnimInstance/MWBaseAnimInstance.h"
#include "MWBlueprintFunctionLibrary.h"

bool UMWBaseAnimInstance::DoesOwnerHaveTag(FGameplayTag TagToCheck) const
{
    if (APawn* OwningPawn = TryGetPawnOwner())
    {
        return UMWBlueprintFunctionLibrary::NativeDoesActorHaveTag(OwningPawn, TagToCheck);
    }

    return false;
}
