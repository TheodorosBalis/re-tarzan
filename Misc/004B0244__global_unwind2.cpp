#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0244
// Label: _global_unwind2
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __global_unwind2
   
   Library: Visual Studio */

void _global_unwind2(PVOID arg1)

{
  RtlUnwind(arg1,(PVOID)0x4b025c,(PEXCEPTION_RECORD)0x0,(PVOID)0x0);
  return;
}

