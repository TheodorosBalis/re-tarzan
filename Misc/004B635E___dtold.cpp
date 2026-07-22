#include "tarzan_ghidra_types.hpp"

// Address: 0x004B635E
// Label: __dtold
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __dtold(uint *arg1,uint *arg2)

{
  ushort value2;
  uint value3;
  uint value4;
  int value;
  uint localState;
  
  value2 = *(ushort *)((int)arg2 + 6);
  value4 = (value2 & 0x7ff0) >> 4;
  value3 = *arg2;
  localState = 0x80000000;
  if (value4 == 0) {
    if (((arg2[1] & 0xfffff) == 0) && (value3 == 0)) {
      arg1[1] = 0;
      *arg1 = 0;
      *(undefined2 *)(arg1 + 2) = 0;
      return;
    }
    value = 0x3c01;
    localState = 0;
  }
  else if (value4 == 0x7ff) {
    value = 0x7fff;
  }
  else {
    value = value4 + 0x3c00;
  }
  localState = value3 >> 0x15 | (arg2[1] & 0xfffff) << 0xb | localState;
  arg1[1] = localState;
  *arg1 = value3 << 0xb;
  while ((localState & 0x80000000) == 0) {
    localState = *arg1 >> 0x1f | localState * 2;
    *arg1 = *arg1 * 2;
    arg1[1] = localState;
    value = value + 0xffff;
  }
  *(ushort *)(arg1 + 2) = value2 & 0x8000 | (ushort)value;
  return;
}

