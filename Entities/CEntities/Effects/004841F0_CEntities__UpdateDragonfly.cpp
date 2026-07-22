#include "tarzan_ghidra_types.hpp"

// Address: 0x004841F0
// Label: CEntities::UpdateDragonfly
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateDragonfly(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  int value3;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value2 != 0) && (*(int *)(value2 + 0xc) == 0)) {
    value2 = *(int *)(entity->sceneObjects + 0x10c);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(entry,0x10);
    value = entity->sceneObjects;
    value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value3;
    value = *(int *)(entity->sceneObjects + 0x110);
    if (*(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value * 4) + 8 + value * 4 +
                g_CollisionSurfaceTable) + -0x200 <= value2) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  return;
}

