#include "tarzan_ghidra_types.hpp"

// Address: 0x00426460
// Label: ElephantHairDare::UpdateMonkeySpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateMonkeySpawner(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  value3 = entity->sceneObjects;
  if ((value3 != 0) &&
     (value2 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value2, value2 < 0)) {
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                       ((EntitySceneObject *)value3)->z,0x6a,0x11);
    if (value2 != 0) {
      *(ushort *)(value2 + 0x4a) = *(ushort *)(value2 + 0x4a) | 0x480;
      if (entity->descriptor != 0) {
        if ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 1) != 0) {
          *(ushort *)(value2 + 0x4a) = *(ushort *)(value2 + 0x4a) | 0x200;
        }
        if ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 2) != 0) {
          *(byte *)(value2 + 0x4b) = *(byte *)(value2 + 0x4b) | 8;
        }
      }
      value = *(int *)(value2 + 0x38);
      if (value == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)value2);
      }
      else {
        *(undefined4 *)(value + 0x108) = 1;
        *(undefined4 *)(value + 0x110) = ((EntitySceneObject *)value3)->surfacePathIndex;
        *(undefined4 *)(value + 0x10c) = ((EntitySceneObject *)value3)->surfaceIndex;
        if ((entity->descriptor != 0) &&
           ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 2) & 0x20) != 0)) {
          *(undefined4 *)(value + 0x10c) = 0x10;
        }
        UpdateEntityEntitySceneObjectTransformFromPlacement(value);
        CEntities::RefreshAnimalFacingAndCollisionAfterTurn(value2,value);
      }
    }
    value3 = RandomModulo(*(int *)(entry + 0x50) - *(int *)(entry + 0x4c));
    *(uint *)(entry + 0x4c) = value3 + (uint)*(ushort *)(entry + 0x4a);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

