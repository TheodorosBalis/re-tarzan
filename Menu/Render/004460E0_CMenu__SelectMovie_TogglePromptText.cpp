#include "tarzan_ghidra_types.hpp"

// Address: 0x004460E0
// Label: CMenu::SelectMovie_TogglePromptText
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::SelectMovie_TogglePromptText(int menu)

{
  *(uint *)(menu + 0x18) = (*(int *)(menu + 0x18) != 0x80b3) + 0x80b2;
  TimeIDLEinMenu = 0;
  return;
}

