#include "tarzan_ghidra_types.hpp"

// Address: 0x00453EB0
// Label: WaitForLogoSkipInput
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint WaitForLogoSkipInput(int arg1,int arg2,uint arg3)

{
  uint value;
  
  arg2 = arg1 - arg2;
  value = 0;
  while (arg1 != 0) {
    arg1 = arg1 + -1;
    GetInputs();
    if ((arg1 < arg2) && ((arg3 & g_InputCurrentMask & g_InputEdgeMask) != 0)) {
      arg1 = 0;
      value = arg3;
    }
  }
  return value;
}

