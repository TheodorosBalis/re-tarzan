#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0B56
// Label: _lock_file
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _lock_file(uint arg1)

{
  if ((0x51907f < arg1) && (arg1 < 0x5192e1)) {
    _lock(((int)(arg1 - 0x519080) >> 5) + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x20));
  return;
}

