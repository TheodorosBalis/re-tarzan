#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E080
// Label: GetUserInputAndConvert
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint GetUserInputAndConvert(int arg1)

{
  ushort value;
  uint value2;
  
  value = GetAsyncKeyState(arg1);
  value2 = (&InputBuffer)[arg1] & value & 0x8001;
  (&InputBuffer)[arg1] = value2;
  return ~value2 & value & 0x8001;
}

