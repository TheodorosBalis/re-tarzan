#include "tarzan_ghidra_types.hpp"

// Address: 0x004B36F1
// Label: _initptd
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _initptd(int arg1)

{
  *(undefined **)(arg1 + 0x50) = &DAT_0051b950;
  *(undefined4 *)(arg1 + 0x14) = 1;
  return;
}

