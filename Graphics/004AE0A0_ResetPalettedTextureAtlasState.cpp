#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE0A0
// Label: ResetPalettedTextureAtlasState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetPalettedTextureAtlasState(void)

{
  int value;
  undefined4 *stateFlags;
  
  g_PalettedTextureAtlasAllocationFailCount = 0;
  stateFlags = (undefined4 *)&g_MenuTextureAtlasPixels;
  for (value = 0x8000; value != 0; value = value + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  value = 0;
  do {
    UpdateTexturesReference(value,0,0,0x100,0x100);
    value = value + 1;
  } while (value < 0xf);
  stateFlags = &g_PalettedTextureAtlasOccupancyGrid;
  for (value = 0x1e0; value != 0; value = value + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  return;
}

