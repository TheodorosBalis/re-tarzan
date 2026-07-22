#include "tarzan_ghidra_types.hpp"

// Address: 0x004444E0
// Label: ResetRespawnRuntimeListsAndEntries
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetRespawnRuntimeListsAndEntries(void)

{
  _g_RuntimeProcessingPhase = 0;
  _g_RespawnRuntimeResetState = 0;
  g_ActiveSwingEntityList = 0;
  g_DormantPhase2EntityListHead = 0;
  g_ActiveThrowableEntityList = 0;
  g_ActiveEntityListHead = 0;
  g_ScriptedEnemyEntityListHead = 0;
  ReleaseActiveEntitiesToFreeList();
  return;
}

