#include "tarzan_ghidra_types.hpp"

// Address: 0x0041A210
// Label: ComingOfAge::UpdateHogVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateHogVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value3;
  int value4;
  uint value6;
  int value5;
  int value;
  
  value = entity->sceneObjects;
  if ((value == 0) ||
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 == 0))
  goto switchD_0041a322_caseD_4;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0x28,0x1e);
  resultFlag = CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue2);
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  value5 = ((EntitySceneObject *)value)->surfaceIndex;
  resultFlag2 = CEntities::CheckPlayerDamageContact(value);
  if ((resultFlag2 != '\0') &&
     (QueuePlayerDamageEvent(entry,7), g_PlayerDamageContactEntitySceneObject = value,
     *(short *)(entry + 0x48) != 1)) {
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    *(undefined2 *)(entry + 0x48) = 0;
  }
  resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag2 != '\0') {
    PlayAudioById(0xef,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,value,0x107);
    }
    *(undefined2 *)(entry + 0x48) = 6;
  }
  if (*(short *)(entry + 0x3e) < 1) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    CEntities::SelectScriptAttachmentSequence(value3,0);
    *(undefined2 *)(entry + 0x48) = 1;
    value = RandomModulo(2);
    *(int *)(entry + 0x4c) = value + 1;
    break;
  case 1:
    if ((resultFlag != '\0') &&
       ((value4 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value4, value4 < 0 ||
        ((*(byte *)(entry + 0x4b) & 2) != 0)))) {
      PlayAudioById(0xee,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      value6 = CEntities::ComputeSignedPlayerFacingDistanceXZ(&((EntitySceneObject *)value)->x);
      if (*(char *)(value + 0x75) != '\0') {
        value6 = ~value6 + 1;
      }
      if (((int)value6 < 1) || (499 < (int)value6)) {
        *(undefined2 *)(entry + 0x48) = 2;
      }
      else {
        if (*(char *)(value + 0x75) != '\0') {
          value5 = value2 - value5;
        }
        if (value5 < 0x259) {
          *(undefined2 *)(entry + 0x48) = 0;
        }
        else {
          CEntities::SelectScriptAttachmentSequence(value3,7);
          *(undefined2 *)(entry + 0x48) = 7;
        }
      }
    }
    break;
  case 2:
    CEntities::SelectScriptAttachmentSequence(value3,1);
    *(undefined2 *)(entry + 0x48) = 3;
    value = RandomModulo(10);
    *(int *)(entry + 0x4c) = value + 5;
    break;
  case 3:
    if (*(char *)(value + 0x75) == '\0') {
      if (0x226 < value2 - value5) break;
      if ((*(byte *)(entry + 0x4b) & 2) != 0) {
        CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
        return;
      }
    }
    else if (0x226 < value5) break;
    *(undefined2 *)(entry + 0x48) = 7;
    CEntities::SelectScriptAttachmentSequence(value3,6);
    break;
  case 6:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value3,10);
    *(undefined2 *)(entry + 0x48) = 8;
    break;
  case 7:
    goto joined_r0x0041a469;
  case 8:
joined_r0x0041a469:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
  }
switchD_0041a322_caseD_4:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

