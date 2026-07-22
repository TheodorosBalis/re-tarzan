#include "tarzan_ghidra_types.hpp"

// Address: 0x004948C0
// Label: DecodeCfgBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecodeCfgBuffer(void)

{
  uint value;
  
  value = 0;
  do {
    *(byte *)((int)&tarzanCFGbuffer + value) =
         *(byte *)((int)&tarzanCFGbuffer + value) ^ (char)value * '{';
    value = value + 1;
  } while (value < 0xbc);
  return;
}

