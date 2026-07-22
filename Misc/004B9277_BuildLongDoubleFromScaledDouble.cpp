#include "tarzan_ghidra_types.hpp"

// Address: 0x004B9277
// Label: BuildLongDoubleFromScaledDouble
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

float10 BuildLongDoubleFromScaledDouble(undefined8 arg1,short arg2)

{
  undefined8 localState;
  
  localState = (double)CONCAT26((arg2 + 0x3fe) * 0x10 | *( undefined2 *)((int)&arg1 + 6) & 0x800f,(undefined6)arg1);
  return (float10)localState;
}

