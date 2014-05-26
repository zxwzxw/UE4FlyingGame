// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Engine.h"

#define FLYING_SAMPLE_VERSION FString("Version 0.0.1a")

class FFlyingSampleModule : public FDefaultGameModuleImpl
{
	virtual void StartupModule() OVERRIDE;
	virtual void ShutdownModule() OVERRIDE;
};

namespace Objects
{
	template<typename T>
	T * Get(wchar_t* s)
	{
		ConstructorHelpers::FObjectFinder<T> result(s);

		return result.Object;
	};
}

DECLARE_LOG_CATEGORY_EXTERN(LogFlying, Log, All);

