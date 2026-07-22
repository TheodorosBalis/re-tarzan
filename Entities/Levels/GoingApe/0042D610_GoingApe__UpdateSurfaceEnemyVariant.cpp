#include "tarzan_ghidra_types.hpp"

// Address: 0x0042D610
// Label: GoingApe::UpdateSurfaceEnemyVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateSurfaceEnemyVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  int value2;
  char resultFlag;
  char resultFlag2;
  short shortValue;
  int value3;
  int value4;
  int value5;
  
  LoadEncodedResourceId(0x1016);
  value4 = entity->sceneObjects;
  if ((value4 != 0) &&
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 != 0)) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value5 = (int)shortValue;
    shortValue = *(short *)(value3 + 0x18);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value4,0x24,0x14);
    resultFlag = CEntities::HandleAnimalScriptEvent(entry,value4,value5);
    value = ((EntitySceneObject *)value4)->surfaceIndex;
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value4)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value4)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    resultFlag2 = CEntities::CheckPlayerDamageContact(value4);
    if (resultFlag2 != '\0') {
      g_PlayerDamageContactEntitySceneObject = value4;
      QueuePlayerDamageEvent(entry,0x2006);
    }
    resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag2 != '\0') {
      if (0 < *(short *)(entry + 0x3e)) {
        PlayAudioById(0x112,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      }
      if ((*(byte *)(entry + 0x4a) & 8) != 0) {
        CEntities::HandleAnimalScriptEvent(entry,value4,0x107);
      }
    }
    if (*(short *)(entry + 0x3e) < 1) {
      PlayAudioById(0x158,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y + 0x100;
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    if (value5 == 0x10c) {
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,300);
    }
    else if (value5 == 0x10d) {
      CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,0xffffff40);
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      if ((*(byte *)(entry + 0x4a) & 0x80) == 0) {
        CEntities::SelectScriptAttachmentSequence(value3,0);
        *(undefined2 *)(entry + 0x48) = 1;
        value4 = RandomModulo(0x1e);
        *(int *)(entry + 0x4c) = value4 + 0x1e;
      }
      else {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      break;
    case 1:
      value4 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value4;
      if (value4 < 1) {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      break;
    case 6:
      CEntities::SelectScriptAttachmentSequence(value3,1);
      *(undefined2 *)(entry + 0x48) = 7;
      value4 = RandomModulo(6);
      *(int *)(entry + 0x4c) = value4 + 6;
      break;
    case 7:
      if ((resultFlag != '\0') || (value5 == 0x110)) {
        if (*(char *)(value4 + 0x75) == '\0') {
          if (value2 - value < 800) {
            *(undefined2 *)(entry + 0x48) = 0xb;
            CEntities::SelectScriptAttachmentSequence(value3,9);
            break;
          }
        }
        else if (value < 800) {
          *(undefined2 *)(entry + 0x48) = 0xb;
          CEntities::SelectScriptAttachmentSequence(value3,9);
          break;
        }
        if (((*(byte *)(entry + 0x4a) & 0x80) == 0) &&
           (value4 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value4, value4 < 1)) {
          if (value5 == 0x110) {
            CEntities::SelectScriptAttachmentSequence(value3,6);
            *(undefined2 *)(entry + 0x48) = 0xd;
          }
          else {
            CEntities::SelectScriptAttachmentSequence(value3,3);
            *(undefined2 *)(entry + 0x48) = 0xd;
          }
        }
      }
      break;
    case 0xb:
      if (shortValue == 2) {
        *(undefined2 *)(entry + 0x48) = 7;
      }
      break;
    case 0xd:
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

