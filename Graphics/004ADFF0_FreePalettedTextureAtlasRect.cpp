#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADFF0
// Label: FreePalettedTextureAtlasRect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreePalettedTextureAtlasRect(uint *graphicsObject)

{
  uint value4;
  uint value5;
  int value;
  uint value6;
  int value2;
  int value3;
  
  if ((graphicsObject != (uint *)0x0) && (value4 = *graphicsObject, (value4 & 1) != 0)) {
    value5 = (value4 >> 0xf & 0xff) + 1;
    value6 = (value4 >> 0x17 & 0xff) + 1;
    if (value5 < 8) {
      value5 = 8;
    }
    if (value6 < 8) {
      value6 = 8;
    }
    value3 = (int)(value6 + 7) >> 3;
    value2 = 0;
    if (value3 != 0) {
      do {
        value = (*graphicsObject >> 10 & 0x1f) + value2 + (*graphicsObject >> 1 & 0xf) * 0x20;
        value2 = value2 + 1;
        (&g_PalettedTextureAtlasOccupancyGrid)[value] =
             (&g_PalettedTextureAtlasOccupancyGrid)[value] &
             ~((1 << ((byte)((int)(value5 + 7) >> 3) & 0x1f)) + -1 << ((byte)(value4 >> 5) & 0x1f));
      } while (value2 < value3);
    }
    *graphicsObject = *graphicsObject & 0xfffffffe;
  }
  return;
}

