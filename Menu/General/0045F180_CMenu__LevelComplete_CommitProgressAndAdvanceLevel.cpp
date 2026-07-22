#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F180
// Label: CMenu::LevelComplete_CommitProgressAndAdvanceLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_CommitProgressAndAdvanceLevel(void)

{
  byte flagByte;
  
  *( undefined1 *)((int)&g_LevelTransitionContext + 3) =
       *( undefined1 *)((int)&g_LevelTransitionContext + 3) + (char)(gCurrentTokensCollected / 100);
  gCurrentTokensCollected = gCurrentTokensCollected + (short)(gCurrentTokensCollected / 100) * -100;
  if ((g_CollectedTARZANLetterMask6 & 0x3f) == 0x3f) {
    *(byte *)((int)&g_RuntimeCompletionFlagsByLevel + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 2)) =
         *(byte *)((int)&g_RuntimeCompletionFlagsByLevel + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 2)) |
         '\x01' << (*( undefined1 *)((int)&g_LevelTransitionContext + 1) & 0x1f);
  }
  flagByte = g_SelectedLevelIndex + 1;
  if (((flagByte & 1) != 0) && ((g_CollectedSketchPieceMask4 & 0xf) != 0xf)) {
    g_SelectedLevelIndex = g_SelectedLevelIndex + 2;
    flagByte = g_SelectedLevelIndex;
  }
  g_SelectedLevelIndex = flagByte;
  return;
}

