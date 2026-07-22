#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5360
// Label: ConvertHexDigitCharacter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint ConvertHexDigitCharacter(uint arg1)

{
  uint value;
  
  if (g_CrtLocaleEnabled < 2) {
    value = (byte)g_CrtCtypeTable[arg1 * 2] & 4;
  }
  else {
    value = _isctype(arg1,4);
  }
  if (value == 0) {
    arg1 = (arg1 & 0xffffffdf) - 7;
  }
  return arg1;
}

