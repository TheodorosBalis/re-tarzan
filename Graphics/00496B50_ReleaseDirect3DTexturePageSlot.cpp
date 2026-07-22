#include "tarzan_ghidra_types.hpp"

// Address: 0x00496B50
// Label: ReleaseDirect3DTexturePageSlot
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirect3DTexturePageSlot(byte graphicsObject)

{
  int *slotCursor;
  uint value;
  
  if (graphicsObject < 0x10) {
    value = (uint)graphicsObject;
    slotCursor = (int *)(&g_Direct3DTextureSurfaceTable)[value];
    if (slotCursor != (int *)0x0) {
      (**(code **)(*slotCursor + 8))(slotCursor);
    }
    slotCursor = (int *)(&g_Direct3DTexturePageSurfaceTable)[value];
    (&g_Direct3DTextureSurfaceTable)[value] = 0;
    if (slotCursor != (int *)0x0) {
      g_Direct3DLastResult = (**(code **)(*slotCursor + 8))(slotCursor);
    }
    (&g_Direct3DTexturePageSurfaceTable)[value] = 0;
    (&g_Direct3DTexturePageReadyTable)[value] = 0;
  }
  return;
}

