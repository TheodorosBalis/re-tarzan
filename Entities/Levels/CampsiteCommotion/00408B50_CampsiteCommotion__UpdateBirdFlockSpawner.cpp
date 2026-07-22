#include "tarzan_ghidra_types.hpp"

// Address: 0x00408B50
// Label: CampsiteCommotion::UpdateBirdFlockSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBirdFlockSpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  char resultFlag;
  uint value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value2 = *(int *)(entry + 0x18);
    value3 = *(int *)(entry + 0x4c) + 0x10U & 0xfff;
    *(uint *)(entry + 0x4c) = value3;
    shortValue = (&g_SinCosTable12Bit)[value3 - 0x400 & 0xfff];
    for (; value2 != 0; value2 = *(int *)(value2 + 0x18)) {
      if (*(int *)(value2 + 0x38) != 0) {
        *(int *)(*(int *)(value2 + 0x38) + 0x18) =
             ((EntitySceneObject *)value)->y - (shortValue * 0x100 + 0x380 >> 0xc);
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

