#include "tarzan_ghidra_types.hpp"

// Address: 0x004B37EB
// Label: __ctrandisp2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __ctrandisp2
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

void __ctrandisp2(undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  __fload(arg1,arg2);
  __fload(arg3,arg4);
  __trandisp2();
  HandleCTranscendentalDispatchException();
  return;
}

