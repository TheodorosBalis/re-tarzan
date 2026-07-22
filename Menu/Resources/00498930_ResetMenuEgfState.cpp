#include "tarzan_ghidra_types.hpp"

// Address: 0x00498930
// Label: ResetMenuEgfState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetMenuEgfState(void)

{
  int menuIndex;
  undefined4 *stateFlags;
  
  if (g_MenuEgfHandle != 0) {
    CloseVirtualGameFileHandle(g_MenuEgfHandle);
  }
  stateFlags = &g_MenuEgfHeader;
  for (menuIndex = 0x12; menuIndex != 0; menuIndex = menuIndex + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  stateFlags = &g_MenuEgfChunkOffsets;
  for (menuIndex = 0x10; menuIndex != 0; menuIndex = menuIndex + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  g_MenuEgfHandle = 0;
  g_MenuEgfChunkCount = 0;
  return;
}

