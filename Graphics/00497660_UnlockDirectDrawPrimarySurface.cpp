#include "tarzan_ghidra_types.hpp"

// Address: 0x00497660
// Label: UnlockDirectDrawPrimarySurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlockDirectDrawPrimarySurface(void)

{
  if ((g_DirectDrawGraphicsModeInitialized != 0) && (g_DirectDrawPrimarySurfaceLocked != 0)) {
    if (g_DirectDrawBackBufferSurface != (int *)0x0) {
      g_DirectDrawLastResult =
           (**(code **)(*g_DirectDrawBackBufferSurface + 0x80))(g_DirectDrawBackBufferSurface,0);
    }
    g_DirectDrawPrimarySurfaceLocked = 0;
  }
  return;
}

