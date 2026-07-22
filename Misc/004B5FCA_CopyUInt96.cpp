#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5FCA
// Label: CopyUInt96
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CopyUInt96(int arg1,undefined4 *arg2)

{
  int value;
  
  arg1 = arg1 - (int)arg2;
  value = 3;
  do {
    *(undefined4 *)(arg1 + (int)arg2) = *arg2;
    arg2 = arg2 + 1;
    value = value + -1;
  } while (value != 0);
  return;
}

