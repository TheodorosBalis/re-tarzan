#include "tarzan_ghidra_types.hpp"

// Address: 0x004B87A7
// Label: toupper
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int toupper(int arg1)

{
  bool flagByte;
  
  if (g_CrtMultibyteLocaleActive == 0) {
    if ((0x60 < arg1) && (arg1 < 0x7b)) {
      return arg1 + -0x20;
    }
  }
  else {
    InterlockedIncrement((LONG *)&g_CrtLocaleRefCount);
    flagByte = g_CrtLocaleLockActive != 0;
    if (flagByte) {
      InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
      _lock(0x13);
    }
    arg1 = _toupper_lk(arg1);
    if (flagByte) {
      _unlock(0x13);
    }
    else {
      InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
    }
  }
  return arg1;
}

