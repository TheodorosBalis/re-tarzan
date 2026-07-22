#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C5E0
// Label: CampsiteCommotion::UpdateHog
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateHog(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  int value2;
  undefined4 value4;
  int value3;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x40);
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      if (*(int *)(entry + 0x50) == 0) {
        PlayAudioById(0xef,(int *)0,(undefined4 *)0);
        *(undefined4 *)(entry + 0x50) = 0x28;
      }
      QueuePlayerDamageEvent(entry,0x1007);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      PlayAudioById(0xef,(int *)0,(undefined4 *)0);
      *(undefined4 *)(entry + 0x50) = 0x28;
      if ((*(ushort *)(entry + 0x42) & 0x1000) != 0) {
        *(undefined2 *)(entry + 0x3e) = 0xffff;
        *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xefff;
      }
      if (*(short *)(entry + 0x3e) < 0) {
        CEntities::ProcessEntityDeath(value,1);
        value3 = 3;
        value4 = *(undefined4 *)
                 (*(int *)(g_CollisionSurfaceTable + 4 +
                          *(int *)(g_PlayerEntitySceneObject + 0x110) * 4) + 0x40 +
                  ((((5999 < ((EntitySceneObject *)value)->surfaceIndex) - 1 & 0xfffffffe) + 0x15) * 7 +
                  *(int *)(g_PlayerEntitySceneObject + 0x110)) * 4 + g_CollisionSurfaceTable);
        do {
          value2 = (int)*(short *)(&g_CampsiteCommotionHogDeathDebrisModelTable +
                                 g_CampsiteCommotionHogDeathDebrisModelIndex * 2);
          if (value2 != -1) {
            if (value2 != 0) {
              CEntities::SpawnMappedEffectOnSurfaceWithScatterConfig
                        (value2,*(undefined4 *)(g_PlayerEntitySceneObject + 0x110),value4,
                         &g_CampsiteCommotionHogDeathDebrisDesc);
            }
            g_CampsiteCommotionHogDeathDebrisModelIndex =
                 g_CampsiteCommotionHogDeathDebrisModelIndex + 1;
          }
          ((EntitySceneObject *)value)->surfaceIndex = 0;
          CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0);
          value3 = value3 + -1;
          *(undefined2 *)(entry + 0x3e) = 0x100;
        } while (value3 != 0);
      }
    }
    if (*(int *)(entry + 0x50) == 0) {
      value3 = RandomModulo(0x28);
      if (value3 == 0) {
        value4 = RandomModulo(5);
        switch(value4) {
        case 1:
          value4 = 0x2a5;
          break;
        case 2:
          value4 = 0x2a6;
          break;
        case 3:
          value4 = 0x2a7;
          break;
        case 4:
          value4 = 0x2a8;
          break;
        default:
          value4 = 0x2a9;
        }
        PlayAudioById(value4,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
        *(undefined4 *)(entry + 0x50) = 0x28;
      }
    }
    else {
      *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + -1;
    }
    if ((*(byte *)(value + 0x13c) & 2) != 0) {
      ((EntitySceneObject *)value)->surfaceIndex = 0;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

