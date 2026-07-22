#include "tarzan_ghidra_types.hpp"

// Address: 0x00414D40
// Label: ComingOfAge::UpdateBreakableRewardProp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBreakableRewardProp(int entry)

{
  Entity *entity = (Entity *)entry;
  undefined4 *dataCursor;
  int value;
  int value2;
  char resultFlag;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (*(short *)(entry + 0x4a) == 0) {
      if (resultFlag != '\0') {
        dataCursor = (undefined4 *)(&((EntitySceneObject *)value)->x);
        PlayAudioById(0xd1,(int *)0,(undefined4 *)dataCursor);
        value3 = *(int *)(entry + 0x50);
        *(undefined4 *)(entry + 0x4c) = 9;
        *(undefined2 *)(entry + 0x4a) = 1;
        value2 = *(int *)(&g_ComingOfAgeBreakableRewardSpawnSequenceTable +
                        *(int *)(&g_BreakableRewardSpawnCounter0 + value3 * 4) * 4);
        if (value2 == -1) {
          CEntities::SpawnEntityByTypeAtPosition
                    (*dataCursor,((EntitySceneObject *)value)->y + -0x180,((EntitySceneObject *)value)->z,0x13,0x11
                    );
        }
        else if (value2 == 0) {
          CEntities::SpawnEntityByTypeAtPosition
                    (*dataCursor,((EntitySceneObject *)value)->y + -0x180,((EntitySceneObject *)value)->z,0x13,0x11
                    );
          *(int *)(&g_BreakableRewardSpawnCounter0 + value3 * 4) =
               *(int *)(&g_BreakableRewardSpawnCounter0 + value3 * 4) + 1;
        }
        else {
          CEntities::SpawnMappedEffectOnSurfaceWithScatterConfig
                    (value2,((EntitySceneObject *)value)->surfacePathIndex,((EntitySceneObject *)value)->surfaceIndex,
                     &g_ComingOfAgeBreakableRewardSpawnOffsetTable);
          *(int *)(&g_BreakableRewardSpawnCounter0 + value3 * 4) =
               *(int *)(&g_BreakableRewardSpawnCounter0 + value3 * 4) + 1;
        }
      }
    }
    else {
      value3 = *(int *)(entry + 0x4c) + -1;
      if (value3 < 0) {
        *(undefined2 *)(entry + 0x4a) = 0;
      }
      else {
        *(int *)(value + 0xa8) =
             *(int *)(value + 0xa8) -
             (int)*(short *)(&g_ComingOfAgeBreakableRewardScaleDeltaTable + value3 * 2);
        *(int *)(value + 0xac) =
             *(int *)(value + 0xac) +
             (int)*(short *)(&g_ComingOfAgeBreakableRewardScaleDeltaTable + value3 * 2);
        *(int *)(value + 0xb0) =
             *(int *)(value + 0xb0) -
             (int)*(short *)(&g_ComingOfAgeBreakableRewardScaleDeltaTable + value3 * 2);
      }
      *(int *)(entry + 0x4c) = value3;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

