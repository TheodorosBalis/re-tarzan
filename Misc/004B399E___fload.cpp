#include "tarzan_ghidra_types.hpp"

// Address: 0x004B399E
// Label: __fload
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __fload
   
   Libraries: Visual Studio 1998, Visual Studio 2003, Visual Studio 2005, Visual Studio 2008 */

float10 __fload(uint arg1,int arg2)

{
  float10 value;
  
  if ((*( undefined2 *)((int)&arg2 + 2) & 0x7ff0) == 0x7ff0) {
    value = (float10)CONCAT28(*( undefined2 *)((int)&arg2 + 2) | 0x7fff,
                              CONCAT44(arg2 << 0xb | arg1 >> 0x15,arg1));
  }
  else {
    value = (float10)(double)CONCAT26(*( undefined2 *)((int)&arg2 + 2),CONCAT24((undefined2)arg2,arg1));
  }
  return value;
}

