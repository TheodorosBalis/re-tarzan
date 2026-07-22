#include "tarzan_ghidra_types.hpp"

// Address: 0x004B6231
// Label: _atodbl
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _atodbl(undefined4 arg1,undefined4 arg2)

{
  undefined1 localState [12];
  
  ParseAsciiFloatingPointString(localState,&arg2,arg2,0,0,0,0);
  __ld12tod(localState,arg1);
  return;
}

