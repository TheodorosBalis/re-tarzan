#include "tarzan_ghidra_types.hpp"

// Address: 0x00497B70
// Label: ReleaseDirectDrawSurfaces
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirectDrawSurfaces(void)

{
  if (g_DirectDrawBackBufferSurface != (int *)0x0) {
    (**(code **)(*g_DirectDrawBackBufferSurface + 8))(g_DirectDrawBackBufferSurface);
  }
  g_DirectDrawBackBufferSurface = (int *)0x0;
  if (g_DirectDrawPrimarySurface != (int *)0x0) {
    g_DirectDrawLastResult =
         (**(code **)(*g_DirectDrawPrimarySurface + 8))(g_DirectDrawPrimarySurface);
  }
  g_DirectDrawPrimarySurface = (int *)0x0;
  return;
}

