#include "tarzan_ghidra_types.hpp"

// Address: 0x004963D0
// Label: BeginDirect3DSceneOrHandleLostDevice
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BeginDirect3DSceneOrHandleLostDevice(void)

{
  if ((g_Direct3DRendererInitialized != 0) && (g_Direct3DFrameBufferLocked == 0)) {
    FlushPendingDirect3DFrame();
    if (g_DirectDrawPrimarySurface != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_DirectDrawPrimarySurface + 0x2c))(g_DirectDrawPrimarySurface,0,1);
    }
    if (g_Direct3DLastResult == -0x7789fe3e) {
      if (g_DirectDrawPrimarySurface != (int *)0x0) {
        (**(code **)(*g_DirectDrawPrimarySurface + 0x6c))(g_DirectDrawPrimarySurface);
      }
      if (g_DirectDrawBackBufferSurface != (int *)0x0) {
        (**(code **)(*g_DirectDrawBackBufferSurface + 0x6c))(g_DirectDrawBackBufferSurface);
      }
      if (g_DirectDrawOptionalRenderSurface != (int *)0x0) {
        (**(code **)(*g_DirectDrawOptionalRenderSurface + 0x6c))(g_DirectDrawOptionalRenderSurface);
      }
    }
  }
  return;
}

