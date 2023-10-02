#include "pch.h"
#include "libnmcan.h"

#include "libnmcan_dotnet_wrapper.h"

namespace libnmcan_dotnet_wrapper
{
	CAN_device_list* CanEnumerate()
	{
		return CAN_enumerate();
	}
}