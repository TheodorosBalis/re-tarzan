#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E2E0
// Label: JourneyToTheTreeHouse::UpdateRewardFlowerPetal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateRewardFlowerPetal(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  
  value = entity->sceneObjects;
  *(short *)(entry + 0x4a) = *(short *)(entry + 0x4a) + 6;
  value2 = *(int *)(value + 0xb0) + -0x24;
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + (uint)*(ushort *)(entry + 0x4a);
  *(int *)(value + 0xb0) = value2;
  *(int *)(value + 0xac) = value2;
  *(int *)(value + 0xa8) = value2;
  if (199 < value2) {
    *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + *(short *)(entry + 0x50);
    ((EntitySceneObject *)value)->pitch = ((EntitySceneObject *)value)->pitch + *(short *)(entry + 0x4c);
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag == '\0') {
      return;
    }
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

