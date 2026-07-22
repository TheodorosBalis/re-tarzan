#include "tarzan_ghidra_types.hpp"

// Address: 0x004B7371
// Label: mbtowc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 mbtowc(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  undefined4 value;
  bool flagByte;
  
  InterlockedIncrement((LONG *)&g_CrtLocaleRefCount);
  flagByte = g_CrtLocaleLockActive != 0;
  if (flagByte) {
    InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
    _lock(0x13);
  }
  value = _mbtowc_lk(arg1,arg2,arg3);
  if (flagByte) {
    _unlock(0x13);
  }
  else {
    InterlockedDecrement((LONG *)&g_CrtLocaleRefCount);
  }
  return value;
}

