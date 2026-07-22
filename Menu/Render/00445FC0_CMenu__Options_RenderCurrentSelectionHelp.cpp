#include "tarzan_ghidra_types.hpp"

// Address: 0x00445FC0
// Label: CMenu::Options_RenderCurrentSelectionHelp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::Options_RenderCurrentSelectionHelp(undefined4 menu)

{
  RenderMenuUiBlockEntry
            (&DAT_004ef634,&DAT_00533bd8,2,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderSelectedMenuEntryTextThunk(menu);
  return;
}

