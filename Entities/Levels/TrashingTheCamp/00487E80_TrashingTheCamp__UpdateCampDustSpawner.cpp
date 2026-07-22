#include "tarzan_ghidra_types.hpp"

// Address: 0x00487E80
// Label: TrashingTheCamp::UpdateCampDustSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateCampDustSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  int value;
  int value2;
  
  value2 = entity->sceneObjects;
  if (value2 != 0) {
    if (*(int *)(entry + 0x4c) == 0) {
      value = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y,
                         ((EntitySceneObject *)value2)->z,0xea,0x11);
      if ((value != 0) && (value = *(int *)(value + 0x38), value != 0)) {
        *(undefined4 *)(value + 0x10c) = 0x32;
        *(undefined4 *)(value + 0x110) = ((EntitySceneObject *)value2)->surfacePathIndex;
        *(undefined4 *)(value + 0x108) = 1;
        UpdateEntityEntitySceneObjectTransformFromPlacement(value);
        *(int *)(value + 0x14) = *(int *)(value + 0x14) + *(int *)(value + 0x54);
        *(int *)(value + 0x18) = *(int *)(value + 0x18) + *(int *)(value + 0x58);
        *(int *)(value + 0x1c) = *(int *)(value + 0x1c) + *(int *)(value + 0x5c);
      }
      value2 = RandomModulo(0x1e);
      *(int *)(entry + 0x4c) = &((EntitySceneObject *)value2)->x;
    }
    else {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

