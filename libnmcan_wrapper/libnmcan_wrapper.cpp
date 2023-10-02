// libnmcan_wrapper.cpp : Определяет экспортируемые функции для DLL.
//

#include "pch.h"
#include "framework.h"
#include "libnmcan_wrapper.h"
#include "libnmcan.h"


// Пример экспортированной переменной
LIBNMCANWRAPPER_API int nlibnmcanwrapper=0;

// Пример экспортированной функции.
LIBNMCANWRAPPER_API int fnlibnmcanwrapper(void)
{
    return 0;
}

// Конструктор для экспортированного класса.
Clibnmcanwrapper::Clibnmcanwrapper()
{
    return;
}

LIBNMCANWRAPPER_API CAN_device_list* GetEnumerator()
{
    return CAN_enumerate();
}
