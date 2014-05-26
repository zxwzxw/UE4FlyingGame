// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "FH_Flying.h"
#include "FH_Flying.generated.inl"

#include "IFlathead.h"

DEFINE_LOG_CATEGORY(LogFlying)

IMPLEMENT_PRIMARY_GAME_MODULE(FFlyingSampleModule, FH_Flying, "FH_Flying");

void FFlyingSampleModule::StartupModule()
{
	if (IFlathead::IsAvailable())
	{
		IFlathead::Get().LoadGameScript("GameInit.js");
	}
}

void FFlyingSampleModule::ShutdownModule()
{
}

 