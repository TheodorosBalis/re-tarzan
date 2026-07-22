#include "tarzan_ghidra_types.hpp"

// Address: 0x004B05B2
// Label: __amsg_exit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __amsg_exit
   
   Library: Visual Studio 2003 Release */

void __cdecl __amsg_exit(int arg1)

{
  if (g_CrtRuntimeErrorOutputMode == 1) {
    _FF_MSGBANNER();
  }
  _NMSG_WRITE(arg1);
  (*(code *)g_CrtRuntimeErrorMessageTable)(0xff);
  return;
}

