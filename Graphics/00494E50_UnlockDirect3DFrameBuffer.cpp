#include "tarzan_ghidra_types.hpp"

// Address: 0x00494E50
// Label: UnlockDirect3DFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlockDirect3DFrameBuffer(void)

{
  int *intCursor;
  
  if ((g_Direct3DRendererInitialized != 0) && (g_Direct3DFrameBufferLocked != 0)) {
    intCursor = g_DirectDrawBackBufferSurface;
    if (g_Direct3DLockedSurfaceSelector == 0) {
      intCursor = g_DirectDrawPrimarySurface;
    }
    if (intCursor != (int *)0x0) {
      intCursor = g_DirectDrawPrimarySurface;
      if (g_Direct3DLockedSurfaceSelector != 0) {
        intCursor = g_DirectDrawBackBufferSurface;
      }
      g_Direct3DLastResult = (**(code **)(*intCursor + 0x80))(intCursor,0);
    }
    g_Direct3DFrameBufferLocked = 0;
  }
  return;
}

