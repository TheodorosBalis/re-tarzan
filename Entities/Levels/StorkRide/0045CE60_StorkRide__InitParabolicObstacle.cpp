#include "tarzan_ghidra_types.hpp"

// Address: 0x0045CE60
// Label: StorkRide::InitParabolicObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StorkRide::InitParabolicObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = entity->sceneObjects;
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x1fb0;
  *(undefined2 *)(value + 0xc) = 0;
  value = CEntities::CreateEntityAttachment(entry,0x4c,0x10000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 5;
  }
  value = CEntities::CreateEntityAttachment(entry,0x60,0x20000000);
  if (value != 0) {
    *(undefined4 *)(value + 0xc) = 2;
    ((EntitySceneObject *)value)->x = 0x100;
    ((EntitySceneObject *)value)->worldObject = 0;
    *(undefined4 *)(value + 0x28) = 0;
    *(undefined4 *)(value + 0x2c) = 1;
    *(undefined4 *)(value + 0x30) = 0;
    ((EntitySceneObject *)value)->next = 0;
  }
  CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
  ((EntitySceneObject *)value)->worldObject = 0;
  *(undefined4 *)(value + 0x20) = 0;
  return;
}

