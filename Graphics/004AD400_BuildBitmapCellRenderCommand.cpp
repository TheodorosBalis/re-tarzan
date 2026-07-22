#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD400
// Label: BuildBitmapCellRenderCommand
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BuildBitmapCellRenderCommand
               (ushort *graphicsObject,uint *source2,uint dest,ushort width,int height)

{
  undefined1 *dataCursor;
  byte flagByte;
  undefined1 value2;
  byte flagByte2;
  ushort value3;
  int value;
  uint value4;
  
  *source2 = 0;
  source2[1] = 0;
  source2[2] = 0;
  *(undefined2 *)(source2 + 3) = 0;
  if ((*graphicsObject & 0x8000) != 0) {
    *source2 = (-(uint)(*graphicsObject != 0x8000) & 2) << 0x16 | *source2 & 0xff3fffff;
    value4 = (uint)*graphicsObject;
    _g_TextureColorConvertScratch =
         ((value4 & 0x1f) << 0xd | value4 & 0x3e0) << 6 | (value4 & 0x7c00) >> 7;
    _g_TextureColorConvertScratch =
         _g_TextureColorConvertScratch | _g_TextureColorConvertScratch >> 5 & 0x70707;
    source2[1] = _g_TextureColorConvertScratch;
    *(undefined2 *)((int)source2 + 10) = 0;
    *(undefined2 *)(source2 + 3) = 0;
    *(undefined2 *)(source2 + 2) = 0xfd01;
    *source2 = (uint)(width & 0x1ff | 0x1e00) << 9 | dest & 0x1ff | *source2 & 0xfffc0000;
    return;
  }
  value4 = *source2;
  *source2 = value4 & 0xff7fffff | 0x400000;
  value3 = *graphicsObject;
  value = *(int *)(height + 4);
  source2[1] = 0xffffff;
  dataCursor = (undefined1 *)(value + (uint)value3 * 0x26);
  *(undefined2 *)((int)source2 + 10) = *(undefined2 *)(dataCursor + 8);
  *(undefined2 *)(source2 + 3) = *(undefined2 *)(dataCursor + 10);
  value3 = *(ushort *)(dataCursor + 2);
  *source2 = value3 & 0x1ff | value4 & 0xff7ffe00 | 0x400000;
  *source2 = (*(ushort *)(dataCursor + 4) & 0x1ff) << 9 | value3 & 0x1ff | value4 & 0xff7c0000 | 0x400000;
  flagByte = dataCursor[1];
  *(ushort *)(source2 + 2) = (ushort)flagByte | (ushort)source2[2] & 0xff00;
  value2 = *dataCursor;
  *(ushort *)(source2 + 2) = CONCAT11(value2,flagByte);
  flagByte2 = dataCursor[6];
  value4 = *source2;
  *source2 = (flagByte2 & 0xf) << 0x12 | value4 & 0xffc3ffff;
  value = DoesGraphicsPageRectContainTransparentPixel
                    (flagByte2 & 0xf,flagByte,value2,value4 & 0x1ff,(value4 & 0x3fe00) >> 9);
  *source2 = (uint)(value == 0) << 0x18 | *source2 & 0xfeffffff;
  return;
}

