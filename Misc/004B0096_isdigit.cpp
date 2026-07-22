#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0096
// Label: isdigit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint isdigit(int arg1)

{
  uint value;
  
  if (1 < g_CrtLocaleEnabled) {
    value = _isctype(arg1,8);
    return value;
  }
  return (byte)g_CrtCtypeTable[arg1 * 2] & 8;
}

