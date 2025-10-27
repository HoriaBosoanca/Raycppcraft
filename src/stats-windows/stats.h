#pragma once

#include <cstdint>
#include <processthreadsapi.h>
#include <psapi.h>

inline int64_t getMemoryKB() {
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
    return (int64_t) info.WorkingSetSize / 1024;
}