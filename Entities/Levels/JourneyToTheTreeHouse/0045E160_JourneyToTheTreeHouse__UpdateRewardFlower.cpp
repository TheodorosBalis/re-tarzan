#include "tarzan_ghidra_types.hpp"

// Address: 0x0045E160
// Label: JourneyToTheTreeHouse::UpdateRewardFlower
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateRewardFlower(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined2 *dataCursor;
  
  value = entity->sceneObjects;
  value5 = (*(byte *)(entry + 0x3d) - 6) * 0x18;
  if ((*(short *)(entry + 0x48) == 0) && ((*(byte *)(entry + 0x42) & 0x80) != 0)) {
    *(undefined2 *)(entry + 0x48) = 1;
    PlayAudioById(0x2f1,0,(undefined4 *)(&((EntitySceneObject *)value)->x));
    *(undefined2 *)(value + 0xc) = *(undefined2 *)(&DAT_00505026 + value5);
    value2 = ResolveCollisionSurfaceIndexByCoordRef
                      (*(undefined4 *)(&g_JourneyToTheTreeHouseRewardFlowerConfigTable + value5));
    value4 = g_CollisionSurfaceTable + 4;
    value3 = ResolveCollisionSurfaceIndexByCoordRef
                      (*(undefined4 *)(&g_JourneyToTheTreeHouseRewardFlowerConfigTable + value5));
    value4 = *(int *)(value4 + value2 * 4) + 4 + value3 * 4 + g_CollisionSurfaceTable;
    *(uint *)(value4 + *(int *)(&DAT_0050501c + value5) * 0x1c + 0x44) =
         *(uint *)(value4 + 0x44 + *(int *)(&DAT_0050501c + value5) * 0x1c) | 0x100;
    CEntities::UnlinkEntityFromProcessingList(entry);
    dataCursor = &DAT_00505094;
    do {
      value5 = CEntities::SpawnEntityByTypeAtPosition
                        (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                         ((EntitySceneObject *)value)->z,0x13c,0x11);
      if (value5 != 0) {
        *(undefined2 *)(*(int *)(value5 + 0x38) + 0xc) = dataCursor[-2];
        *(undefined2 *)(value5 + 0x4a) = *dataCursor;
      }
      dataCursor = dataCursor + 4;
    } while ((int)dataCursor < 0x5050c4);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

