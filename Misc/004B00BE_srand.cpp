#include "tarzan_ghidra_types.hpp"

// Address: 0x004B00BE
// Label: srand
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void srand(undefined4 arg1)

{
  int value;
  
  value = _getptd();
  *(undefined4 *)(value + 0x14) = arg1;
  return;
}

