#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E060
// Label: IsControlBindingPressed
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint IsControlBindingPressed(undefined1 arg1)

{
  uint value;
  
  value = GetUserInputAndConvert(arg1);
  return value & 0x8000;
}

