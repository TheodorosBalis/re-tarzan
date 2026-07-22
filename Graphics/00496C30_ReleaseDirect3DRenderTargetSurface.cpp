#include "tarzan_ghidra_types.hpp"

// Address: 0x00496C30
// Label: ReleaseDirect3DRenderTargetSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseDirect3DRenderTargetSurface(void)

{
  if (g_Direct3DRenderTargetInterface != (int *)0x0) {
    (**(code **)(*g_Direct3DRenderTargetInterface + 8))(g_Direct3DRenderTargetInterface);
  }
  g_Direct3DRenderTargetInterface = (int *)0x0;
  if (g_Direct3DRenderTargetSurface != (int *)0x0) {
    g_Direct3DLastResult =
         (**(code **)(*g_Direct3DRenderTargetSurface + 8))(g_Direct3DRenderTargetSurface);
  }
  g_Direct3DRenderTargetSurface = (int *)0x0;
  return;
}

