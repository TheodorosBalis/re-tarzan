#include "tarzan_ghidra_types.hpp"

// Address: 0x00483840
// Label: CEntities::UpdateLeafSwimmingFishSplashDroplet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateLeafSwimmingFishSplashDroplet(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    *(int *)(entity->sceneObjects + 0x18) = *(int *)(entity->sceneObjects + 0x18) + -8;
    value = entity->sceneObjects;
    if (((EntitySceneObject *)value)->y < ((EntitySceneObject *)value2)->worldObject) {
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,((EntitySceneObject *)value)->z,
                 0x193,0x11);
      value2 = entity->sceneObjects;
      CEntities::SpawnEntityByTypeAtPosition
                (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y,
                 ((EntitySceneObject *)value2)->z,0x195,0x11);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  return;
}

