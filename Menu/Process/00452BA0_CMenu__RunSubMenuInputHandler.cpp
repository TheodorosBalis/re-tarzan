#include "tarzan_ghidra_types.hpp"

// Address: 0x00452BA0
// Label: CMenu::RunSubMenuInputHandler
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::RunSubMenuInputHandler(int menu)

{
  int menuEntries;
  
  menuEntries = *(int *)(menu + 8);
  if ((menuEntries != 0) && (*(code **)(menuEntries + 0x1c) != (code *)0x0)) {
    (**(code **)(menuEntries + 0x1c))(menuEntries);
  }
  return;
}

