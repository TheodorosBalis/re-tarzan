#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9A60
// Label: DrawSceneSpriteQuad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort DrawSceneSpriteQuad(ushort *arg1,undefined4 arg2,undefined4 arg3,uint arg4)

{
  uint value;
  uint value2;
  int entry;
  uint value3;
  
  value = arg4 >> 0x10 & 0xff;
  _g_SpriteTintColorScratch = value | (arg4 & 0xff) << 0x10 | arg4 & 0xff00;
  value2 = _g_SpriteTintColorScratch;
  value3 = _g_SpriteTintColorScratch;
  if (g_FadeBrightnessInverse != 0) {
    entry = 0x1000 - g_FadeBrightnessInverse;
    value2 = ((arg4 & 0xff) * entry & 0xfffff000) << 4;
    value3 = (((arg4 & 0xff00) >> 8) * entry & 0xfffff00f | value * entry >> 8) >> 4 | value2;
  }
  DrawTexturedQuad((int)(short)arg2,(int)*( undefined2 *)((int)&arg2 + 2),arg1[1],arg1[2],
                   (char)(*arg1 >> 8),*arg1 & 0xff,arg1[1],
                   CONCAT22((short)(value2 >> 0x10),arg1[2]),
                   CONCAT31((int3)((value3 | 0xff000000) >> 8),(char)arg1[3]),value3 | 0xff000000,
                   (arg4 & 0xff000000) != 0,arg3,0,1);
  return arg1[1];
}

