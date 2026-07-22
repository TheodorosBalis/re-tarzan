#include "tarzan_ghidra_types.hpp"

// Address: 0x0047E660
// Label: JourneyToTheTreeHouse::UpdateCivet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateCivet(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value2;
  char resultFlag;
  short shortValue2;
  uint value6;
  undefined4 value7;
  int value3;
  int value4;
  int value5;
  int value;
  bool flagByte;
  
  value4 = entity->sceneObjects;
  if (value4 == 0) goto switchD_0047e813_default;
  value6 = NextRandomValue();
  if ((value6 & 0x3f) == 0) {
    value7 = RandomModulo(4);
    switch(value7) {
    case 0:
      value7 = 0x134;
      break;
    case 1:
      value7 = 0x134;
      break;
    case 2:
      value7 = 0x134;
      break;
    case 3:
      value7 = 0x135;
      break;
    default:
      goto switchD_0047e68e_default;
    }
    PlayAudioById(value7,(int *)&((EntitySceneObject *)value4)->soundPosition,(undefined4 *)&((EntitySceneObject *)value4)->x);
  }
switchD_0047e68e_default:
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value3 == 0) goto switchD_0047e813_default;
  shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  shortValue = *(short *)(value3 + 0x18);
  CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value4,0x1e,0x14);
  shortValue2 = CEntities::HandleAnimalScriptEvent(entry,value4,(int)shortValue2);
  value5 = ((EntitySceneObject *)value4)->surfacePathIndex;
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value5 * 4) + 8 + value5 * 4 +
                  g_CollisionSurfaceTable);
  value = ((EntitySceneObject *)value4)->surfaceIndex;
  if ((value5 != *(int *)(g_PlayerEntitySceneObject + 0x110)) ||
     (flagByte = true, (*(byte *)(entry + 0x4b) & 1) == 0)) {
    flagByte = false;
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value4);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x1007);
    g_PlayerDamageContactEntitySceneObject = value4;
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    PlayAudioById(0x136,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
    *(undefined2 *)(entry + 0x48) = 4;
  }
  if (*(short *)(entry + 0x3e) < 1) {
    CEntities::ProcessEntityDeathAndRelease(entry,1);
    return;
  }
  if ((*(byte *)(entry + 0x4a) & 2) != 0) {
    if (*(byte *)(value4 + 0x75) == 0) {
      if (value2 - value < 0x15f) {
        *(undefined1 *)(value4 + 0x75) = 0xff;
      }
    }
    else if (value < 0x15f) {
      *(byte *)(value4 + 0x75) = ~*(byte *)(value4 + 0x75);
    }
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    if ((*(byte *)(entry + 0x4a) & 0x80) == 0) {
      value4 = RandomModulo(0x14);
      *(int *)(entry + 0x4c) = &((EntitySceneObject *)value4)->x;
      *(undefined2 *)(entry + 0x48) = 1;
      CEntities::SelectScriptAttachmentSequence(value3,0);
    }
    else {
      *(undefined2 *)(entry + 0x48) = 3;
      CEntities::SelectScriptAttachmentSequence(value3,1);
    }
    break;
  case 1:
    if ((flagByte) &&
       (value6 = *(int *)(g_PlayerEntitySceneObject + 0x10c) - ((EntitySceneObject *)value4)->surfaceIndex,
       (*(byte *)(entry + 0x4b) & 1) != 0)) {
      if (*(char *)(value4 + 0x75) == '\0') {
        value = value2 - value;
        value4 = value + -600;
        flagByte = value4 == 0;
      }
      else {
        value6 = ~value6 + 1;
        value4 = value + -600;
        flagByte = value == 600;
      }
      if (((!flagByte && SBORROW4(value,600) == value4 < 0) && ((int)value6 < 0x259)) &&
         (0 < (int)value6)) {
        CEntities::SelectScriptAttachmentSequence(value3,9);
        *(undefined2 *)(entry + 0x48) = 5;
        break;
      }
    }
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if (value4 < 0) {
      *(undefined2 *)(entry + 0x48) = 2;
    }
    break;
  case 2:
    CEntities::SelectScriptAttachmentSequence(value3,1);
    *(undefined2 *)(entry + 0x48) = 3;
    value4 = RandomModulo(8);
    value4 = value4 + 8;
    goto LAB_0047e9cc;
  case 3:
    if (shortValue2 != 0) {
      if (((*(ushort *)(entry + 0x4a) & 0x80) == 0) &&
         (value5 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value5, value5 < 0)) {
        CEntities::SelectScriptAttachmentSequence(value3,3);
        *(undefined2 *)(entry + 0x48) = 5;
      }
      else if (((*(ushort *)(entry + 0x4a) & 0x100) != 0) && (flagByte)) {
        value6 = *(int *)(g_PlayerEntitySceneObject + 0x10c) - ((EntitySceneObject *)value4)->surfaceIndex;
        if (*(char *)(value4 + 0x75) == '\0') {
          value = value2 - value;
          value4 = value + -0x2ee;
          flagByte = value4 == 0;
        }
        else {
          value6 = ~value6 + 1;
          value4 = value + -0x2ee;
          flagByte = value == 0x2ee;
        }
        if (((!flagByte && SBORROW4(value,0x2ee) == value4 < 0) && ((int)value6 < 0x2ef)) &&
           (0 < (int)value6)) {
          CEntities::SelectScriptAttachmentSequence(value3,6);
          *(undefined2 *)(entry + 0x48) = 6;
        }
      }
    }
    break;
  case 4:
    *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfffc;
    CEntities::SelectScriptAttachmentSequence(value3,0xc);
    *(undefined2 *)(entry + 0x48) = 5;
    break;
  case 5:
    if (shortValue == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
    }
    break;
  case 6:
    if (shortValue != 0) break;
    CEntities::SelectScriptAttachmentSequence(value3,1);
    *(undefined2 *)(entry + 0x48) = 3;
    value4 = RandomModulo(3);
    value4 = value4 + 3;
LAB_0047e9cc:
    *(int *)(entry + 0x4c) = value4;
  }
switchD_0047e813_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

