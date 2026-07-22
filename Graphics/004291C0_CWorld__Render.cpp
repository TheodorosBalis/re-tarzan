#include "tarzan_ghidra_types.hpp"

// Address: 0x004291C0
// Label: CWorld::Render
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::Render(void)

{
  PrepareWorldAndMenuRenderState();
  if (*( undefined2 *)((int)&g_LevelTransitionRequestFlags + 2) != 0) {
    CWorld::RenderNatureTerrain_Thunk();
  }
  CWorld::RenderEntitiesAndHud_Thunk();
  return;
}

