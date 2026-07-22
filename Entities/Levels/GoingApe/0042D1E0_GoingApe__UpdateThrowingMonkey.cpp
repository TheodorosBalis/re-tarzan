#include "tarzan_ghidra_types.hpp"

// Address: 0x0042D1E0
// Label: GoingApe::UpdateThrowingMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateThrowingMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  char resultFlag;
  short shortValue2;
  int value;
  undefined4 value4;
  int value2;
  int value3;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  LoadEncodedResourceId(0x1015);
  value2 = entity->sceneObjects;
  if ((value2 != 0) &&
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value3 = (int)shortValue2;
    shortValue2 = *(short *)(value + 0x18);
    CEntities::HandleAnimalScriptEvent(entry,value2,value3);
    CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0);
    resultFlag = CEntities::CheckPlayerDamageContact(value2);
    if (resultFlag != '\0') {
      g_PlayerDamageContactEntitySceneObject = value2;
      QueuePlayerDamageEvent(entry,6);
    }
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      if (*(short *)(entry + 0x3e) < 1) goto LAB_0042d28e;
      PlayAudioById(0x112,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
      *(undefined2 *)(entry + 0x48) = 9;
    }
    if (*(short *)(entry + 0x3e) < 1) {
LAB_0042d28e:
      PlayAudioById(0x158,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      *(undefined2 *)(entry + 0x48) = 1;
      *(uint *)(entry + 0x4c) = (uint)*(ushort *)(entry + 0x4a);
      break;
    case 1:
      if (((entity->descriptor == 0) ||
          ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 1) == 0)) ||
         (value3 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value3 != 0)) {
        value3 = *(int *)(entry + 0x4c) + -1;
        *(int *)(entry + 0x4c) = value3;
        if ((value3 < 1) &&
           (*(int *)(g_PlayerEntitySceneObject + 0x18) - ((EntitySceneObject *)value2)->y < 300)) {
          *(undefined2 *)(entry + 0x48) = 5;
          CEntities::SelectScriptAttachmentSequence(value,0x15);
          value2 = RandomModulo(4);
          *(int *)(entry + 0x50) = value2 + 5;
        }
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0xc;
        CEntities::SelectScriptAttachmentSequence(value,7);
      }
      break;
    case 5:
      if (value3 == 0xb) {
        value = GetSceneAttachmentWorldPositionByMask(value2,0x100,&localState3);
        if ((value != 0) &&
           (value = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x1a,0x11),
           value != 0)) {
          value3 = CEntities::CreateEntityAttachment(value,0x9c,0x10000000);
          if (value3 == 0) {
            CEntities::ReleaseEntityToFreeList((byte *)value);
          }
          else {
            *(undefined4 *)(value3 + 0x1c) = 6;
            *(undefined2 *)(value3 + 0x18) = 0x5a;
            if ((entity->descriptor != 0) &&
               (value = *(int *)(*(int *)(entity->descriptor + 0x10) + 4), value != 0)) {
              *(short *)(value3 + 0x18) = (short)value;
            }
            *(int *)(value3 + 0xc) =
                 (short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw - 0x400 & 0xfff] * 0x50 >>
                 0xc;
            value4 = RandomModulo(0x14);
            *(undefined4 *)(value3 + 0x10) = value4;
            shortValue = (&g_SinCosTable12Bit)[((EntitySceneObject *)value2)->yaw & 0xfff];
            *(undefined1 *)(value3 + 0x20) = 0;
            *(int *)(value3 + 0x14) = shortValue * 0x50 >> 0xc;
          }
        }
      }
      else if (value3 == 0x10e) {
        value3 = *(int *)(entry + 0x50) + -1;
        *(int *)(entry + 0x50) = value3;
        if (((value3 != 0) &&
            (*(int *)(g_PlayerEntitySceneObject + 0x18) - ((EntitySceneObject *)value2)->y < 300)) &&
           (value2 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity), value2 != 0)) {
          *(undefined2 *)(value + 0x16) = 5;
        }
        break;
      }
      if (shortValue2 == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
      break;
    case 9:
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
      CEntities::SelectScriptAttachmentSequence(value,0x12);
      *(undefined2 *)(entry + 0x48) = 0xc;
      break;
    case 0xc:
      if (shortValue2 == 0) {
        *(undefined2 *)(entry + 0x48) = 1;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

