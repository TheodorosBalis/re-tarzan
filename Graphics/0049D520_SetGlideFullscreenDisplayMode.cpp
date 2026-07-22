#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D520
// Label: SetGlideFullscreenDisplayMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 SetGlideFullscreenDisplayMode(int arg1)

{
  int value;
  
  if (g_GlideTextureMemoryBase == 0) {
    return 0;
  }
  if ((g_SetGlideFullscreenDisplayMode_Global_00515F48 != arg1) &&
     ((g_SetGlideFullscreenDisplayMode_Global_00515F48 != -1 || (arg1 != 0)))) {
    g_SetGlideFullscreenDisplayMode_Global_00515F48 = arg1;
    if (arg1 != 0) {
      ReconfigureMainWindowAndMouseIfNeeded2(g_GlideFullscreenMode,0x280,0x1e0);
      value = (*g_GlideProcTable_Field0060)(0,7,0,0,0,2,g_GlideSelectedDisplayMode);
      if (value != 1) {
        return 0;
      }
      ReconfigureMainWindowAndMouseIfNeeded2(g_GlideFullscreenMode,0x280,0x1e0);
      return 1;
    }
    (*g_GlideProcTable_Field005C)();
  }
  return 1;
}

