#include "tarzan_ghidra_types.hpp"

// Address: 0x004645C0
// Label: TarzanToTheRescue::UpdateScriptedKnifeEnemyGroupA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateScriptedKnifeEnemyGroupA(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value7;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  uint value6;
  int value3;
  int value4;
  int value5;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto LAB_00464bdf;
  value2 = entity->sceneObjects;
  value3 = ((EntitySceneObject *)value2)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value4 = ((EntitySceneObject *)value2)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value2 = ((EntitySceneObject *)value2)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
  value6 = GetAngleFromXZVector12Bit(value3,value4);
  value2 = SqrtToInt(value2 * value2 + value4 * value4 + value3 * value3);
  if (value2 >> 6 < 0x100) {
    value2 = 0x100 - (value2 >> 6);
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) -
         ((short)(&g_SinCosTable12Bit)[(value6 & 0xfff) - 0x400 & 0xfff] * value2 >> 0xc);
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) -
         ((short)(&g_SinCosTable12Bit)[value6 & 0xfff] * value2 >> 0xc);
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if ((resultFlag != '\0') && (*(int *)(value + 0xc) != 9)) {
    *(int *)(value + 0xc4) = *(int *)(value + 0xc);
    if (*(int *)(value + 0xc) == 5) {
      *(undefined4 *)(value + 0xc) = 9;
      if (*(int *)(value + 0x58) == 2) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 4) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 5) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value + 0x10),*(int *)(value + 0x54) + 3);
    }
    if (*(int *)(value + 0xc) == 2) {
      *(undefined4 *)(value + 0xc) = 2;
      if (*(int *)(value + 0x58) == 2) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 4) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 5) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value + 0x10),*(int *)(value + 0x54) + 2);
    }
    if ((*(int *)(value + 0x58) == 2) &&
       (PlayAudioById(0x398,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14),
       *(short *)(entry + 0x3e) < 0)) {
      g_TarzanToTheRescueTrackedKnifeEnemyGroupA0 = 0;
      PlayAudioById(0x3ce,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      CEntities::ProcessEntityDeathAndRelease(entry,0);
      return;
    }
    if ((*(int *)(value + 0x58) == 4) &&
       (PlayAudioById(0x39f,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14),
       *(short *)(entry + 0x3e) < 0)) {
      g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = 0;
      if (g_TarzanToTheRescueTrackedKnifeEnemyVariantC == 0) {
        g_TarzanToTheRescueKnifeEnemyGroupCReleased = 1;
      }
      PlayAudioById(0x3cf,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      CEntities::ProcessEntityDeathAndRelease(entry,0);
      return;
    }
    if ((*(int *)(value + 0x58) == 5) &&
       (PlayAudioById(0x3a3,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14),
       *(short *)(entry + 0x3e) < 0)) {
      g_TarzanToTheRescueTrackedKnifeEnemyVariantC = 0;
      if (g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 == 0) {
        g_TarzanToTheRescueKnifeEnemyGroupCReleased = 1;
      }
      PlayAudioById(0x3d0,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      CEntities::ProcessEntityDeathAndRelease(entry,0);
      return;
    }
  }
  value2 = *(int *)(value + 0xc);
  if (value2 == 2) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(int *)(value + 0xc0) == 1) {
      value3 = GetAngleFromXZVector12Bit
                        (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                         *(int *)(entity->sceneObjects + 0x14),
                         *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                         *(int *)(entity->sceneObjects + 0x1c));
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value3 - 0x800U & 0xfff);
      value7 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value7 = *value7 + (short)(value3 >> 2);
    }
    if (*(int *)(value + 0xc0) == 0) {
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,0xda4);
      value7 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value7 = *value7 + (short)(value3 >> 2);
    }
    if (shortValue == 5) {
      if (*(int *)(value + 0x58) == 2) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      if (*(int *)(value + 0x58) == 4) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      if (*(int *)(value + 0x58) == 5) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      goto LAB_00464bdf;
    }
    if (shortValue == 6) {
      *(undefined4 *)(value + 0xc0) = 1;
      goto LAB_00464bdf;
    }
    if (shortValue == 3) {
      value2 = GetSceneAttachmentWorldPositionByMask(entity->sceneObjects,0x100,&localState3)
      ;
      if (value2 != 0) {
        if (*(int *)(value + 0x58) == 2) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        if (*(int *)(value + 0x58) == 4) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        if (*(int *)(value + 0x58) == 5) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        *(undefined4 *)(value + 0xc0) = 0;
        value2 = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x16c,0x11);
        if (value2 != 0) {
          *(int *)(*(int *)(value2 + 0x38) + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
          value3 = CEntities::FindEntityAttachmentByFlags(value2,0x10000000);
          if (value3 != 0) {
            *(undefined4 *)(value3 + 0x34) = 0x100;
            *(int *)(value3 + 0x70) = (int)*(short *)(entity->sceneObjects + 0xa2);
            *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa2) =
                 *(undefined2 *)(entity->sceneObjects + 0xa2);
            if (*(int *)(value + 0x58) == 2) {
              *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x2014;
              *(undefined4 *)(value3 + 0x78) = 1;
            }
            if (*(int *)(value + 0x58) == 4) {
              *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x2025;
              *(undefined4 *)(value3 + 0x78) = 2;
            }
            if (*(int *)(value + 0x58) == 5) {
              *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x2025;
              *(undefined4 *)(value3 + 0x78) = 2;
            }
          }
        }
      }
      goto LAB_00464bdf;
    }
    if (shortValue != 1) goto LAB_00464bdf;
    value2 = entity->sceneObjects;
    value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - ((EntitySceneObject *)value2)->x;
    value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) - ((EntitySceneObject *)value2)->z;
    if (0x8fffff < value4 * value4 + value3 * value3) {
      if (*(int *)(value + 0x58) == 2) {
        *(undefined4 *)(value2 + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 4) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      if (*(int *)(value + 0x58) == 5) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
      }
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x54));
      *(undefined4 *)(value + 0xc) = 5;
      goto LAB_00464bdf;
    }
  }
  else {
    if (value2 == 5) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value2 = *(int *)(entity->sceneObjects + 0x14);
      value3 = *(int *)(entity->sceneObjects + 0x1c);
      value5 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) - value3;
      value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - value2;
      value3 = GetAngleFromXZVector12Bit
                        (*(int *)(g_PlayerEntitySceneObject + 0x14) - value2,
                         *(int *)(g_PlayerEntitySceneObject + 0x1c) - value3);
      value2 = entity->sceneObjects;
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value3 - 0x800U & 0xfff);
      value7 = (short *)(&((EntitySceneObject *)value2)->yaw);
      *value7 = *value7 + (short)(value3 >> 2);
      if (value5 * value5 + value4 * value4 < 0x900000) {
        *(undefined4 *)(value + 0xc) = 2;
        CEntities::SelectScriptAttachmentSequence
                  (*(undefined4 *)(value + 0x10),*(int *)(value + 0x54) + 1);
        return;
      }
      goto LAB_00464bdf;
    }
    if ((value2 != 9) ||
       (shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry), shortValue != 1))
    goto LAB_00464bdf;
    *(int *)(value + 0xc) = *(int *)(value + 0xc4);
    if (*(int *)(value + 0xc4) == 5) {
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x54));
    }
    if (*(int *)(value + 0xc) != 2) goto LAB_00464bdf;
  }
  CEntities::SelectScriptAttachmentSequence
            (*(undefined4 *)(value + 0x10),*(int *)(value + 0x54) + 1);
LAB_00464bdf:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

