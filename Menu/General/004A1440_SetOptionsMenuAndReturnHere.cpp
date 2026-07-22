#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1440
// Label: SetOptionsMenuAndReturnHere
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetOptionsMenuAndReturnHere(int menu)

{
  int menuIndex;
  
  menuIndex = ResolveOptionsMenuHandlerById(menu);
  if ((menuIndex != -1) && (menu != g_ActiveOptionsMenuId)) {
    bIsPaused = 1;
    g_PendingOptionsMenuId = menu;
    g_ReturnOptionsMenuId = g_ActiveOptionsMenuId;
  }
  return;
}

