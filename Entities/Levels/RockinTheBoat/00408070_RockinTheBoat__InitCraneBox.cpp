#include "tarzan_ghidra_types.hpp"

// Address: 0x00408070
// Label: RockinTheBoat::InitCraneBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitCraneBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(entry + 0x4a) = 1;
    *(undefined2 *)(value + 0xc) = 0x2011;
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
    value2 = g_CurrentWorldSceneContext;
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 8;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->yaw = 0x400;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

