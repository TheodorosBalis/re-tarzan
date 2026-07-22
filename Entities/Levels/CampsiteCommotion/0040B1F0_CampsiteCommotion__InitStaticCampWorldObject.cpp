#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B1F0
// Label: CampsiteCommotion::InitStaticCampWorldObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitStaticCampWorldObject(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value2 = g_CurrentWorldSceneContext;
  value = entity->sceneObjects;
  if (value != 0) {
    *(undefined2 *)(value + 0xc) = 0x2009;
    ((EntitySceneObject *)value)->worldObject = value2;
    ((EntitySceneObject *)value)->roll = 2;
    *(undefined2 *)(value + 0xe) = 0;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

