#include "tarzan_ghidra_types.hpp"

// Address: 0x00445E80
// Label: CMenu::OpenOptionsWithLevelMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::OpenOptionsWithLevelMode(undefined1 menu)

{
  *( undefined1 *)((int)&g_LevelTransitionContext + 1) = menu;
  CMenu::Options(&PTR_Options_OptionsSelections_004f0210);
  return;
}

