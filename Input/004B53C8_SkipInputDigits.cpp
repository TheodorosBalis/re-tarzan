#include "tarzan_ghidra_types.hpp"

// Address: 0x004B53C8
// Label: SkipInputDigits
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SkipInputDigits(int *arg1,undefined4 arg2)

{
  undefined4 value2;
  int value;
  
  do {
    *arg1 = *arg1 + 1;
    value2 = GetInputCharacter(arg2);
    value = isdigit(value2);
  } while (value != 0);
  return value2;
}

