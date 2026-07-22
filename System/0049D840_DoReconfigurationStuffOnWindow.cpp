#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D840
// Label: DoReconfigurationStuffOnWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DoReconfigurationStuffOnWindow(void)

{
  ZeroGlobal723738();
  UnlockGlideFrameBuffer();
  SetGlideFullscreenDisplayMode(0);
  if (g_GlideTextureMemoryBase != (HMODULE)0x0) {
    if ((g_GlideWindowModePending != 0) && (g_GlideProcTable_Field0040 != (code *)0x0)) {
      (*g_GlideProcTable_Field0040)();
    }
    FreeLibrary(g_GlideTextureMemoryBase);
    g_GlideTextureMemoryBase = (HMODULE)0x0;
  }
  ReconfigureMainWindowAndMouseIfNeeded(g_GlideFullscreenMode);
  g_GlideWindowModePending = 0;
  g_GlideFrameBufferPtr = 0;
  return;
}

