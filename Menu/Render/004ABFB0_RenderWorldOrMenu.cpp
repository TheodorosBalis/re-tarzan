#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABFB0
// Label: RenderWorldOrMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderWorldOrMenu(void)

{
  if (g_ActiveWorldOrMenuRenderFn != (code *)0x0) {
    (*g_ActiveWorldOrMenuRenderFn)();
  }
  UpdateEntity3DSounds();
  FrameCount = FrameCount + 1;
  return;
}

