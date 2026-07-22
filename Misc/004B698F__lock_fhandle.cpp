#include "tarzan_ghidra_types.hpp"

// Address: 0x004B698F
// Label: _lock_fhandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _lock_fhandle(uint arg1)

{
  int value;
  int value2;
  
  value2 = (arg1 & 0x1f) * 0x24;
  value = (&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + value2;
  if (*(int *)(value + 8) == 0) {
    _lock(0x11);
    if (*(int *)(value + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(value + 0xc));
      *(int *)(value + 8) = *(int *)(value + 8) + 1;
    }
    _unlock(0x11);
  }
  EnterCriticalSection
            ((LPCRITICAL_SECTION)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 0xc + value2));
  return;
}

