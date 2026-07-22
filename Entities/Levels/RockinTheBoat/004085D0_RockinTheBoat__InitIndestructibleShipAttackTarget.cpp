#include "tarzan_ghidra_types.hpp"

// Address: 0x004085D0
// Label: RockinTheBoat::InitIndestructibleShipAttackTarget
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::InitIndestructibleShipAttackTarget(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->worldObject = g_CurrentWorldSceneContext;
    *(undefined2 *)(value + 0xc) = 0x5087;
    ((EntitySceneObject *)value)->roll = 1;
    CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

