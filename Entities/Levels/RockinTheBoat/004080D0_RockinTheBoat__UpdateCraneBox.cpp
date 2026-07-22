#include "tarzan_ghidra_types.hpp"

// Address: 0x004080D0
// Label: RockinTheBoat::UpdateCraneBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateCraneBox(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  
  value = entity->sceneObjects;
  if ((value != 0) && (*( undefined1 *)((int)&g_RockinTheBoatDeckSurfaceA + 2) != '\0')) {
    *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x80;
    if (*(short *)(entry + 0x4a) == 1) {
      if (((EntitySceneObject *)value)->surfacePathIndex == *(int *)(g_PlayerEntitySceneObject + 0x110)) {
        *(undefined2 *)(entry + 0x4a) = 2;
      }
    }
    else {
      value2 = ((EntitySceneObject *)value)->y + -0x14;
      ((EntitySceneObject *)value)->y = value2;
      if (value2 < -0xb00) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

