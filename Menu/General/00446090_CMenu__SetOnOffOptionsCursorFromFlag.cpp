#include "tarzan_ghidra_types.hpp"

// Address: 0x00446090
// Label: CMenu::SetOnOffOptionsCursorFromFlag
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SetOnOffOptionsCursorFromFlag(int menu)

{
  *(uint *)(menu + 0x24) = (uint)(_g_OnOffOptionsMenuCurrentValue == 0);
  return;
}

