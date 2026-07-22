#include "tarzan_ghidra_types.hpp"

// Address: 0x004ADE70
// Label: AllocatePalettedTextureAtlasRect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint AllocatePalettedTextureAtlasRect(int graphicsObject,uint source2,uint dest)

{
  uint value4;
  uint value5;
  int value;
  uint *dataCursor;
  uint value6;
  uint value7;
  int value2;
  int value3;
  uint *dataCursor2;
  int scratchRect;
  int scratchRect3;
  uint *scratchRect2;
  
  value4 = graphicsObject + 0x1ffff;
  value5 = source2 + 0x1ff;
  if (graphicsObject < 8) {
    graphicsObject = 8;
  }
  if ((int)source2 < 8) {
    source2 = 8;
  }
  value = graphicsObject + 7 >> 3;
  value2 = (int)(source2 + 7) >> 3;
  scratchRect = 0x20;
  scratchRect3 = 0x20;
  if (dest != 0) {
    scratchRect = 0x20 - value;
    scratchRect3 = 0x20 - value2;
  }
  source2 = 0;
  scratchRect2 = &g_PalettedTextureAtlasOccupancyGrid;
  do {
    dest = 0;
    dataCursor = scratchRect2;
    if (0 < scratchRect3) {
      do {
        if ((*dataCursor != 0xffffffff) && (value6 = 0, 0 < scratchRect)) {
          do {
            value7 = (1 << ((byte)value & 0x1f)) + -1 << ((byte)value6 & 0x1f);
            value3 = value2;
            dataCursor2 = dataCursor;
            while( true ) {
              if (value3 < 1) {
                if (0 < value2) {
                  dataCursor = &g_PalettedTextureAtlasOccupancyGrid + source2 * 0x20 + dest;
                  do {
                    value2 = value2 + -1;
                    *dataCursor = *dataCursor | value7;
                    dataCursor = dataCursor + 1;
                  } while (value2 != 0);
                }
                return (((dest & 0x1f) << 5 | value6 & 0x1f) << 4 | source2 & 0xf) << 1 |
                       (value4 & 0xff) << 0xf ^ (value5 & 0xff) << 0x17 | 1;
              }
              if ((*dataCursor2 & value7) != 0) break;
              value3 = value3 + -1;
              dataCursor2 = dataCursor2 + 1;
            }
            value6 = value6 + value;
          } while ((int)value6 < scratchRect);
        }
        dest = dest + value2;
        dataCursor = dataCursor + value2;
      } while ((int)dest < scratchRect3);
    }
    scratchRect2 = scratchRect2 + 0x20;
    source2 = source2 + 1;
  } while ((int)scratchRect2 < 0xc467fc);
  g_PalettedTextureAtlasAllocationFailCount = g_PalettedTextureAtlasAllocationFailCount + 1;
  return 0;
}

