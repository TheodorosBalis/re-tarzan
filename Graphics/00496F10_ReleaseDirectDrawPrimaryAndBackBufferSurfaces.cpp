#include "tarzan_ghidra_types.hpp"

// Address: 0x00496F10
// Label: ReleaseDirectDrawPrimaryAndBackBufferSurfaces
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirectDrawPrimaryAndBackBufferSurfaces(void)

{
  if (g_DirectDrawBackBufferSurface != (int *)0x0) {
    (**(code **)(*g_DirectDrawBackBufferSurface + 8))(g_DirectDrawBackBufferSurface);
  }
  g_DirectDrawBackBufferSurface = (int *)0x0;
  if (g_DirectDrawOptionalRenderSurface != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_DirectDrawOptionalRenderSurface + 8))(g_DirectDrawOptionalRenderSurface);
  }
  g_DirectDrawOptionalRenderSurface = (int *)0x0;
  if (g_DirectDrawPrimarySurface != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_DirectDrawPrimarySurface + 8))(g_DirectDrawPrimarySurface);
  }
  g_DirectDrawPrimarySurface = (int *)0x0;
  return;
}

