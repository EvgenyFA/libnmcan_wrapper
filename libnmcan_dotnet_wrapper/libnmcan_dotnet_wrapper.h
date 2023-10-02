#pragma once

using namespace System;

namespace libnmcan_dotnet_wrapper {
	extern "C" __declspec(dllexport) CAN_device_list* CanEnumerate();
}
