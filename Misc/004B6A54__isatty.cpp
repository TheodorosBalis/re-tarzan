#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6A54
// Label: _isatty
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

byte _isatty(uint arg1)

{
  if (g_FileDescriptorCapacity <= arg1) {
    return 0;
  }
  return *(byte *)((&g_FileDescriptorBlockTable)[(int)arg1 >> 5] + 4 + (arg1 & 0x1f) * 0x24) &
         0x40;
}

