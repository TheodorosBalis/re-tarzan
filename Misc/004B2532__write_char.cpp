#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2532
// Label: _write_char
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _write_char(undefined4 arg1,int arg2,undefined4 arg3,int *arg4)

{
  do {
    if (arg2 < 1) {
      return;
    }
    arg2 = arg2 + -1;
    WriteCharacterToStreamAndCount(arg1,arg3,arg4);
  } while (*arg4 != -1);
  return;
}

