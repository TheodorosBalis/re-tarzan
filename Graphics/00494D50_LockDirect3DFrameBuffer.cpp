#include "tarzan_ghidra_types.hpp"

// Address: 0x00494D50
// Label: LockDirect3DFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 LockDirect3DFrameBuffer(int graphicsObject,int *source2,int *dest,undefined4 *width)

{
  int value;
  undefined4 *bufferCursor;
  undefined4 scratchRect3 [4];
  int scratchRect2;
  int scratchRect;
  
  if ((((g_Direct3DRendererInitialized != 0) && (source2 != (int *)0x0)) && (dest != (int *)0x0))
     && ((width != (undefined4 *)0x0 && (g_Direct3DFrameBufferLocked == 0)))) {
    *source2 = 0;
    *dest = 0;
    *width = 0;
    bufferCursor = scratchRect3;
    for (value = 0x1b; value != 0; value = value + -1) {
      *bufferCursor = 0;
      bufferCursor = bufferCursor + 1;
    }
    scratchRect3[0] = 0x6c;
    if (g_DirectDrawBackBufferSurface != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_DirectDrawBackBufferSurface + 100))
                     (g_DirectDrawBackBufferSurface,0,scratchRect3,(-(graphicsObject != 0) & 0x10U) + 0x10 | 1,
                      0);
    }
    g_Direct3DLockedSurfaceSelector = 1;
    g_Direct3DFrameBufferLocked = (graphicsObject != 0) + 1;
    if ((scratchRect != 0) && (0x27f < scratchRect2)) {
      *source2 = scratchRect;
      *dest = scratchRect2;
      *width = g_Direct3DBackBufferIsRgb565;
      return 1;
    }
    UnlockDirect3DFrameBuffer();
  }
  return 0;
}

