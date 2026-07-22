#include "tarzan_ghidra_types.hpp"

// Address: 0x00496210
// Label: BeginDirect3DFrameAndClearBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void BeginDirect3DFrameAndClearBackBuffer(uint graphicsObject)

{
  uint value2;
  int value;
  undefined4 *bufferCursor;
  undefined4 scratchRect5;
  undefined4 scratchRect4;
  undefined4 scratchRect3;
  undefined4 scratchRect2;
  undefined4 scratchRect [20];
  uint scratchRect6;
  
  if (((g_Direct3DRendererInitialized != 0) && (g_Direct3DFrameDirty == 0)) &&
     (g_Direct3DFrameBufferLocked == 0)) {
    if (g_Direct3DDevice != 0) {
      scratchRect5 = 0;
      scratchRect4 = 0;
      scratchRect3 = 0x280;
      scratchRect2 = 0x1e0;
      if (g_Direct3DViewport != (int *)0x0) {
        g_Direct3DLastResult =
             (**(code **)(*g_Direct3DViewport + 0x30))(g_Direct3DViewport,1,&scratchRect5,2);
      }
    }
    if (graphicsObject != 0xffffffff) {
      bufferCursor = scratchRect;
      for (value = 0x19; value != 0; value = value + -1) {
        *bufferCursor = 0;
        bufferCursor = bufferCursor + 1;
      }
      scratchRect[0] = 100;
      if (g_Direct3DBackBufferIsRgb565 == 0) {
        value2 = (graphicsObject >> 3 & 0x1f0000 | graphicsObject & 0xf800) >> 3;
      }
      else {
        value2 = (graphicsObject >> 3 & 0x1f0000 | graphicsObject & 0xfc00) >> 2;
      }
      _g_Direct3DFrameState_Field0000 = (value2 | graphicsObject & 0xf8) >> 3;
      scratchRect6 = (value2 | graphicsObject & 0xf8) >> 3;
      if (g_DirectDrawBackBufferSurface != (int *)0x0) {
        g_Direct3DLastResult =
             (**(code **)(*g_DirectDrawBackBufferSurface + 0x14))
                       (g_DirectDrawBackBufferSurface,0,0,0,0x1000400,scratchRect);
      }
    }
    if (g_Direct3DDevice != (int *)0x0) {
      g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x28))(g_Direct3DDevice);
    }
    g_Direct3DFrameDirty = 1;
    g_Direct3DBackBufferPixelMask = 0x80;
    g_Direct3DRenderStateDirty = 0x80;
    g_Direct3DRenderStateCurrentTexturePage = 0x80;
  }
  return;
}

