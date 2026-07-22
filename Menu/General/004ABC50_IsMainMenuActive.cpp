#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABC50
// Label: IsMainMenuActive
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 IsMainMenuActive(void)

{
  if ((*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\x16') && (g_CurrentMenu == &g_MainMenuMainFontMenuEntry))
  {
    return 1;
  }
  return 0;
}

