#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0A75
// Label: ShiftStringRight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShiftStringRight(char *arg1,int arg2)

{
  size_t shortValue;
  
  if (arg2 != 0) {
    shortValue = strlen(arg1);
    memmove(arg1 + arg2,arg1,shortValue + 1);
  }
  return;
}

