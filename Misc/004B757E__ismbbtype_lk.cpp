#include "tarzan_ghidra_types.hpp"

// Address: 0x004B757E
// Label: _ismbbtype_lk
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 _ismbbtype_lk(byte arg1,uint arg2,byte arg3)

{
  if ((*(byte *)((int)&DAT_00c47120 + arg1 + 1) & arg3) == 0) {
    if (arg2 == 0) {
      arg2 = 0;
    }
    else {
      arg2 = *(ushort *)(&g_CrtMbbTypeLookupState + (uint)arg1 * 2) & arg2;
    }
    if (arg2 == 0) {
      return 0;
    }
  }
  return 1;
}

