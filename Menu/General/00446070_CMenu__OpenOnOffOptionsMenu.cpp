#include "tarzan_ghidra_types.hpp"

// Address: 0x00446070
// Label: CMenu::OpenOnOffOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::OpenOnOffOptionsMenu(undefined4 menu)

{
  _g_OnOffOptionsMenuCurrentValue = menu;
  CMenu::Options(&PTR_Options_OptionsSelections_004f0188);
  return;
}

