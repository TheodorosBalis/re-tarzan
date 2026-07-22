#include "tarzan_ghidra_types.hpp"

// Address: 0x0045D830
// Label: JourneyToTheTreeHouse::UpdateRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateRhino(int entry)

{
  Entity *entity = (Entity *)entry;
  bool flagByte;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  int value4;
  
  value3 = entity->sceneObjects;
  if ((value3 == 0) ||
     (value = CEntities::FindEntityAttachmentByFlags(entry,0x400), value == 0))
  goto switchD_0045d920_default;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  CEntities::MoveEntitySceneObjectAndSnapFacingAngles(entry,*(undefined2 *)(entry + 0x4a));
  CEntities::CheckEntitySceneObjectCollisionDelta(value3);
  if (shortValue < 0x107) {
    if (shortValue == 0x106) {
      *(undefined2 *)(entry + 0x4a) = 0x2c;
    }
    else if (shortValue == 4) {
      *(undefined2 *)(entry + 0x4a) = 0;
    }
    else if (shortValue == 0x105) {
      *(undefined2 *)(entry + 0x4a) = 0x10;
    }
  }
  else if (shortValue == 0x107) {
    *(byte *)(value3 + 0x75) = ~*(byte *)(value3 + 0x75);
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag == '\0') {
LAB_0045d8e2:
    flagByte = false;
  }
  else {
    value2 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
    flagByte = true;
    if (value2 != 0) goto LAB_0045d8e2;
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value3);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x100c);
    g_PlayerDamageContactEntitySceneObject = value3;
  }
  value2 = ((EntitySceneObject *)value3)->surfaceIndex;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value3 = RandomModulo(0x32);
    *(int *)(entry + 0x4c) = &((EntitySceneObject *)value3)->x;
    *(undefined2 *)(entry + 0x48) = 1;
    break;
  case 1:
    if (flagByte) {
      *(undefined2 *)(entry + 0x48) = 2;
      CEntities::SelectScriptAttachmentSequence(value,4);
      PlayAudioById(0xe6,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
    }
    else {
      value3 = *(int *)(entry + 0x4c) + -1;
      *(int *)(entry + 0x4c) = value3;
      if (value3 == 0) {
        value3 = RandomModulo(0x32);
        *(int *)(entry + 0x4c) = &((EntitySceneObject *)value3)->x;
        CEntities::SelectScriptAttachmentSequence(value,1);
      }
    }
    break;
  case 2:
    if (*(short *)(value + 0x18) == 6) {
      *(undefined2 *)(entry + 0x48) = 3;
    }
    break;
  case 3:
    if (*(char *)(value3 + 0x75) == '\0') {
      value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
      if (value4 != 0) {
        value2 = *(int *)(entry + 0x50) - value2;
        goto joined_r0x0045d9f2;
      }
LAB_0045d9f4:
      CEntities::SelectScriptAttachmentSequence(value,8);
      *(undefined2 *)(entry + 0x48) = 4;
      PlayAudioById(0x14b,(int *)0,(undefined4 *)&((EntitySceneObject *)value3)->x);
    }
    else {
      value4 = CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
      if (value4 == 0) goto LAB_0045d9f4;
joined_r0x0045d9f2:
      if (value2 < 0x5dd) goto LAB_0045d9f4;
    }
    if ((g_PlayerDamageInvulnerabilityTicks == 0) &&
       (value = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - ((EntitySceneObject *)value3)->z,
       -400 < *(int *)(g_PlayerEntitySceneObjectData + 0xc) - ((EntitySceneObject *)value3)->y)) {
      if (*(char *)(value3 + 0x75) != '\0') {
        value = -value;
      }
      if ((value < 0) && (-600 < value)) {
        QueuePlayerDamageEvent(entry,0x100c);
      }
    }
    break;
  case 4:
    if (*(short *)(value + 0x18) == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
  }
switchD_0045d920_default:
  if ((*(int *)(g_WorldEntitySceneObjectArrayBase + 0x3884) != 0) &&
     (resultFlag = IsEntityOutsideOuterActivationBounds(entry), resultFlag != '\0')) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

