#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2563
// Label: _write_string
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void _write_string(char *arg1,int arg2,undefined4 arg3,int *arg4)

{
  char resultFlag;
  
  do {
    if (arg2 < 1) {
      return;
    }
    arg2 = arg2 + -1;
    resultFlag = *arg1;
    arg1 = arg1 + 1;
    WriteCharacterToStreamAndCount((int)resultFlag,arg3,arg4);
  } while (*arg4 != -1);
  return;
}

