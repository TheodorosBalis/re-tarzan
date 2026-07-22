#include "tarzan_ghidra_types.hpp"

// Address: 0x0047F1D0
// Label: InitMenuIdleScriptCursor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitMenuIdleScriptCursor(undefined4 *menu,undefined4 menuItem)

{
  *menu = menuItem;
  menu[1] = 0;
  return;
}

