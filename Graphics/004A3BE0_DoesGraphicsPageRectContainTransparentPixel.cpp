#include "tarzan_ghidra_types.hpp"

// Address: 0x004A3BE0
// Label: DoesGraphicsPageRectContainTransparentPixel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
DoesGraphicsPageRectContainTransparentPixel
          (int graphicsObject,uint source2,uint dest,int width,int height)

{
  short *value3;
  uint value;
  uint value2;
  
  value = height + dest;
  if (dest < value) {
    do {
      if (source2 < width + source2) {
        value3 = (short *)((graphicsObject << 8 | dest) * 0x200 + g_GraphicsPageBufferBase + source2 * 2
                          );
        value2 = source2;
        do {
          if (*value3 == 0) {
            return 1;
          }
          value2 = value2 + 1;
          value3 = value3 + 1;
        } while (value2 < width + source2);
      }
      dest = dest + 1;
    } while (dest < value);
  }
  return 0;
}

