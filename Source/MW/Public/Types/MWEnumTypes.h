#pragma once

UENUM()
enum class EMWValidType : uint8
{
	Valid,
	InValid
};

UENUM()
enum class EMWConfirmType : uint8
{
	Yes,
	No
};

UENUM()
enum class EMWCountdownActionInput : uint8
{
	Start,
	Cancel
};

UENUM()
enum class EMWCountdownActionOutput : uint8
{
	Updated,
	Completed,
	Cancelled
};

UENUM(BlueprintType)
enum class EMWSurvivalGameModeState : uint8
{
	WaitSpawnNewWave,
	SpawningNewWave,
	InProgress,
	WaveCompleted,
	AllWavesDone,
	PlayerDied
};

UENUM(BlueprintType)
enum class EMWInputMode : uint8
{
	GameOnly,
	UIOnly
};

UENUM(BlueprintType)
enum class EMWGameDfficulty : uint8
{
	Easy,
	Normal,
	Hard,
	VeryHard	
};