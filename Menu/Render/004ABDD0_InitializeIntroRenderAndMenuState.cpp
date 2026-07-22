#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABDD0
// Label: InitializeIntroRenderAndMenuState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitializeIntroRenderAndMenuState(void)

{
  InitializeSinCosLookupTable12Bit();
  SetActiveMenuContext(0);
  g_RenderBlendMode = 0;
  return;
}

