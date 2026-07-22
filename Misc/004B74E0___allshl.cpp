#include "tarzan_ghidra_types.hpp"

// Address: 0x004B74E0
// Label: __allshl
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __allshl
   
   Library: Visual Studio */

longlong __fastcall __allshl(byte arg1,int arg2)

{
  uint inputEax;
  
  if (0x3f < arg1) {
    return 0;
  }
  if (arg1 < 0x20) {
    return CONCAT44(arg2 << (arg1 & 0x1f) | inputEax >> 0x20 - (arg1 & 0x1f),
                    inputEax << (arg1 & 0x1f));
  }
  return (ulonglong)(inputEax << (arg1 & 0x1f)) << 0x20;
}

