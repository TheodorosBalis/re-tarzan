#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CA10
// Label: CampsiteCommotion::UpdateMovingBoxWithPushers
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateMovingBoxWithPushers(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    value3 = (int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks - 0x40 & 0xff) * 0x10] +
            (int)(short)(&g_SinCosTable12Bit)[(TotalGameLoopTicks & 0x1ff) * 8] >> 7;
    ((EntitySceneObject *)value)->x =
         (g_LevelEntityInitScratch_Field186C * value3 >> 0xc) + *(int *)(value + 0x48);
    ((EntitySceneObject *)value)->z =
         (g_LevelEntityInitScratch_Field106C * value3 >> 0xc) + *(int *)(value + 0x50);
    for (value3 = *(int *)(entry + 0x18); value3 != 0; value3 = *(int *)(value3 + 0x18)) {
      value2 = *(int *)(value3 + 0x38);
      if (value2 != 0) {
        *(int *)(value2 + 0x14) = ((EntitySceneObject *)value)->x;
        *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value)->y;
        *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value)->z;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

