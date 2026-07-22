#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7E2A
// Label: ShiftUInt96RightOne
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShiftUInt96RightOne(uint *arg1)

{
  uint value;
  
  value = arg1[1];
  arg1[1] = value >> 1 | arg1[2] << 0x1f;
  arg1[2] = arg1[2] >> 1;
  *arg1 = *arg1 >> 1 | value << 0x1f;
  return;
}

