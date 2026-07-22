#include "tarzan_ghidra_types.hpp"

// Address: 0x00428120
// Label: ElephantHairDare::UpdateGroundCollapseDebris
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateGroundCollapseDebris(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  
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
                         ((EntitySceneObject *)value)->z,0x7d,0x11);
      if (value != 0) {
        value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
        if (value2 != 0) {
          *(int *)(value2 + 0xc) = value;
        }
        value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
        if (value != 0) {
          ((EntitySceneObject *)value)->x = 0x2800;
        }
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      }
    }
  }
  return;
}

