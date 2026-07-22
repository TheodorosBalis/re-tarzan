#include "tarzan_ghidra_types.hpp"

// Address: 0x00452CD0
// Label: RenderSelectedMenuEntryText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderSelectedMenuEntryText(int *menu)

{
  int *menuEntry;
  int menuIndex;
  int menuIndex2;
  
  menuEntry = (int *)(menu[2] + menu[9] * 0x18);
  menuIndex = menuEntry[1];
  if ((-1 < menuIndex) && (menuIndex2 = *menuEntry, menuIndex2 != 0)) {
    RenderMenuUiBlockEntry
              (menuIndex2 + 4,&DAT_00533bd8,menuIndex,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  }
  ReleasePalettedTextureBlockIfUnused(*menu + 4,2);
  return;
}

