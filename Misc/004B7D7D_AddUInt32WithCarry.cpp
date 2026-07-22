#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7D7D
// Label: AddUInt32WithCarry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 AddUInt32WithCarry(uint arg1,uint arg2,uint *arg3)

{
  uint value;
  undefined4 value2;
  
  value2 = 0;
  value = arg1 + arg2;
  if ((value < arg1) || (value < arg2)) {
    value2 = 1;
  }
  *arg3 = value;
  return value2;
}

