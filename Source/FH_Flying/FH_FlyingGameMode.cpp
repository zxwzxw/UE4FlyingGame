// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "FH_Flying.h"
#include "FH_FlyingGameMode.h"
#include "FH_FlyingPawn.h"

AFH_FlyingGameMode::AFH_FlyingGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AFH_FlyingPawn::StaticClass();
}
