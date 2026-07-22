#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E800
// Label: SelectPreviousEnabledMenuItem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int SelectPreviousEnabledMenuItem(int selectedIndex,int *menuEntries)

{
  int menuItemId;
  int lastEnabledIndex;
  int *menuItem;
  int scannedIndex;
  
  selectedIndex = selectedIndex + -1;
  if (-1 < selectedIndex) {
    menuItem = menuEntries + selectedIndex * 2;
    do {
      if (*menuItem == 0) break;
      if ((short)menuItem[1] != 1) {
        return selectedIndex;
      }
      selectedIndex = selectedIndex + -1;
      menuItem = menuItem + -2;
    } while (-1 < selectedIndex);
  }
  scannedIndex = 0;
  lastEnabledIndex = 0;
  menuItemId = *menuEntries;
  while (menuItemId != 0) {
    if ((short)menuEntries[1] != 1) {
      lastEnabledIndex = scannedIndex;
    }
    menuItem = menuEntries + 2;
    menuEntries = menuEntries + 2;
    scannedIndex = scannedIndex + 1;
    menuItemId = *menuItem;
  }
  return lastEnabledIndex;
}

