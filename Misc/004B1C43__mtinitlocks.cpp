#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1C43
// Label: _mtinitlocks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _mtinitlocks(void)

{
  InitializeCriticalSection((LPCRITICAL_SECTION)g_CrtLockTableEntry3);
  InitializeCriticalSection((LPCRITICAL_SECTION)g_CrtLockTableEntry2);
  InitializeCriticalSection((LPCRITICAL_SECTION)g_CrtLockTableEntry1);
  InitializeCriticalSection((LPCRITICAL_SECTION)g_CrtLockTableEntry0);
  return;
}

