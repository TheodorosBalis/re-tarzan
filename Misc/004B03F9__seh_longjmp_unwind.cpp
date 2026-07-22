#include "tarzan_ghidra_types.hpp"

// Address: 0x004B03F9
// Label: _seh_longjmp_unwind
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _seh_longjmp_unwind(int arg1)

{
  _local_unwind2(*(undefined4 *)(arg1 + 0x18),*(undefined4 *)(arg1 + 0x1c));
  return;
}

