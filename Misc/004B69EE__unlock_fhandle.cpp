#include "tarzan_ghidra_types.hpp"

// Address: 0x004B69EE
// Label: _unlock_fhandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _unlock_fhandle(uint arg1)

{
  LeaveCriticalSection
            ((LPCRITICAL_SECTION)
             ((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 0xc + (arg1 & 0x1f) * 0x24));
  return;
}

