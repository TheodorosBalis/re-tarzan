#include "tarzan_ghidra_types.hpp"

// Address: 0x00452A90
// Label: RemoveMainMenuSelections
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RemoveMainMenuSelections(void)

{
  HideMenuGraphicBlock(&MainMenu_MainFont);
  HideMenuGraphicBlock(&MainMenu_Selections);
  HideMenuGraphicBlock(&MainMenu_ExitGame);
  return;
}

