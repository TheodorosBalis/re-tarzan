#include "tarzan_ghidra_types.hpp"

// Address: 0x00444890
// Label: CreateLevelStartupEntities
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CreateLevelStartupEntities(void)

{
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\0') {
    JourneyToTheTreeHouse::SpawnAnimatedEffectEntity();
    return;
  }
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\x17') {
    ActivateLevelStartupRuntimeDescriptors();
    return;
  }
  return;
}

