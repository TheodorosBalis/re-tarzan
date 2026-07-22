#include "tarzan_ghidra_types.hpp"

// Address: 0x0047F1C0
// Label: SetMenuIdleScriptOverride
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetMenuIdleScriptOverride(int menu,undefined4 menuItem)

{
  *(undefined4 *)(menu + 4) = menuItem;
  return;
}

