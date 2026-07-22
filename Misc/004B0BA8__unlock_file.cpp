#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0BA8
// Label: _unlock_file
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _unlock_file(uint arg1)

{
  if ((0x51907f < arg1) && (arg1 < 0x5192e1)) {
    _unlock(((int)(arg1 - 0x519080) >> 5) + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(arg1 + 0x20));
  return;
}

