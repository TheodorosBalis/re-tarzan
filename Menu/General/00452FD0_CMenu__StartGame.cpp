#include "tarzan_ghidra_types.hpp"

// Address: 0x00452FD0
// Label: CMenu::StartGame
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::StartGame(void)

{
  InitiateFade(2,0x100);
  *( undefined1 *)((int)&g_LevelTransitionContext + 3) =
       (&g_LevelTransitionTypeBySlot)[*( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2];
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0;
  gCurrentTokensCollected = 0;
  g_SelectedLevelIndex = 0;
  ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  return;
}

