#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E950
// Label: SetOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetOptionsMenu(int menu)

{
  int menuIndex;
  
  menuIndex = ResolveOptionsMenuHandlerById(menu);
  if ((menuIndex != -1) && (menu != g_ActiveOptionsMenuId)) {
    bIsPaused = 1;
    g_PendingOptionsMenuId = menu;
    g_ReturnOptionsMenuId = 0;
  }
  return;
}

