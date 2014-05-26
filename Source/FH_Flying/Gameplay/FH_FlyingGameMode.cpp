// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "FH_Flying.h"
#include "IFlathead.h"
#include "Gameplay/FH_FlyingGameMode.h"
#include "Player/FH_FlyingPawn.h"

AFH_FlyingGameMode::AFH_FlyingGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// set default pawn class to our flying pawn
	DefaultPawnClass = AFH_FlyingPawn::StaticClass();
}

void AFH_FlyingGameMode::Tick(float DeltaSeconds)
{
	FString jsEvent = FString::Printf(TEXT("var event = new CustomEvent(\"game.tick\", {detail: {deltaTime : %0.4f}}); Object.dispatchEvent(event);"), DeltaSeconds);

	UE_LOG(LogFlying, Log, TEXT("%s"), *jsEvent);

	if (IFlathead::IsAvailable())
	{
		IFlathead::Get().Execute(jsEvent, TEXT("GameMode"));
	}
}
