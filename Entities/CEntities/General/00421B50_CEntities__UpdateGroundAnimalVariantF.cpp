#include "tarzan_ghidra_types.hpp"

// Address: 0x00421B50
// Label: CEntities::UpdateGroundAnimalVariantF
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateGroundAnimalVariantF(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  char resultFlag;
  short shortValue2;
  int value;
  int value2;
  int value3;
  uint value7;
  int value4;
  int value5;
  undefined4 value6;
  
  value2 = entity->sceneObjects;
  if ((value2 == 0) ||
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value == 0))
  goto switchD_00421c86_caseD_2;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value2,0x10,10);
  shortValue2 = CEntities::HandleAnimalScriptEvent(entry,value2,(int)shortValue2);
  value5 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value2)->surfacePathIndex * 4) + 8 +
                   ((EntitySceneObject *)value2)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  value4 = ((EntitySceneObject *)value2)->surfaceIndex;
  resultFlag = CEntities::CheckPlayerDamageContact(value2);
  if (resultFlag != '\0') {
    g_PlayerDamageContactEntitySceneObject = value2;
    if ((*(byte *)(entry + 0x4b) & 2) == 0) {
      QueuePlayerDamageEvent(entry,7);
      switch(*(undefined2 *)(entry + 0x48)) {
      case 3:
      case 4:
      case 7:
      case 8:
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    else {
      QueuePlayerDamageEvent(entry,0x1007);
    }
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    PlayAudioById(0x139,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,value2,0x107);
    }
    *(undefined2 *)(entry + 0x48) = 5;
  }
  if (*(short *)(entry + 0x3e) < 1) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if ((*(byte *)(entry + 0x4b) & 2) == 0) {
      *(undefined2 *)(entry + 0x48) = 1;
      value2 = RandomModulo(0x1e);
      *(int *)(entry + 0x4c) = value2 + 0x1e;
      CEntities::SelectScriptAttachmentSequence(value,0);
      break;
    }
LAB_00421c93:
    *(undefined2 *)(entry + 0x48) = 3;
    CEntities::SelectScriptAttachmentSequence(value,4);
    break;
  case 1:
    value3 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value3;
    if (-1 < value3) break;
    if (*(char *)(value2 + 0x75) == '\0') {
      if (400 < value5 - value4) goto LAB_00421d32;
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value,9);
      value6 = 0x137;
    }
    else if (value4 < 0x191) {
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value,9);
      value6 = 0x137;
    }
    else {
LAB_00421d32:
      value7 = CEntities::ComputeSignedPlayerFacingDistanceXZ(&((EntitySceneObject *)value2)->x);
      if (*(char *)(value2 + 0x75) != '\0') {
        value7 = ~value7 + 1;
      }
      if (((int)value7 < 1) || (0x1c1 < (int)value7)) goto LAB_00421c93;
      if (*(char *)(value2 + 0x75) != '\0') {
        value4 = value5 - value4;
      }
      if (value4 < 0x1f5) {
        *(undefined2 *)(entry + 0x48) = 0;
        break;
      }
      *(undefined2 *)(entry + 0x48) = 6;
      CEntities::SelectScriptAttachmentSequence(value,9);
      value6 = 0x137;
    }
LAB_00421ed4:
    PlayAudioById(value6,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
    break;
  case 3:
    if (shortValue2 != 0) {
      if (*(char *)(value2 + 0x75) == '\0') {
        if (400 < value5 - value4) break;
        if ((*(byte *)(entry + 0x4b) & 2) != 0) {
          CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
          return;
        }
      }
      else if (400 < value4) break;
      *(undefined2 *)(entry + 0x48) = 4;
      CEntities::SelectScriptAttachmentSequence(value,6);
    }
    break;
  case 4:
    if (shortValue == 0) {
      if ((*(byte *)(entry + 0x4b) & 4) == 0) {
        *(undefined2 *)(entry + 0x48) = 1;
        *(undefined4 *)(entry + 0x4c) = 0;
        CEntities::SelectScriptAttachmentSequence(value,0);
      }
      else if (*(char *)(value2 + 0x75) == '\0') {
        *(undefined2 *)(entry + 0x48) = 7;
        CEntities::SelectScriptAttachmentSequence(value,1);
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    break;
  case 5:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value,0xc);
    *(undefined2 *)(entry + 0x48) = 6;
    break;
  case 6:
    if (shortValue == 0) {
      if ((*(byte *)(entry + 0x4b) & 2) == 0) {
        *(undefined2 *)(entry + 0x48) = 1;
        *(undefined4 *)(entry + 0x4c) = 0;
      }
      else {
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
    break;
  case 7:
    value = RandomModulo(3);
    *(int *)(entry + 0x4c) = value + 1;
    *(undefined2 *)(entry + 0x48) = 8;
    PlayAudioById(0x138,(int *)0,(undefined4 *)&((EntitySceneObject *)value2)->x);
    break;
  case 8:
    if (shortValue != 0) break;
    value5 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value5;
    if (value5 < 1) {
      *(undefined2 *)(entry + 0x48) = 0;
      break;
    }
    CEntities::SelectScriptAttachmentSequence(value,1);
    value6 = 0x138;
    goto LAB_00421ed4;
  }
switchD_00421c86_caseD_2:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

