#include "tarzan_ghidra_types.hpp"

// Address: 0x00453DA0
// Label: ResetIntroGameplayState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetIntroGameplayState(void)

{
  *( undefined1 *)((int)&g_LevelTransitionContext + 2) = 0;
  g_GameplayRuntimeFlags = 0;
  g_CurrentCheckpointId = 0;
  *( undefined1 *)((int)&g_LevelTransitionContext + 1) = 1;
  *( undefined1 *)((int)&g_LevelTransitionContext + 3) = g_DefaultPlayerLives;
  g_AllSketchPiecesNewlyCompleted = 0;
  *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0;
  g_SelectedLevelIndex = 0xff;
  gCurrentTokensCollected = 0;
  g_TextLayoutScreenWidth = 0x200;
  *( undefined2 *)((int)&g_GameplayStateFlags + 0) = 0;
  g_BcdTimerTicksPerSecond = 0x3c;
  return;
}

