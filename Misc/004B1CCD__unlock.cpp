#include "tarzan_ghidra_types.hpp"

// Address: 0x004B1CCD
// Label: _unlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _unlock(int arg1)

{
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)(&g_CrtLockCriticalSectionTable + arg1 * 4));
  return;
}

