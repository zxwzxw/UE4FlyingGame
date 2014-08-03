// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "FH_Flying.h"

#include "IFlathead.h"

DEFINE_LOG_CATEGORY(LogFlying)

IMPLEMENT_PRIMARY_GAME_MODULE(FFlyingSampleModule, FH_Flying, "FH_Flying");

void FFlyingSampleModule::StartupModule()
{
	if (Flathead::IsAvailable())
	{
		Flathead::Get().LoadGameScript("GameInit.js");
	}
}

void FFlyingSampleModule::ShutdownModule()
{
}

 