#include "tarzan_ghidra_types.hpp"

// Address: 0x00451280
// Label: SaborAttacks::InitBreakableRewardProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitBreakableRewardProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  if (entity->descriptor != 0) {
    *(undefined4 *)(entry + 0x50) = *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4)
    ;
  }
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2009;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined4 *)(value + 0xb4) = 1;
  }
  *(undefined2 *)(entry + 0x4a) = 0;
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

