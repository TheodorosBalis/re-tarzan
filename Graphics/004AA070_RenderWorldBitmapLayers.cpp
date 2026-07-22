#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA070
// Label: RenderWorldBitmapLayers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderWorldBitmapLayers(int graphicsObject)

{
  int value;
  int value2;
  
  if (*(int *)(graphicsObject + 0x10) != 0) {
    g_RenderBlendMode = 0;
    value2 = *(int *)(graphicsObject + 0x10);
    if (-1 < value2 + -1) {
      value = *(int *)(graphicsObject + 0x14) + (value2 + -1) * 0x72;
      do {
        if ((*(byte *)(value + 4) & 2) != 0) {
          RenderWorldBitmapLayer(value,&g_CameraFocusX,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40);
        }
        value = value + -0x72;
        value2 = value2 + -1;
      } while (value2 != 0);
    }
  }
  return;
}

