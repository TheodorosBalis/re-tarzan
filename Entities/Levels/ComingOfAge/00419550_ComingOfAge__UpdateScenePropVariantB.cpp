#include "tarzan_ghidra_types.hpp"

// Address: 0x00419550
// Label: ComingOfAge::UpdateScenePropVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ComingOfAge::UpdateScenePropVariantB(int entry4)

{
  Entity *entity = (Entity *)entry4;
  int entry;
  char resultFlag;
  int entry2;
  int entry3;
  
  if ((_g_PlayerHeroMode == 2) && ((g_PlayerActionState == 0x28 || (g_PlayerActionState == 0x25))))
  {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry4);
    return;
  }
  entry3 = entity->sceneObjects;
  if ((entry3 != 0) &&
     (entry2 = *(int *)(entry4 + 0x4c) + -1, *(int *)(entry4 + 0x4c) = entry2, entry2 < 0)) {
    entry2 = CEntities::SpawnEntityByTypeAtPosition
                      (((EntitySceneObject *)entry3)->x,((EntitySceneObject *)entry3)->y,
                       ((EntitySceneObject *)entry3)->z,0x1dd,0x11);
    if (entry2 != 0) {
      entry = *(int *)(entry2 + 0x38);
      *(byte *)(entry2 + 0x4b) = *(byte *)(entry2 + 0x4b) | 2;
      if (entry == 0) {
        CEntities::ReleaseEntityToFreeList((byte *)entry2);
      }
      else {
        *(undefined4 *)(entry + 0x108) = 1;
        *(undefined4 *)(entry + 0x10c) = ((EntitySceneObject *)entry3)->surfaceIndex;
        *(undefined4 *)(entry + 0x110) = ((EntitySceneObject *)entry3)->surfacePathIndex;
        *(undefined4 *)(entry + 0x10c) = ((EntitySceneObject *)entry3)->surfaceIndex;
        if ((entity->descriptor != 0) &&
           ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 2) & 0x20) != 0)) {
          *(undefined4 *)(entry + 0x10c) = 0x10;
        }
        UpdateEntityEntitySceneObjectTransformFromPlacement(entry);
        CEntities::RefreshAnimalFacingAndCollisionAfterTurn(entry2,entry);
      }
    }
    entry3 = RandomModulo(*(int *)(entry4 + 0x50) - *(int *)(entry4 + 0x4c));
    *(uint *)(entry4 + 0x4c) = entry3 + (uint)*(ushort *)(entry4 + 0x4a);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry4);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry4);
  }
  return;
}

