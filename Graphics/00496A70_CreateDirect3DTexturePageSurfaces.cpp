#include "tarzan_ghidra_types.hpp"

// Address: 0x00496A70
// Label: CreateDirect3DTexturePageSurfaces
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CreateDirect3DTexturePageSurfaces(byte graphicsObject)

{
  int *intCursor;
  int *intCursor2;
  int *intCursor3;
  uint value2;
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  bool flagByte;
  undefined4 scratchRect [27];
  
  intCursor2 = g_DirectDraw;
  if (0xf < graphicsObject) {
    return 0;
  }
  value2 = (uint)graphicsObject;
  if ((&g_Direct3DTexturePageReadyTable)[value2] != 0) {
    return 1;
  }
  dataCursor = &g_DefaultDirectDrawSurfaceDesc555_Field0000;
  dataCursor2 = scratchRect;
  for (value = 0x1b; value != 0; value = value + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  intCursor = &g_Direct3DTexturePageSurfaceTable + value2;
  flagByte = g_DirectDraw != (int *)0x0;
  *intCursor = 0;
  if (flagByte) {
    g_Direct3DLastResult = (**(code **)(*intCursor2 + 0x18))(intCursor2,scratchRect,intCursor,0);
  }
  dataCursor = (undefined4 *)*intCursor;
  intCursor2 = &g_Direct3DTextureSurfaceTable + value2;
  *intCursor2 = 0;
  if (dataCursor != (undefined4 *)0x0) {
    g_Direct3DLastResult = (**(code **)*dataCursor)(dataCursor,&DAT_004babc8,intCursor2);
  }
  if ((g_Direct3DDevice != 0) && (intCursor3 = (int *)*intCursor2, intCursor3 != (int *)0x0)) {
    g_Direct3DLastResult =
         (**(code **)(*intCursor3 + 0xc))
                   (intCursor3,g_Direct3DDevice,&g_Direct3DTexturePageReadyTable + value2);
  }
  if (((*intCursor != 0) && (*intCursor2 != 0)) && ((&g_Direct3DTexturePageReadyTable)[value2] != 0)) {
    return 1;
  }
  return 0;
}

