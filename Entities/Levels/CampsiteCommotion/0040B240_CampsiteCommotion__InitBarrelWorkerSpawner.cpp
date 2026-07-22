#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B240
// Label: CampsiteCommotion::InitBarrelWorkerSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBarrelWorkerSpawner(undefined4 entry)

{
  int value;
  
  if (g_CampsiteCommotionBarrelWorkerSpawnerListHead == 0) {
    value = 0;
    do {
      CampsiteCommotion::SpawnBarrelWorkerVariant(value);
      value = value + 1;
    } while (value < 3);
  }
  CEntities::LinkEntityIntoProcessingList(&g_CampsiteCommotionBarrelWorkerSpawnerListHead,entry);
  return;
}

