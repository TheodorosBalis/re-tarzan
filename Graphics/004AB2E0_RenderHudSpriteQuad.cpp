#include "tarzan_ghidra_types.hpp"

// Address: 0x004AB2E0
// Label: RenderHudSpriteQuad
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderHudSpriteQuad(uint *graphicsObject,undefined4 source2)

{
  uint value5;
  uint3 value6;
  uint *dataCursor;
  uint value7;
  int value2;
  int value3;
  uint value8;
  uint value9;
  int value4;
  int value;
  
  dataCursor = graphicsObject;
  value5 = *(uint *)(*(int *)(graphicsObject[1] + 0x14) + 0x10 + (graphicsObject[2] & 0xfff) * 0x26);
  value8 = *graphicsObject;
  graphicsObject = (uint *)0xffffff;
  if ((value8 & 0x18) != 0) {
    value8 = dataCursor[9];
    _g_SpriteTintColorScratch = value8 & 0xff00 | value8 >> 0x10 & 0xff | (value8 & 0xff) << 0x10;
    graphicsObject = (uint *)_g_SpriteTintColorScratch;
  }
  if (g_FadeBrightnessInverse != 0) {
    value4 = 0x1000 - g_FadeBrightnessInverse;
    graphicsObject = (uint *)((((uint)graphicsObject >> 0x10) * value4 & 0xfffff000) << 4 |
                      (((uint)graphicsObject >> 8 & 0xff) * value4 & 0xfffff00f |
                      ((uint)graphicsObject & 0xff) * value4 >> 8) >> 4);
  }
  if (((uint)graphicsObject & 0xff0000) < 0x7f8000) {
    value8 = (uint)graphicsObject >> 0xf & 0x1fe;
  }
  else {
    value8 = 0xff;
  }
  if (((uint)graphicsObject & 0xff00) < 0x7f80) {
    value9 = (uint)graphicsObject >> 7 & 0x1fe;
  }
  else {
    value9 = 0xff;
  }
  value7 = ((uint)graphicsObject & 0xff) * 2;
  if (0xfe < value7) {
    value7 = 0xff;
  }
  if ((*dataCursor & 4) == 0) {
    value4 = (value5 >> 0x17 & 0xff) + 1;
    value = (value5 >> 0xf & 0xff) + 1;
  }
  else {
    value4 = (int)*(short *)((int)dataCursor + 0x12);
    value = (int)(short)dataCursor[4];
  }
  value6 = (uint3)(value5 >> 8);
  value2 = (CONCAT31((int3)(((uint)(value6 >> 9) << 0x10) >> 8),(char)(value5 >> 10)) & 0xffffff1f) <<
          3;
  value3 = (short)dataCursor[3] * 0x280;
  DrawTexturedQuad((int)(value3 + (value3 >> 0x1f & 0x1ffU)) >> 9,
                   (*(short *)((int)dataCursor + 0xe) * 0x1e0) / 0xf0,(int)(short)dataCursor[4],
                   (int)*(short *)((int)dataCursor + 0x12) << 1,
                   (CONCAT31((int3)((uint)value2 >> 8),(char)(value5 >> 5)) & 0xffff001f) << 3,value2,
                   value,value4,CONCAT31(value6 >> 1,(char)(value5 >> 1)) & 0xffffff0f,
                   value7 | value8 << 0x10 | value9 << 8 | 0xff000000,
                   CONCAT31((int3)((uint)source2 >> 8),(byte)*dataCursor) & 0xffffff01,source2,0,1);
  return;
}

