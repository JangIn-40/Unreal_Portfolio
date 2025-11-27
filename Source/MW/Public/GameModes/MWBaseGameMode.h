// JIH

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Types/MWEnumTypes.h"
#include "MWBaseGameMode.generated.h"

/**
 * 
 */
UCLASS()
class MW_API AMWBaseGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	AMWBaseGameMode();

	FORCEINLINE EMWGameDfficulty GetCurrentGameDifficulty() const { return CurrentGameDfficulty; }
	FORCEINLINE int32 GetCurrentGameWave() const { return CurrentWaveCount; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Game Settings")
	EMWGameDfficulty CurrentGameDfficulty;

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Game Play Data")
	int32 CurrentWaveCount = 1;
};
