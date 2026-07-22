#include "tarzan_ghidra_types.hpp"

// Address: 0x00489F50
// Label: GetWrappedSignedAngleDelta12Bit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetWrappedSignedAngleDelta12Bit(int arg1,int arg2)

{
  uint value;
  
  value = arg2 - arg1 & 0xfff;
  if (0x800 < value) {
    value = value - 0x1000;
  }
  return value;
}

