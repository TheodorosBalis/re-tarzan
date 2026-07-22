#include "tarzan_ghidra_types.hpp"

// Address: 0x00445EA0
// Label: CMenu::SetOptionsCursorFromLevelMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::SetOptionsCursorFromLevelMode(int menu)

{
  *(int *)(menu + 0x24) = (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1) % 3;
  return;
}

