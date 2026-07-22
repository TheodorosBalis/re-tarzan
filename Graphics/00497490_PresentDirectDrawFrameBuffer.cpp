#include "tarzan_ghidra_types.hpp"

// Address: 0x00497490
// Label: PresentDirectDrawFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PresentDirectDrawFrameBuffer(void)

{
  if (g_DirectDrawGraphicsModeInitialized != 0) {
    UnlockDirectDrawPrimarySurface();
    if (g_DirectDrawPrimarySurface != (int *)0x0) {
      g_DirectDrawLastResult =
           (**(code **)(*g_DirectDrawPrimarySurface + 0x2c))(g_DirectDrawPrimarySurface,0,1);
    }
    if (g_DirectDrawLastResult == -0x7789fe3e) {
      if (g_DirectDrawPrimarySurface != (int *)0x0) {
        (**(code **)(*g_DirectDrawPrimarySurface + 0x6c))(g_DirectDrawPrimarySurface);
      }
      if (g_DirectDrawBackBufferSurface != (int *)0x0) {
        (**(code **)(*g_DirectDrawBackBufferSurface + 0x6c))(g_DirectDrawBackBufferSurface);
      }
    }
  }
  return;
}

