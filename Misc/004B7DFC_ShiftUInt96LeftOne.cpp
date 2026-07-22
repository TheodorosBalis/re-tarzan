#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7DFC
// Label: ShiftUInt96LeftOne
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShiftUInt96LeftOne(uint *arg1)

{
  uint value;
  uint value2;
  
  value = *arg1;
  value2 = arg1[1];
  *arg1 = value * 2;
  arg1[1] = value2 * 2 | value >> 0x1f;
  arg1[2] = arg1[2] << 1 | value2 >> 0x1f;
  return;
}

