#include "tarzan_ghidra_types.hpp"

// Address: 0x004B5C34
// Label: _control87
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _control87(undefined4 arg1,uint arg2)

{
  _controlfp(arg1,arg2 & 0xfff7ffff);
  return;
}

