#include "tarzan_ghidra_types.hpp"

// Address: 0x004169C0
// Label: ComingOfAge::InitBreakableTreeProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::InitBreakableTreeProp(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x200f;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 1;
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveEntityListHead,entry);
  g_EntityHitResponseScratch = 0;
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

