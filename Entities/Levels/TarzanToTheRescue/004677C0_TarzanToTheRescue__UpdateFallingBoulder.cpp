#include "tarzan_ghidra_types.hpp"

// Address: 0x004677C0
// Label: TarzanToTheRescue::UpdateFallingBoulder
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateFallingBoulder(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    if (-0x10 < *(int *)(value2 + 0x44)) {
      CEntities::AdvanceBounceMotionAndReturnImpact(entity->sceneObjects,value2 + 0x24);
      value = *(int *)(value2 + 0x14);
      *(int *)(value2 + 0x14) = value + -1;
      if (value < 0) {
        value = entity->sceneObjects;
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                   ((EntitySceneObject *)value)->z,0x174,0x11);
        *(undefined4 *)(value2 + 0x14) = 3;
      }
    }
    value2 = *(int *)(value2 + 0x10);
    if (value2 != 0) {
      value = entity->sceneObjects;
      *(undefined4 *)(value2 + 0x14) = ((EntitySceneObject *)value)->x;
      *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value)->y;
      *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value)->z;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

