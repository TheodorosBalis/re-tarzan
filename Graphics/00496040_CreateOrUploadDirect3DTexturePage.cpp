#include "tarzan_ghidra_types.hpp"

// Address: 0x00496040
// Label: CreateOrUploadDirect3DTexturePage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CreateOrUploadDirect3DTexturePage(uint graphicsObject,int source2)

{
  int *intCursor;
  char resultFlag;
  ushort value3;
  short shortValue;
  int value;
  ushort *dataCursor;
  undefined4 *dataCursor2;
  int value2;
  undefined4 scratchRect2 [4];
  int scratchRect;
  ushort *scratchRect3;
  
  if (((byte)graphicsObject < 0x10) && (value = CreateDirect3DTexturePageSurfaces(graphicsObject), value != 0)) {
    graphicsObject = graphicsObject & 0xff;
    intCursor = (int *)(&g_Direct3DTexturePageSurfaceTable)[graphicsObject];
    if ((intCursor != (int *)0x0) && (value = (**(code **)(*intCursor + 0x60))(intCursor), value != 0)) {
      (**(code **)(*(int *)(&g_Direct3DTexturePageSurfaceTable)[graphicsObject] + 0x6c))
                ((int *)(&g_Direct3DTexturePageSurfaceTable)[graphicsObject]);
    }
    if ((g_Direct3DRenderTargetSurface != (int *)0x0) &&
       (value = (**(code **)(*g_Direct3DRenderTargetSurface + 0x60))(g_Direct3DRenderTargetSurface),
       value != 0)) {
      (**(code **)(*g_Direct3DRenderTargetSurface + 0x6c))(g_Direct3DRenderTargetSurface);
    }
    dataCursor2 = (undefined4 *)&stack0xffffff90;
    for (value = 0x1b; dataCursor2 = dataCursor2 + 1, value != 0; value = value + -1) {
      *dataCursor2 = 0;
    }
    scratchRect2[0] = 0x6c;
    if (g_Direct3DRenderTargetSurface != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DRenderTargetSurface + 100))
                     (g_Direct3DRenderTargetSurface,0,scratchRect2,0,0);
    }
    if (scratchRect3 != (ushort *)0x0) {
      value = 0;
      do {
        if (source2 == 0) {
          shortValue = ((0x7f < value) - 1 & 0x8000) + 0x3def;
          dataCursor = scratchRect3;
          for (value2 = 0x80; value2 != 0; value2 = value2 + -1) {
            *(uint *)dataCursor = CONCAT22(shortValue,shortValue);
            dataCursor = dataCursor + 2;
          }
          if (0xf4 < value) {
            value2 = 0;
            dataCursor = scratchRect3;
            do {
              resultFlag = (char)value2;
              value2 = value2 + 1;
              *dataCursor = -(ushort)((resultFlag + (char)value & 1U) != 0);
              dataCursor = dataCursor + 1;
            } while (value2 < 0xb);
          }
        }
        else {
          value2 = 0x100;
          dataCursor = scratchRect3;
          do {
            value3 = *(ushort *)((source2 - (int)scratchRect3) + (int)dataCursor) & 0x7fff;
            *dataCursor = value3;
            if (value3 != 0) {
              *dataCursor = value3 | 0x8000;
            }
            dataCursor = dataCursor + 1;
            value2 = value2 + -1;
          } while (value2 != 0);
          source2 = source2 + 0x200;
        }
        value = value + 1;
        scratchRect3 = (ushort *)((int)scratchRect3 + scratchRect);
      } while (value < 0x100);
    }
    if (g_Direct3DRenderTargetSurface != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DRenderTargetSurface + 0x80))(g_Direct3DRenderTargetSurface,0);
    }
    if ((g_Direct3DRenderTargetInterface != 0) &&
       (intCursor = (int *)(&g_Direct3DTextureSurfaceTable)[graphicsObject], intCursor != (int *)0x0)) {
      g_Direct3DLastResult = (**(code **)(*intCursor + 0x14))(intCursor,g_Direct3DRenderTargetInterface);
    }
    if ((((&g_Direct3DTexturePageSurfaceTable)[graphicsObject] != 0) &&
        ((&g_Direct3DTextureSurfaceTable)[graphicsObject] != 0)) &&
       ((&g_Direct3DTexturePageReadyTable)[graphicsObject] != 0)) {
      return 1;
    }
  }
  return 0;
}

