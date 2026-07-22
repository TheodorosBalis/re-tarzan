#include "tarzan_ghidra_types.hpp"

// Address: 0x0049E860
// Label: SelectNextEnabledMenuItem
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int SelectNextEnabledMenuItem(int selectedIndex,int menuEntries)

{
  int *nextMenuItem;
  int menuItemId;
  int menuItem;
  int wrapPassesRemaining;
  
  if (selectedIndex < -1) {
    selectedIndex = -1;
  }
  wrapPassesRemaining = 1;
  do {
    selectedIndex = selectedIndex + 1;
    menuItem = menuEntries + selectedIndex * 8;
    menuItemId = *(int *)(menuEntries + selectedIndex * 8);
    while (menuItemId != 0) {
      if (*(short *)(menuItem + 4) != 1) {
        return selectedIndex;
      }
      nextMenuItem = (int *)(menuItem + 8);
      menuItem = menuItem + 8;
      selectedIndex = selectedIndex + 1;
      menuItemId = *nextMenuItem;
    }
    selectedIndex = -1;
    wrapPassesRemaining = wrapPassesRemaining + -1;
  } while (-1 < wrapPassesRemaining);
  return -1;
}

