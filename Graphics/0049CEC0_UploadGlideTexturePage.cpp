#include "tarzan_ghidra_types.hpp"

// Address: 0x0049CEC0
// Label: UploadGlideTexturePage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 UploadGlideTexturePage(void)

{
  ushort value2;
  ushort *dataCursor;
  int value;
  byte incomingStackArg;
  int incomingStackArg2;
  
  SafeCheckStackPtr();
  if (g_GlideTextureMemoryBase == 0) {
    return 0;
  }
  if (0xf < incomingStackArg) {
    return 0;
  }
  value = 0x10000;
  dataCursor = (ushort *)registerFrame;
  do {
    if (incomingStackArg2 == 0) {
      *dataCursor = 0xbdef;
    }
    else {
      value2 = *(ushort *)((incomingStackArg2 - (int)&stack0x00000000) + (int)dataCursor) & 0x7fff;
      *dataCursor = value2;
      if (value2 != 0) {
        *dataCursor = value2 | 0x8000;
      }
    }
    dataCursor = dataCursor + 1;
    value = value + -1;
  } while (value != 0);
  _g_GlideTextureUploadPageIndex = (undefined1 *)registerFrame;
  (*g_GlideProcTable_Field006C)
            (*(undefined4 *)(&g_GlideTextureUploadScratch + (uint)incomingStackArg * 8),
             *(undefined4 *)(&g_GlideTextureMemoryRanges + (uint)incomingStackArg * 8),3,
             &g_GlideViewportLeft);
  return 1;
}

