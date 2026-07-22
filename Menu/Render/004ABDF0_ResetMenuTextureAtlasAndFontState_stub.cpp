#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABDF0
// Label: ResetMenuTextureAtlasAndFontState_stub
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetMenuTextureAtlasAndFontState_stub(void)

{
  int menuIndex;
  undefined4 *stateFlags;
  
  g_PalettedTextureAtlasAllocationFailCount = 0;
  stateFlags = (undefined4 *)&g_MenuTextureAtlasPixels;
  for (menuIndex = 0x8000; menuIndex != 0; menuIndex = menuIndex + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  menuIndex = 0;
  do {
    UpdateTexturesReference(menuIndex,0,0,0x100,0x100);
    menuIndex = menuIndex + 1;
  } while (menuIndex < 0xf);
  stateFlags = &g_PalettedTextureAtlasOccupancyGrid;
  for (menuIndex = 0x1e0; menuIndex != 0; menuIndex = menuIndex + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  return;
}

