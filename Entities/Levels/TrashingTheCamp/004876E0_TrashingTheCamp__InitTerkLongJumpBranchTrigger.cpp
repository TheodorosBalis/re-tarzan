#include "tarzan_ghidra_types.hpp"

// Address: 0x004876E0
// Label: TrashingTheCamp::InitTerkLongJumpBranchTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitTerkLongJumpBranchTrigger(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = entity->sceneObjects;
  *(uint *)(entry + 0x28) = *(uint *)(entry + 0x28) ^ 3;
  value2 = g_CurrentWorldSceneContext;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2018;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->pitch = 0xff01;
  }
  CEntities::LinkEntityIntoProcessingList(&g_CollisionTriggerEntryListHead,entry);
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

