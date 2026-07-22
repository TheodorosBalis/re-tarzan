#include "tarzan_ghidra_types.hpp"

// Address: 0x004AF457
// Label: fopen
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int fopen(undefined4 arg1,undefined4 arg2)

{
  _fsopen(arg1,arg2,0x40);
  return 0;
}

