#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CC60
// Label: CampsiteCommotion::SpawnFallingBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::SpawnFallingBox(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  uint value2;
  int value;
  uint value3;
  
  value = entity->sceneObjects;
  if ((value != 0) && (((EntitySceneObject *)value)->surfacePathIndex == *(int *)(g_PlayerEntitySceneObject + 0x110))) {
    value2 = ((EntitySceneObject *)value)->surfaceIndex - *(int *)(g_PlayerEntitySceneObject + 0x10c);
    value3 = (int)value2 >> 0x1f;
    if ((int)((value2 ^ value3) - value3) < 2000) {
      if (*(int *)(entry + 0x4c) == 0) {
        value = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                           ((EntitySceneObject *)value)->z,0x119,0x11);
        if (value != 0) {
          *(undefined4 *)(entry + 0x4c) = 0x78;
        }
      }
      else {
        *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      }
    }
    else {
      *(undefined4 *)(entry + 0x4c) = 0x1e;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

