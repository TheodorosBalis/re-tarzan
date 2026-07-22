#include "tarzan_ghidra_types.hpp"

// Address: 0x004332D0
// Label: RespawnAndReinitializeGameplayWorld
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RespawnAndReinitializeGameplayWorld(void)

{
  g_HudCollectedTARZANslotSlideTicks = 0x78;
  g_HudCollectedSketchSlideTicks = 0x78;
  _g_GameplayRespawnSceneState = 0x78;
  ResetRespawnRuntimeListsAndEntries();
  RebuildLoadedWorldSceneState();
  ResetGameplayRuntimeState();
  RefreshGameplaySceneCallbacks();
  return;
}

