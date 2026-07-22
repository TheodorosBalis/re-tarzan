#include "tarzan_ghidra_types.hpp"

// Address: 0x0043EC40
// Label: WelcomeToTheJungle::UpdatePangolin
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void WelcomeToTheJungle::UpdatePangolin(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  int value3;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value4;
  uint value6;
  int value5;
  int value;
  
  value5 = entity->sceneObjects;
  if ((value5 != 0) &&
     (value4 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value4 != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value4 + 0x18);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value5,0x14,0xe);
    resultFlag = CEntities::HandleAnimalScriptEvent(entry,value5,(int)shortValue2);
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value5)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value5)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    value3 = ((EntitySceneObject *)value5)->surfaceIndex;
    resultFlag2 = CEntities::CheckPlayerDamageContact(value5);
    if (resultFlag2 != '\0') {
      QueuePlayerDamageEvent(entry,3);
      g_PlayerDamageContactEntitySceneObject = value5;
      if ((1 < *(ushort *)(entry + 0x48)) && (*(ushort *)(entry + 0x48) < 4)) {
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag2 != '\0') {
      PlayAudioById(0x13e,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
      if ((*(byte *)(entry + 0x4a) & 8) != 0) {
        CEntities::HandleAnimalScriptEvent(entry,value5,0x107);
      }
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
      *(undefined2 *)(entry + 0x48) = 0;
    }
    if (*(short *)(entry + 0x3e) < 1) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      CEntities::SelectScriptAttachmentSequence(value4,0);
      *(undefined2 *)(entry + 0x48) = 1;
      value5 = RandomModulo(3);
      *(int *)(entry + 0x4c) = value5 + 3;
      break;
    case 1:
      if ((resultFlag != '\0') &&
         (value = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value, value < 0)) {
        value = &((EntitySceneObject *)value5)->x;
        value6 = CEntities::ComputeSignedPlayerFacingDistanceXZ(value);
        if (*(char *)(value5 + 0x75) != '\0') {
          value6 = ~value6 + 1;
        }
        if (((int)value6 < 1) || (499 < (int)value6)) {
          *(undefined2 *)(entry + 0x48) = 2;
        }
        else {
          if (*(char *)(value5 + 0x75) == '\0') {
            if (800 < value3) {
              *(undefined2 *)(entry + 0x48) = 4;
              CEntities::SelectScriptAttachmentSequence(value4,3);
              PlayAudioById(0x155,(int *)0,(undefined4 *)value);
              break;
            }
          }
          else if (800 < value2 - value3) {
            *(undefined2 *)(entry + 0x48) = 4;
            CEntities::SelectScriptAttachmentSequence(value4,3);
            PlayAudioById(0x155,(int *)0,(undefined4 *)value);
            break;
          }
          *(undefined2 *)(entry + 0x48) = 0;
        }
      }
      break;
    case 2:
      CEntities::SelectScriptAttachmentSequence(value4,1);
      *(undefined2 *)(entry + 0x48) = 3;
      value5 = RandomModulo(0xc);
      *(int *)(entry + 0x4c) = value5 + 6;
      break;
    case 3:
      if (resultFlag != '\0') {
        value = *(int *)(entry + 0x4c) + -1;
        *(int *)(entry + 0x4c) = value;
        if (value < 0) {
          CEntities::SelectScriptAttachmentSequence(value4,6);
          *(undefined2 *)(entry + 0x48) = 5;
        }
        if (*(char *)(value5 + 0x75) == '\0') {
          if (value2 - value3 < 0x28b) {
            *(undefined2 *)(entry + 0x48) = 4;
            CEntities::SelectScriptAttachmentSequence(value4,3);
            PlayAudioById(0x155,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
          }
        }
        else if (value3 < 0x28b) {
          *(undefined2 *)(entry + 0x48) = 4;
          CEntities::SelectScriptAttachmentSequence(value4,3);
          PlayAudioById(0x155,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
        }
      }
      break;
    case 4:
      if (shortValue == 2) {
        *(undefined2 *)(entry + 0x48) = 3;
      }
      break;
    case 5:
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

