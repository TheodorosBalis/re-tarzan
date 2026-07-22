#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACB70
// Label: ResetBitmapCellRuntimeDescriptor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetBitmapCellRuntimeDescriptor(undefined4 *arg1)

{
  int value;
  
  for (value = 7; value != 0; value = value + -1) {
    *arg1 = 0;
    arg1 = arg1 + 1;
  }
  return;
}

