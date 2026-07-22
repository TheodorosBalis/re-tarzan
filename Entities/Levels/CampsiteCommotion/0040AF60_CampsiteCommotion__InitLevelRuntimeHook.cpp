#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AF60
// Label: CampsiteCommotion::InitLevelRuntimeHook
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitLevelRuntimeHook(void)

{
  PlayAudioById(200,(int *)0,(undefined4 *)0);
  CEntities::ResetRandomAmbientSoundCountdown();
  g_CampsiteCommotionWorkerEnemyListHead = 0;
  g_CampsiteCommotionBarrelWorkerSurfaceIndex = FindCollisionSurfaceIndexByCoordRef(0x58);
  g_CampsiteCommotionBarrelWorkerSpawnerListHead = 0;
  g_CampsiteCommotionFallingDebrisModelIndex = 0;
  return;
}

