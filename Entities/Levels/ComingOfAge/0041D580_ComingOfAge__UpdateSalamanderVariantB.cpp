#include "tarzan_ghidra_types.hpp"

// Address: 0x0041D580
// Label: ComingOfAge::UpdateSalamanderVariantB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateSalamanderVariantB(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value3;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value4;
  int value5;
  undefined4 value6;
  uint value7;
  int value;
  int value2;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value4 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value4 != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value4 + 0x18);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0,0x10);
    resultFlag = CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue2);
    value5 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    value3 = ((EntitySceneObject *)value)->surfaceIndex;
    resultFlag2 = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag2 != '\0') {
      QueuePlayerDamageEvent(entry,2);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag2 != '\0') {
      PlayAudioById(0x108,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    }
    if (*(short *)(entry + 0x3e) < 0) {
      CEntities::ProcessEntityDeathAndRelease(entry,1);
      return;
    }
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      CEntities::SelectScriptAttachmentSequence(value4,0);
      *(undefined2 *)(entry + 0x48) = 1;
      value = RandomModulo(100);
      *(int *)(entry + 0x4c) = value + 0x3c;
      break;
    case 1:
      value5 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value5;
      if ((value5 < 0) && (resultFlag != '\0')) {
        value6 = RandomModulo(4);
        switch(value6) {
        case 0:
        case 1:
          *(undefined2 *)(entry + 0x48) = 4;
          CEntities::SelectScriptAttachmentSequence(value4,1);
          value7 = RandomModulo(4);
          if ((value7 & 1) == 0) {
            PlayAudioById(0x107,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
          }
          else {
            PlayAudioById(0x106,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
          }
          break;
        case 2:
        case 3:
          *(undefined2 *)(entry + 0x48) = 2;
        }
      }
      break;
    case 2:
      CEntities::SelectScriptAttachmentSequence(value4,4);
      *(undefined2 *)(entry + 0x48) = 3;
      value = RandomModulo(10);
      *(int *)(entry + 0x4c) = value + 5;
      break;
    case 3:
      if (resultFlag != '\0') {
        value2 = *(int *)(entry + 0x4c) + -1;
        *(int *)(entry + 0x4c) = value2;
        if (value2 < 0) {
          CEntities::SelectScriptAttachmentSequence(value4,9);
          *(undefined2 *)(entry + 0x48) = 4;
        }
        if ((value3 < 0x321) && (*(char *)(value + 0x75) == -1)) {
          *(undefined2 *)(entry + 0x48) = 5;
          CEntities::SelectScriptAttachmentSequence(value4,6);
        }
        else if ((value5 - value3 < 0x321) && (*(char *)(value + 0x75) == '\0')) {
          *(undefined2 *)(entry + 0x48) = 5;
          CEntities::SelectScriptAttachmentSequence(value4,6);
        }
      }
      break;
    case 4:
      if (shortValue == 0) {
        *(undefined2 *)(entry + 0x48) = 0;
      }
      break;
    case 5:
      if (shortValue == 5) {
        *(undefined2 *)(entry + 0x48) = 3;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

