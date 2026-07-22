#include "tarzan_ghidra_types.hpp"

// Address: 0x00453040
// Label: RenderMainMenuSelectionsText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderMainMenuSelectionsText(undefined4 menu)

{
  RenderSelectedMenuEntryText(menu);
  RenderMenuUiBlockEntry(0x4f1e4c,&DAT_00533bd8,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4f1e6c,&DAT_00533bd8,1,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  return;
}

