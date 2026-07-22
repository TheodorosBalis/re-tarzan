#include "tarzan_ghidra_types.hpp"

// Address: 0x00496BB0
// Label: CreateDirect3DRenderTargetSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CreateDirect3DRenderTargetSurface(void)

{
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  undefined4 scratchRect2 [26];
  undefined4 scratchRect;
  
  dataCursor = &g_DefaultDirectDrawSurfaceDesc555_Field0000;
  dataCursor2 = scratchRect2;
  for (value = 0x1b; value != 0; value = value + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  scratchRect = 0x1800;
  if (g_DirectDraw != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_DirectDraw + 0x18))(g_DirectDraw,scratchRect2,&g_Direct3DRenderTargetSurface,0)
    ;
  }
  if (g_Direct3DRenderTargetSurface != (undefined4 *)0x0) {
    g_Direct3DLastResult =
         (**(code **)*g_Direct3DRenderTargetSurface)
                   (g_Direct3DRenderTargetSurface,&DAT_004babc8,&g_Direct3DRenderTargetInterface);
    if ((g_Direct3DRenderTargetSurface != (undefined4 *)0x0) &&
       (g_Direct3DRenderTargetInterface != 0)) {
      return 1;
    }
  }
  return 0;
}

