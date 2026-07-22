#include "tarzan_ghidra_types.hpp"

// Address: 0x004A4C00
// Label: UpdateTexturesReference
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateTexturesReference(uint graphicsObject,int source2,int dest,int width,int height)

{
  int value;
  ushort *dataCursor;
  uint value4;
  undefined4 *dataCursor2;
  ushort *dataCursor3;
  int value2;
  undefined4 *dataCursor4;
  int value3;
  undefined4 *dataCursor5;
  
  value3 = g_CurrentGraphicsPixelLayout;
  (&g_DirtyTexturePageFlags)[graphicsObject & 0xf] = 1;
  value = (graphicsObject & 0xf) * 0x10000;
  if (value3 == 0) {
    if (0 < height) {
      dataCursor2 = (undefined4 *)&g_MenuTextureAtlasPixels;
      value3 = (dest * 0x100 + value + source2) * 2;
      do {
        dataCursor5 = (undefined4 *)(g_GraphicsPageBufferBase + value3);
        value3 = value3 + 0x200;
        dataCursor4 = dataCursor2;
        for (value4 = (uint)(width * 2) >> 2; value4 != 0; value4 = value4 - 1) {
          *dataCursor5 = *dataCursor4;
          dataCursor4 = dataCursor4 + 1;
          dataCursor5 = dataCursor5 + 1;
        }
        dataCursor2 = dataCursor2 + 0x80;
        height = height + -1;
        for (value4 = width * 2 & 3; value4 != 0; value4 = value4 - 1) {
          *(undefined1 *)dataCursor5 = *(undefined1 *)dataCursor4;
          dataCursor4 = (undefined4 *)((int)dataCursor4 + 1);
          dataCursor5 = (undefined4 *)((int)dataCursor5 + 1);
        }
      } while (height != 0);
    }
  }
  else if (0 < height) {
    dataCursor3 = &g_MenuTextureAtlasPixels;
    value3 = (dest * 0x100 + value + source2) * 2;
    do {
      dataCursor = dataCursor3;
      value = value3;
      value2 = width;
      if (0 < width) {
        do {
          value2 = value2 + -1;
          *(ushort *)(value + g_GraphicsPageBufferBase) = (*dataCursor & 0xffe0) << 1 | *dataCursor & 0x3f;
          dataCursor = dataCursor + 1;
          value = value + 2;
        } while (value2 != 0);
      }
      value3 = value3 + 0x200;
      dataCursor3 = dataCursor3 + 0x100;
      height = height + -1;
    } while (height != 0);
    return;
  }
  return;
}

