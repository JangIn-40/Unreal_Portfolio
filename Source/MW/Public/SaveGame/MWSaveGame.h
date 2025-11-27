// JIH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Types/MWEnumTypes.h"
#include "MWSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class MW_API UMWSaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	EMWGameDfficulty SaveCurrentGameDifficulty;

	UPROPERTY(BlueprintReadOnly)
	int32 SavedCurrentWaveCount;
};
