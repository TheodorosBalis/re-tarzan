#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EB00
// Label: SaborAttacks::InitShakeTriggeredProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::InitShakeTriggeredProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = g_WorldEntitySceneObjectArrayBase;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2010;
    *(undefined4 *)(value + 0xb4) = 1;
    ((EntitySceneObject *)value)->worldObject = value2 + 0x1178;
  }
  *(undefined2 *)(entry + 0x4a) = 0;
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

