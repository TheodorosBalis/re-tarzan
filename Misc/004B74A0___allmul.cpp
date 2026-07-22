#include "tarzan_ghidra_types.hpp"

// Address: 0x004B74A0
// Label: __allmul
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* Library Function - Single Match
    __allmul
   
   Library: Visual Studio */

longlong __allmul(uint arg1,int arg2,uint arg3,int arg4)

{
  if (arg4 == 0 && arg2 == 0) {
    return (ulonglong)arg1 * (ulonglong)arg3;
  }
  return CONCAT44((int)((ulonglong)arg1 * (ulonglong)arg3 >> 0x20) +
                  arg2 * arg3 + arg1 * arg4,
                  (int)((ulonglong)arg1 * (ulonglong)arg3));
}

