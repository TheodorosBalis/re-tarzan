#include "tarzan_ghidra_types.hpp"

// Address: 0x00452DD0
// Label: CMenu::RenderMainMenuFontOnly
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::RenderMainMenuFontOnly(void)

{
  RenderMenuUiBlockEntry
            (g_MainMenuMainFontMenuEntry + 4,&DAT_00533bd8,_g_MainMenuMainFontMenuEntryId,
             *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  return;
}

