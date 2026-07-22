#include "tarzan_ghidra_types.hpp"

// Address: 0x004821A0
// Label: CEntities::UpdateMovingWaterSplashDroplet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateMovingWaterSplashDroplet(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x20000000);
  if (value != 0) {
    *(int *)(entity->sceneObjects + 0x14) =
         *(int *)(entity->sceneObjects + 0x14) - (*(int *)(value + 0x30) * 10 >> 0xc);
    *(int *)(entity->sceneObjects + 0x1c) =
         *(int *)(entity->sceneObjects + 0x1c) - (((EntitySceneObject *)value)->next * 10 >> 0xc);
    value = CEntities::UpdateParabolicSceneObjectMotionAttachment(entry);
    if (value != 0) {
      value = entity->sceneObjects;
      value = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                         ((EntitySceneObject *)value)->z,0x193,0x11);
      if (value != 0) {
        value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
        if (value != 0) {
          ((EntitySceneObject *)value)->worldObject = 0x2800;
        }
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      }
    }
  }
  return;
}

