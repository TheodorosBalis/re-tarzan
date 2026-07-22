#include "tarzan_ghidra_types.hpp"

// Address: 0x00452A60
// Label: BuildMainMenuSelections
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BuildMainMenuSelections(void)

{
  LoadMenuGraphicBlock(&MainMenu_MainFont);
  LoadMenuGraphicBlock(&MainMenu_Selections);
  LoadMenuGraphicBlock(&MainMenu_ExitGame);
  return;
}

