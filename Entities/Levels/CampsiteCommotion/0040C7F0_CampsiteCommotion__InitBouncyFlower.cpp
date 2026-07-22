#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C7F0
// Label: CampsiteCommotion::InitBouncyFlower
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitBouncyFlower(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x200a;
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

