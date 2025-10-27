#pragma once

#include <processthreadsapi.h>
#include <psapi.h>

inline int getMemoryKB() {
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
    return (int) info.WorkingSetSize / 1024;
}