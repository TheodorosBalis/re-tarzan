#include "tarzan_ghidra_types.hpp"

// Address: 0x00444400
// Label: ResetLevelRuntimeState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetLevelRuntimeState(void)

{
  _g_RuntimeProcessingPhase = 0;
  g_RuntimeDescriptorArray = 0;
  _g_RespawnRuntimeResetState = 0;
  g_ActiveSwingEntityList = 0;
  g_DormantPhase2EntityListHead = 0;
  g_ActiveThrowableEntityList = 0;
  _g_LevelRuntimeResetState = 0;
  g_LevelEnemyEntityListHead = 0;
  g_ScriptedEnemyEntityListHead = 0;
  _g_BreakableRewardSpawnCounter0 = 0;
  _g_BreakableRewardSpawnCounter1 = 0;
  _g_BreakableRewardSpawnCounter2 = 0;
  _g_BreakableRewardSpawnCounter3 = 0;
  _g_ComingOfAgeBananaTreeRewardIndex0 = 0;
  _g_ComingOfAgeBananaTreeRewardIndex1 = 0;
  _g_ComingOfAgeBananaTreeRewardIndex2 = 0;
  _g_ComingOfAgeBananaTreeRewardIndex3 = 0;
  BuildLevelRuntimeDescriptors();
  CEntities::ResetEntityPoolSlotsToTemplate();
  CEntities::InitializeEntityPoolAndLists();
  return;
}

