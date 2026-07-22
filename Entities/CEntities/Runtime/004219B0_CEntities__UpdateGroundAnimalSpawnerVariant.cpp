#include "tarzan_ghidra_types.hpp"

// Address: 0x004219B0
// Label: CEntities::UpdateGroundAnimalSpawnerVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateGroundAnimalSpawnerVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  
  if ((_g_PlayerHeroMode == 2) && ((g_PlayerActionState == 0x28 || (g_PlayerActionState == 0x25))))
  {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  value3 = entity->sceneObjects;
  if ((value3 != 0) &&
     (value2 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value2, value2 < 0)) {
    value2 = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                       ((EntitySceneObject *)value3)->z,0x1c2,0x11);
    if (value2 != 0) {
      value = *(int *)(value2 + 0x38);
      *(byte *)(value2 + 0x4b) = *(byte *)(value2 + 0x4b) | 2;
      if (value == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)value2);
      }
      else {
        *(undefined4 *)(value + 0x108) = 1;
        *(undefined4 *)(value + 0x10c) = ((EntitySceneObject *)value3)->surfaceIndex;
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

