#include "tarzan_ghidra_types.hpp"

// Address: 0x004B00CB
// Label: rand
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl rand(void)

{
  int value;
  uint value2;
  
  value = _getptd();
  value2 = *(int *)(value + 0x14) * 0x343fd + 0x269ec3;
  *(uint *)(value + 0x14) = value2;
  return value2 >> 0x10 & 0x7fff;
}

