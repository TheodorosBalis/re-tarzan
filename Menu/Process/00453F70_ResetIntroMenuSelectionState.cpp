#include "tarzan_ghidra_types.hpp"

// Address: 0x00453F70
// Label: ResetIntroMenuSelectionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetIntroMenuSelectionState(void)

{
  *( undefined1 *)((int)&g_LevelTransitionContext + 1) = 1;
  *( undefined1 *)((int)&g_LevelTransitionContext + 0) = 0;
  g_LoadGameProfileIndex = 2;
  g_SelectedLevelIndex = 0xff;
  g_IntroMenuStartFlag = 0;
  return;
}

