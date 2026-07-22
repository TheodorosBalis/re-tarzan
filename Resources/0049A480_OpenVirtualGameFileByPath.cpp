#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A480
// Label: OpenVirtualGameFileByPath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int OpenVirtualGameFileByPath(undefined4 arg1,undefined4 arg2)

{
  uint value6;
  undefined4 value7;
  uint value8;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined1 localState [1024];
  
  if (g_IsTarzanFsdArchiveActive != 0) {
    value7 = NormalizeVirtualGamePath(arg1);
    value8 = HashVirtualGamePath(value7);
    value3 = g_TarzanFsdEntryCount >> 1;
    value6 = (&g_TarzanFsdEntryTable)[value3 * 3];
    value = 0;
    value5 = g_TarzanFsdEntryCount;
    while ((value8 != value6 && (value < value5 + -1))) {
      if (value8 < value6) {
        value4 = value3 - value;
        value2 = value;
        value5 = value3;
      }
      else {
        value4 = value5 - value;
        value2 = value3;
      }
      value3 = (value4 >> 1) + value;
      value6 = (&g_TarzanFsdEntryTable)[value3 * 3];
      value = value2;
    }
    if (value8 != (&g_TarzanFsdEntryTable)[value3 * 3]) {
      LoadSFX(localState,s_FSYS_fopen___s___00515c08,arg1);
      InternalError(localState);
    }
    (&g_TarzanFsdHandleOffsets)[value3] = 0;
    return value3 + 1;
  }
  value = fopen(arg1,arg2);
  if (value == 0) {
    LoadSFX(localState,s_FSYS_fopen___s___00515c08,arg1);
    InternalError(localState);
  }
  return value;
}

