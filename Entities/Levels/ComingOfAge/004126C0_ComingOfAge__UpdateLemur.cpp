#include "tarzan_ghidra_types.hpp"

// Address: 0x004126C0
// Label: ComingOfAge::UpdateLemur
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateLemur(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  char resultFlag;
  short shortValue2;
  int value3;
  int value4;
  undefined4 value6;
  uint value7;
  int value5;
  int value;
  bool flagByte;
  bool flagByte2;
  
  value5 = entity->sceneObjects;
  if ((value5 == 0) ||
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 == 0))
  goto switchD_004127ee_default;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value5,0x14,10);
  value4 = CEntities::HandleAnimalScriptEvent(entry,value5,(int)shortValue2);
  value2 = ((EntitySceneObject *)value5)->surfaceIndex;
  value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value5)->surfacePathIndex * 4) + 8 +
                    ((EntitySceneObject *)value5)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
  resultFlag = CEntities::CheckPlayerDamageContact(value5);
  if (resultFlag != '\0') {
    g_PlayerDamageContactEntitySceneObject = value5;
    if ((*(byte *)(entry + 0x4b) & 1) == 0) {
      QueuePlayerDamageEvent(entry,7);
      if ((2 < *(ushort *)(entry + 0x48)) && (*(ushort *)(entry + 0x48) < 6)) {
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
    PlayAudioById(0x103,(int *)0,(undefined4 *)&((EntitySceneObject *)value5)->x);
    if ((*(byte *)(entry + 0x4a) & 8) != 0) {
      CEntities::HandleAnimalScriptEvent(entry,value5,0x107);
    }
    *(undefined2 *)(entry + 0x48) = 6;
  }
  if (*(short *)(entry + 0x3e) < 0) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if ((*(byte *)(entry + 0x4b) & 1) == 0) {
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(undefined2 *)(entry + 0x48) = 1;
      value5 = RandomModulo(2);
      *(int *)(entry + 0x4c) = value5 + 1;
    }
    else {
      CEntities::SelectScriptAttachmentSequence(value3,0xc);
      *(undefined2 *)(entry + 0x48) = 5;
      *(undefined4 *)(entry + 0x4c) = 10000;
    }
    break;
  case 1:
    if ((value4 == 0) ||
       (value5 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value5, 0 < value5)) break;
    if ((*(byte *)(entry + 0x4a) & 0x80) == 0) {
      value7 = RandomModulo(7);
      if ((value7 & 1) == 0) {
switchD_0041286c_caseD_2:
        *(undefined2 *)(entry + 0x48) = 2;
        break;
      }
switchD_0041286c_caseD_0:
      *(undefined2 *)(entry + 0x48) = 8;
      CEntities::SelectScriptAttachmentSequence(value3,1);
    }
    else {
      value6 = RandomModulo(7);
      switch(value6) {
      case 0:
      case 1:
        goto switchD_0041286c_caseD_0;
      case 2:
        goto switchD_0041286c_caseD_2;
      case 3:
      case 4:
      case 5:
      case 6:
        *(undefined2 *)(entry + 0x48) = 4;
      }
    }
    break;
  case 2:
    value7 = CEntities::ComputeSignedPlayerFacingDistanceXZ(&((EntitySceneObject *)value5)->x);
    if (*(char *)(value5 + 0x75) != '\0') {
      value7 = ~value7 + 1;
    }
    if (((int)value7 < 1) || (0x1c1 < (int)value7)) {
      CEntities::SelectScriptAttachmentSequence(value3,4);
      *(undefined2 *)(entry + 0x48) = 3;
      value5 = RandomModulo(4);
      *(int *)(entry + 0x4c) = value5 + 3;
      break;
    }
    if (*(char *)(value5 + 0x75) == '\0') {
      if (500 < value2) {
        CEntities::SelectScriptAttachmentSequence(value3,6);
        *(undefined2 *)(entry + 0x48) = 7;
        break;
      }
    }
    else if (500 < value - value2) goto LAB_004129ea;
    *(undefined2 *)(entry + 0x48) = 0;
    break;
  case 3:
    if (value4 == 0) break;
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if (value4 < 0) {
      CEntities::SelectScriptAttachmentSequence(value3,9);
      *(undefined2 *)(entry + 0x48) = 8;
    }
    if (*(char *)(value5 + 0x75) != '\0') {
      if (value2 < 0x1f5) {
        *(undefined2 *)(entry + 0x48) = 7;
        CEntities::SelectScriptAttachmentSequence(value3,6);
      }
      break;
    }
    value = value - value2;
    flagByte2 = SBORROW4(value,500);
    value5 = value + -500;
    flagByte = value == 500;
LAB_00412a0c:
    if (!flagByte && flagByte2 == value5 < 0) break;
    if ((*(byte *)(entry + 0x4b) & 1) != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    goto LAB_004129ea;
  case 4:
    CEntities::SelectScriptAttachmentSequence(value3,0xc);
    *(undefined2 *)(entry + 0x48) = 5;
    value5 = RandomModulo(4);
    *(int *)(entry + 0x4c) = value5 + 4;
    break;
  case 5:
    if (value4 == 0) break;
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if (value4 < 0) {
      CEntities::SelectScriptAttachmentSequence(value3,0x11);
      *(undefined2 *)(entry + 0x48) = 8;
    }
    if (*(char *)(value5 + 0x75) == '\0') {
      value = value - value2;
      flagByte2 = SBORROW4(value,700);
      value5 = value + -700;
      flagByte = value == 700;
      goto LAB_00412a0c;
    }
    if (700 < value2) break;
LAB_004129ea:
    *(undefined2 *)(entry + 0x48) = 7;
    CEntities::SelectScriptAttachmentSequence(value3,6);
    break;
  case 6:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value3,0x14);
    *(undefined2 *)(entry + 0x48) = 8;
    break;
  case 7:
    if (shortValue == 5) {
      *(undefined2 *)(entry + 0x48) = 3;
    }
    break;
  case 8:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
  }
switchD_004127ee_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

