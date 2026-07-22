#include "tarzan_ghidra_types.hpp"

// Address: 0x004B53B1
// Label: UngetInputCharacter
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UngetInputCharacter(int arg1,undefined4 arg2)

{
  if (arg1 != -1) {
    _ungetc_lk(arg1,arg2);
  }
  return;
}

