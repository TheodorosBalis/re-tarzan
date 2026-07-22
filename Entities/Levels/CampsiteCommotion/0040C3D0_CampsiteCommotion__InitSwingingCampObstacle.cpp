#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C3D0
// Label: CampsiteCommotion::InitSwingingCampObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitSwingingCampObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  undefined4 value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    if (entity->descriptor != 0) {
      *(undefined4 *)(entry + 0x4c) =
           *(undefined4 *)(*(int *)(entity->descriptor + 0x10) + 4);
    }
    value2 = g_CurrentWorldSceneContext;
    ((EntitySceneObject *)value)->roll = 1;
    ((EntitySceneObject *)value)->worldObject = value2;
    *(undefined2 *)(value + 0xc) = 0x200c;
  }
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

