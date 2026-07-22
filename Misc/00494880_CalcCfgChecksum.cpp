#include "tarzan_ghidra_types.hpp"

// Address: 0x00494880
// Label: CalcCfgChecksum
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CalcCfgChecksum(void)

{
  uint value2;
  int value;
  
  value = 0x43464733;
  value2 = 4;
  do {
    value = value + ((int)*(char *)((int)&tarzanCFGbuffer + value2) <<
                    (sbyte)((ulonglong)value2 % 0x17));
    value2 = value2 + 1;
  } while (value2 < 0xb8);
  return value;
}

