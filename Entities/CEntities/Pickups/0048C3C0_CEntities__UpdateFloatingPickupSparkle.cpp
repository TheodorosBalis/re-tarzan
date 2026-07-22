#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C3C0
// Label: CEntities::UpdateFloatingPickupSparkle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateFloatingPickupSparkle(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if (value != 0) {
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y - *(int *)(entry + 0x4c);
    *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -5;
    value2 = *(int *)(value + 0xa8) - *(int *)(entry + 0x50);
    *(int *)(value + 0xa8) = value2;
    *(int *)(value + 0xac) = value2;
    *(int *)(value + 0xb0) = value2;
    if (value2 < 0x101) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

