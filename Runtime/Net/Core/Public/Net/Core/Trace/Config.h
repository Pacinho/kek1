// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Trace/Config.h"

// Forward declarations
class FNetTraceCollector;

#if !defined(UE_NET_TRACE_ENABLED)
#	if !(UE_BUILD_SHIPPING || UE_BUILD_TEST) && UE_TRACE_ENABLED
#		define UE_NET_TRACE_ENABLED 1
#	else
#		define UE_NET_TRACE_ENABLED 0
#	endif
#endif

namespace ENetTraceVerbosity
{
	enum Type : uint32
	{
		None = 0,
		Trace,
		Verbose,
		VeryVerbose,
	};
}

#if UE_NET_TRACE_ENABLED
#	ifndef UE_NET_TRACE_COMPILETIME_VERBOSITY
#		define UE_NET_TRACE_COMPILETIME_VERBOSITY ENetTraceVerbosity::Verbose
#	endif
#else
#	define UE_NET_TRACE_COMPILETIME_VERBOSITY ENetTraceVerbosity::None
#endif