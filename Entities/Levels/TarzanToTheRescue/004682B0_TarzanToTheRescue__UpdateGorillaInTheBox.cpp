#include "tarzan_ghidra_types.hpp"

// Address: 0x004682B0
// Label: TarzanToTheRescue::UpdateGorillaInTheBox
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateGorillaInTheBox(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  short *value6;
  char resultFlag;
  int value;
  int *intCursor;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined4 value7;
  undefined4 value8;
  undefined1 localState [4];
  undefined4 localState7;
  undefined4 localState6;
  undefined4 localState5;
  int localState2;
  int localState4;
  int localState3;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value5 = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14)
            >> 2;
    _g_TarzanToTheRescueElephantBarrierPlayerDeltaXQuarter = value5;
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (value5 == 0) {
      *(undefined4 *)(value + 0x80) = 0;
      DetachEntitySoundHandle(entity->sceneObjects + 0x104);
    }
    else if (*(int *)(value + 0x80) == 0) {
      PlayAudioById(0x3d4,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value + 0x80) = 1;
    }
    value2 = *(int *)(value + 0x10);
    if (value2 == 1) {
      *(int *)(entity->sceneObjects + 0x14) = *(int *)(entity->sceneObjects + 0x14) - value5;
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,
                         localState,&localState2);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState2;
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        if ((localState4 < 0) && (-0x80 < localState4)) {
          *(int *)(g_PlayerEntitySceneObject + 0x18) =
               *(int *)(g_PlayerEntitySceneObject + 0x18) - localState4;
        }
      }
      value5 = entity->sceneObjects;
      value2 = GetWrappedSignedAngleDelta12Bit
                        ((int)((EntitySceneObject *)value5)->pitch,
                         (int)(short)(&g_SinCosTable12Bit)
                                     [*(int *)(entry + 0x4c) - 0x400U & 0xfff] *
                         *(int *)(value + 0xc) >> 0xc);
      value6 = (short *)(&((EntitySceneObject *)value5)->pitch);
      *value6 = *value6 + (short)(value2 >> 2);
      value5 = entity->sceneObjects;
      *(uint *)(entry + 0x4c) = *(int *)(entry + 0x4c) + 0x40U & 0xfff;
      localState7 = ((EntitySceneObject *)value5)->x;
      localState6 = ((EntitySceneObject *)value5)->y;
      localState5 = ((EntitySceneObject *)value5)->z;
      value5 = CEntities::IsPointMostlyPositiveXFromReference
                        (&localState7,g_PlayerEntitySceneObject + 0x14);
      if (value5 == 0) {
        *(undefined4 *)(value + 0x10) = 2;
      }
      value5 = g_TarzanToTheRescueScriptedBarrierLeftDone;
      if (*(int *)(value + 0x78) == 0) {
        *(undefined4 *)(value + 0x38) = 0xfffffd5f;
        value5 = g_TarzanToTheRescueScriptedBarrierAltDone;
      }
      if (value5 != 0) {
        *(undefined4 *)(value + 0x10) = 2;
      }
    }
    else if (value2 == 2) {
      g_TarzanToTheRescueActiveElephantBarrier = 0;
      if (((*(int *)(value + 0x78) == 1) && (g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 == 0)) &&
         (g_TarzanToTheRescueTrackedKnifeEnemyVariantC == 0)) {
        g_TarzanToTheRescueKnifeEnemyGroupCReleased = 1;
      }
      if (*(int *)(value + 0x78) == 0) {
        g_TarzanToTheRescueScriptedBarrierRightDone = 1;
      }
      value5 = CEntities::AdvanceBounceMotionAndReturnImpact
                        (entity->sceneObjects,value + 0x14);
      if (value5 != 0) {
        *(undefined4 *)(value + 0x10) = 3;
        if (*(int *)(value + 0x78) == 0) {
          PlayAudioById(0x3d2,(int *)0,(undefined4 *)0);
        }
        else {
          PlayAudioById(0x3d3,(int *)0,(undefined4 *)0);
        }
      }
    }
    else if (value2 == 3) {
      dataCursor = (ushort *)(entity->sceneObjects + 0xe);
      *dataCursor = *dataCursor & 0x7fff;
      value5 = CEntities::SpawnEntityByTypeAtPosition
                        (*(undefined4 *)(entity->sceneObjects + 0x14),
                         *(int *)(value + 0x7c) + -500,
                         *(undefined4 *)(entity->sceneObjects + 0x1c),0x14,0x11);
      if (value5 != 0) {
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0xa8) = 0x2cec;
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0xac) = 0x2cec;
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0xb0) = 0x2cec;
        *(undefined4 *)(*(int *)(value5 + 0x38) + 0x6c) = 0xffffff80;
      }
      intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                (*(undefined4 *)(entity->sceneObjects + 0x14),
                                 *(int *)(value + 0x7c) + -500,
                                 *(undefined4 *)(entity->sceneObjects + 0x1c),0x178,0x11);
      if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
        *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2630;
        *(undefined4 *)(intCursor[0xe] + 0x6c) = 0xffffff80;
        value5 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
        if (value5 != 0) {
          ((EntitySceneObject *)value5)->next = 0x7fff;
          *(undefined4 *)(value5 + 0x524) = 0x200;
        }
      }
      value5 = 0;
      do {
        if (value5 == 0) {
          value8 = 1;
LAB_00468470:
          value7 = entity->sceneObjects;
LAB_00468474:
          GetSceneAttachmentWorldPositionByMask(value7,value8,&localState7);
        }
        else {
          if (value5 == 1) {
            value7 = entity->sceneObjects;
            value8 = 2;
            goto LAB_00468474;
          }
          if (value5 == 2) {
            value7 = entity->sceneObjects;
            value8 = 4;
            goto LAB_00468474;
          }
          if (value5 == 3) {
            value8 = 8;
            goto LAB_00468470;
          }
        }
        value2 = CEntities::SpawnEntityByTypeAtPosition(localState7,localState6,localState5,0x160,0x11);
        if (value2 != 0) {
          if (*(int *)(value + 0x78) == 1) {
            *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x2024;
          }
          if (*(int *)(value + 0x78) == 0) {
            *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x2027;
          }
          value3 = CEntities::FindEntityAttachmentByFlags(value2,0x20000000);
          if (value3 != 0) {
            value4 = RandomModulo(0x1e);
            *(int *)(value3 + 0x40) =
                 (int)(short)(&g_SinCosTable12Bit)[value5 * 0x400 - 0x200U & 0xfff] * (value4 + 0x3c)
                 >> 0xc;
            *(int *)(value3 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[value5 * 0x400 + 0x200U & 0xfff] * (value4 + 0x3c)
                 >> 0xc;
            *(undefined2 *)(value3 + 0x54) = 0xff60;
            *(undefined2 *)(value3 + 0x56) = 0xff60;
            *(short *)(*(int *)(value2 + 0x38) + 0xa2) = ((short)value5 + 1) * 0x400;
            *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa0) = 0;
            value2 = RandomModulo(0x14);
            *(int *)(value3 + 0x18) = value2 + 0x3c;
            *(undefined4 *)(value3 + 0x10) = 0;
          }
        }
        value5 = value5 + 1;
      } while (value5 < 4);
      if ((*(int *)(value + 0x78) == 1) && (g_TarzanToTheRescueScriptedBarrierLeftDone == 0)) {
        g_GameplayRuntimeFlags = g_GameplayRuntimeFlags & 0xfffffffb;
        QueuePlayerDamageEvent(0,0x200);
        g_PlayerSequenceDelayTicks = 10;
      }
      if ((*(int *)(value + 0x78) == 0) && (g_TarzanToTheRescueScriptedBarrierAltDone == 0)) {
        g_GameplayRuntimeFlags = g_GameplayRuntimeFlags & 0xfffffffb;
        QueuePlayerDamageEvent(0,0x200);
        g_PlayerSequenceDelayTicks = 10;
      }
      *(undefined4 *)(value + 0x10) = 4;
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

