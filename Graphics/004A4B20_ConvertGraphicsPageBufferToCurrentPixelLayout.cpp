#include "tarzan_ghidra_types.hpp"

// Address: 0x004A4B20
// Label: ConvertGraphicsPageBufferToCurrentPixelLayout
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ConvertGraphicsPageBufferToCurrentPixelLayout(void)

{
  int value;
  int value2;
  
  value = GetDirtyTexturePageIndex();
  if (g_CurrentGraphicsPixelLayout != value) {
    g_CurrentGraphicsPixelLayout = GetDirtyTexturePageIndex();
    if (g_CurrentGraphicsPixelLayout != 0) {
      value = 0;
      do {
        value2 = value + 2;
        _g_GraphicsPagePixelConvertScratch =
             (*(ushort *)(value + g_GraphicsPageBufferBase) & 0x7fe0) << 1 |
             *(ushort *)(value + g_GraphicsPageBufferBase) & 0x3f;
        *(short *)(value + g_GraphicsPageBufferBase) = (short)_g_GraphicsPagePixelConvertScratch;
        value = value2;
      } while (value2 < 0x200000);
      return;
    }
    g_CurrentGraphicsPixelLayout = 0;
    value = 0;
    do {
      value2 = value + 2;
      _g_GraphicsPagePixelConvertScratch =
           *(ushort *)(value + g_GraphicsPageBufferBase) >> 1 & 0x7fe0 |
           *(ushort *)(value + g_GraphicsPageBufferBase) & 0x1f;
      *(short *)(value + g_GraphicsPageBufferBase) = (short)_g_GraphicsPagePixelConvertScratch;
      value = value2;
    } while (value2 < 0x200000);
  }
  return;
}

