#include "tarzan_ghidra_types.hpp"

// Address: 0x00448180
// Label: TriggerHudExtraLifeAward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TriggerHudExtraLifeAward(void)

{
  if (g_HudExtraLifeAwardScene != 0) {
    g_ExtraLifeAwardState = 1;
    return;
  }
  *( undefined1 *)((int)&g_LevelTransitionContext + 3) = *( undefined1 *)((int)&g_LevelTransitionContext + 3) + '\x01';
  if ('c' < *( undefined1 *)((int)&g_LevelTransitionContext + 3)) {
    *( undefined1 *)((int)&g_LevelTransitionContext + 3) = 'c';
  }
  return;
}

