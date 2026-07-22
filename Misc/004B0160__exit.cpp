#include "tarzan_ghidra_types.hpp"

// Address: 0x004B0160
// Label: _exit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __exit
   
   Library: Visual Studio 2003 Release */

void __cdecl _exit(int _Code)

{
  doexit(_Code,1,0);
  return;
}

