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