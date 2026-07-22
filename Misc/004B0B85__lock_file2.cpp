#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0B85
// Label: _lock_file2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _lock_file2(int arg1,int arg2)

{
  if (arg1 < 0x14) {
    _lock(arg1 + 0x1c);
    return;
  }
  EnterCriticalSection((LPCRITICAL_SECTION)(arg2 + 0x20));
  return;
}

