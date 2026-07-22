#include "tarzan_ghidra_types.hpp"

// Address: 0x00489F70
// Label: GetWrappedAngleDistance12Bit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetWrappedAngleDistance12Bit(int arg1,int arg2)

{
  uint value;
  
  value = arg2 - arg1 & 0xfff;
  if (0x800 < value) {
    value = 0x1000 - value;
  }
  return value;
}

