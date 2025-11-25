// JIH

#pragma once

#include "ScalableFloat.h"
#include "GameplayTagContainer.h"
#include "MWStructTypes.generated.h"

class UMWGameplayAbility;
class AMWEnemyCharacter;

USTRUCT(BlueprintType)
struct FMWHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UMWGameplayAbility> AbilityToGrant;

	bool IsValid() const;
};

USTRUCT(BlueprintType)
struct FMWHeroSpecialAbilitySets : public FMWHeroAbilitySet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UMaterialInterface> SoftAbilityIconMaterial;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Player.Cooldown"))
	FGameplayTag AbilityCooldownTag;
};

USTRUCT(BlueprintType)
struct FMWHeroUIData
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftObjectPtr<UTexture2D> SoftHeroPortraitIconTexture;
};

USTRUCT(BlueprintType)
struct FMWEnemyWaveSpawnerInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSoftClassPtr<AMWEnemyCharacter> SoftEnemyClassToSpawn;

	UPROPERTY(EditDefaultsOnly)
	int32 MinPerSpawnCount = 1;

	UPROPERTY(EditDefaultsOnly)
	int32 MaxPerSpawnCount = 3;
};

USTRUCT(BlueprintType)
struct FMWEnemyWaveSpawnerTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TArray<FMWEnemyWaveSpawnerInfo> EnemyWaveSpawnerDefinitions;

	UPROPERTY(EditDefaultsOnly)
	int32 TotalEnemyToSpawnThisWave = 1;
};

USTRUCT(BlueprintType)
struct FMWGameLevelSet
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, meta = (Categories = "GameData.Level"))
	FGameplayTag LevelTag;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<UWorld> Level;

	bool IsValid() const
	{
		return LevelTag.IsValid() && !Level.IsNull();
	}
};