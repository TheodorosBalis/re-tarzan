#include "tarzan_ghidra_types.hpp"

// Address: 0x004413F0
// Label: CEntities::ResetHudTextRendererState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::ResetHudTextRendererState(void)

{
  _g_HudTextCursorY = 0;
  g_HudTextCursorX = 0;
  g_HudTextCurrentGlyphX = 0;
  CEntities::InitializeHudGlyphAndSpriteLookupTables();
  g_HudTextRendererState = 0;
  return;
}

