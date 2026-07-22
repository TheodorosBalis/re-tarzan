#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0BD7
// Label: _unlock_file2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _unlock_file2(int arg1,int arg2)

{
  if (arg1 < 0x14) {
    _unlock(arg1 + 0x1c);
    return;
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)(arg2 + 0x20));
  return;
}

