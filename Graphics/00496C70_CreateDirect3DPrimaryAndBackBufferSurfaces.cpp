#include "tarzan_ghidra_types.hpp"

// Address: 0x00496C70
// Label: CreateDirect3DPrimaryAndBackBufferSurfaces
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CreateDirect3DPrimaryAndBackBufferSurfaces(void)

{
  int value;
  int value2;
  int *intCursor;
  int *intCursor2;
  int *intCursor3;
  undefined4 *bufferCursor;
  undefined4 scratchRect9;
  undefined4 scratchRect2 [4];
  int scratchRect5;
  int scratchRect4;
  int scratchRect3;
  undefined4 scratchRect8 [5];
  undefined4 scratchRect7;
  undefined4 scratchRect10;
  undefined4 scratchRect6;
  undefined4 scratchRect [25];
  
  bufferCursor = scratchRect8;
  for (value = 0x1b; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  scratchRect8[0] = 0x6c;
  scratchRect8[1] = 0x21;
  scratchRect6 = 0x6218;
  scratchRect7 = 1;
  if (g_DirectDraw != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_DirectDraw + 0x18))(g_DirectDraw,scratchRect8,&g_DirectDrawPrimarySurface,0);
  }
  scratchRect9 = 4;
  if (g_DirectDrawPrimarySurface != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_DirectDrawPrimarySurface + 0x30))
                   (g_DirectDrawPrimarySurface,&scratchRect9,&g_DirectDrawBackBufferSurface);
  }
  if (g_Direct3DDevice != 0) {
    bufferCursor = scratchRect8;
    for (value = 0x1b; value != 0; value = value + -1) {
      *bufferCursor = 0;
      bufferCursor = bufferCursor + 1;
    }
    scratchRect8[0] = 0x6c;
    scratchRect8[1] = 0x47;
    scratchRect6 = 0x24000;
    scratchRect8[3] = 0x280;
    scratchRect8[2] = 0x1e0;
    scratchRect10 = 0x10;
    if (g_DirectDraw != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_DirectDraw + 0x18))
                     (g_DirectDraw,scratchRect8,&g_DirectDrawOptionalRenderSurface,0);
    }
    if ((g_DirectDrawOptionalRenderSurface != 0) && (g_DirectDrawBackBufferSurface != (int *)0x0)) {
      g_Direct3DLastResult =
           (**(code **)(*g_DirectDrawBackBufferSurface + 0xc))
                     (g_DirectDrawBackBufferSurface,g_DirectDrawOptionalRenderSurface);
    }
  }
  value = 2;
  intCursor = g_DirectDrawPrimarySurface;
  intCursor3 = g_DirectDrawBackBufferSurface;
  do {
    bufferCursor = scratchRect;
    for (value2 = 0x19; value2 != 0; value2 = value2 + -1) {
      *bufferCursor = 0;
      bufferCursor = bufferCursor + 1;
    }
    scratchRect[0] = 100;
    if (intCursor != (int *)0x0) {
      g_Direct3DLastResult = (**(code **)(*intCursor + 0x14))(intCursor,0,0,0,0x1000400,scratchRect);
      intCursor = g_DirectDrawPrimarySurface;
      intCursor3 = g_DirectDrawBackBufferSurface;
    }
    bufferCursor = scratchRect;
    for (value2 = 0x19; value2 != 0; value2 = value2 + -1) {
      *bufferCursor = 0;
      bufferCursor = bufferCursor + 1;
    }
    scratchRect[0] = 100;
    if (((intCursor3 != (int *)0x0) &&
        (g_Direct3DLastResult = (**(code **)(*intCursor3 + 0x14))(intCursor3,0,0,0,0x1000400,scratchRect),
        intCursor = g_DirectDrawPrimarySurface, intCursor3 = g_DirectDrawBackBufferSurface,
        g_DirectDrawBackBufferSurface != (int *)0x0)) && (g_DirectDrawPrimarySurface != (int *)0x0))
    {
      g_Direct3DLastResult =
           (**(code **)(*g_DirectDrawPrimarySurface + 0x2c))
                     (g_DirectDrawPrimarySurface,g_DirectDrawBackBufferSurface,1);
      intCursor = g_DirectDrawPrimarySurface;
      intCursor3 = g_DirectDrawBackBufferSurface;
    }
    value = value + -1;
  } while (value != 0);
  bufferCursor = scratchRect2;
  for (value = 8; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  scratchRect2[0] = 0x20;
  intCursor2 = (int *)0x0;
  if (intCursor != (int *)0x0) {
    g_Direct3DLastResult = (**(code **)(*intCursor + 0x54))(intCursor,scratchRect2);
    intCursor2 = g_DirectDrawPrimarySurface;
    intCursor3 = g_DirectDrawBackBufferSurface;
  }
  if (scratchRect5 == 0xf800) {
    if (scratchRect4 != 0x7e0) {
      return 0;
    }
    if (scratchRect3 != 0x1f) {
      return 0;
    }
    g_Direct3DBackBufferIsRgb565 = 1;
  }
  else {
    if (scratchRect5 != 0x7c00) {
      return 0;
    }
    if (scratchRect4 != 0x3e0) {
      return 0;
    }
    if (scratchRect3 != 0x1f) {
      return 0;
    }
    g_Direct3DBackBufferIsRgb565 = 0;
  }
  if (((g_Direct3DDevice == 0) || (g_DirectDrawOptionalRenderSurface != 0)) &&
     ((intCursor2 != (int *)0x0 && (intCursor3 != (int *)0x0)))) {
    return 1;
  }
  return 0;
}

