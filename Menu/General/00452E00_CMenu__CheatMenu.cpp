#include "tarzan_ghidra_types.hpp"

// Address: 0x00452E00
// Label: CMenu::CheatMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::CheatMenu(void)

{
  CMenu::CheatMenu_UpdateLevelSelect();
  if ((g_InputCurrentMask & g_InputEdgeMask & 1) != 0) {
    CMenu::RequestMenuChangeWithFade(&g_MainMenuMainFontMenuEntry);
  }
  return;
}

