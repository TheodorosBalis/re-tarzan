#include "tarzan_ghidra_types.hpp"

// Address: 0x0047B850
// Label: JourneyToTheTreeHouse::UpdateBird
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void JourneyToTheTreeHouse::UpdateBird(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  undefined2 value7;
  int value;
  int value2;
  char resultFlag;
  short shortValue2;
  int value3;
  int value4;
  undefined4 value8;
  uint value5;
  uint value6;
  
  shortValue2 = 0;
  value = entity->sceneObjects;
  if (value == 0) goto LAB_0047bd30;
  if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\r') {
    resultFlag = CEntities::IsEntitySceneObjectWithinCameraYawWindow(value,600);
    if (resultFlag == '\0') {
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x80;
    }
    else {
      *(ushort *)(value + 0xe) = *(ushort *)(value + 0xe) & 0x7fff;
    }
  }
  if (*(short *)(entry + 0x48) == 6) {
    resultFlag = IsEntityOutsideOuterActivationBounds(entry);
    if (resultFlag == '\0') {
      return;
    }
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if (value3 == 0) goto LAB_0047bd30;
  if ((*(byte *)(entry + 0x4a) & 1) == 0) {
    shortValue = 0;
  }
  else {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value3 + 0x18);
  }
  value4 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value4 == 0) goto LAB_0047bd30;
  if (shortValue2 == 0x10f) {
    value8 = RandomModulo(4);
    switch(value8) {
    case 0:
      value8 = 0x113;
      break;
    case 1:
      value8 = 0x114;
      break;
    case 2:
      value8 = 0x115;
      break;
    case 3:
      value8 = 0x116;
      break;
    default:
      goto switchD_0047b923_default;
    }
    PlayAudioById(value8,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
  }
switchD_0047b923_default:
  if (*(code **)(value4 + 0xc) != (code *)0x0) {
    (**(code **)(value4 + 0xc))(entry,value);
  }
  if (((*(byte *)(entry + 0x4a) & 0x10) != 0) &&
     (resultFlag = CEntities::CheckPlayerDamageContact(value), resultFlag != '\0')) {
    QueuePlayerDamageEvent(entry,0x2006);
    g_PlayerDamageContactEntitySceneObject = value;
  }
  value2 = ((EntitySceneObject *)value)->surface;
  if (value2 == 0) {
    return;
  }
  if ((*(byte *)(value2 + 0x14) & 4) != 0) {
    *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 0x80;
  }
  if (*(ushort *)(value4 + 0x10) < *(ushort *)(value4 + 0x14)) {
    *(ushort *)(value + 0xa0) =
         ~((*(ushort *)(value4 + 0x14) - *(ushort *)(value4 + 0x10)) * 8) & 0xfff;
  }
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value4 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value4;
    if (-1 < value4) break;
    value8 = RandomModulo(4);
    switch(value8) {
    case 0:
    case 1:
      value8 = 7;
      break;
    case 2:
    case 3:
      value8 = 4;
      break;
    default:
      goto switchD_0047ba07_default;
    }
    CEntities::SelectScriptAttachmentSequence(value3,value8);
switchD_0047ba07_default:
    *(undefined2 *)(entry + 0x48) = 4;
    *(undefined4 *)(entry + 0x4c) = 0;
    break;
  case 1:
    if (*(short *)(value2 + 0x12) == 0) {
      value7 = *(undefined2 *)(value4 + 0x10);
LAB_0047bb7b:
      WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,value7);
    }
    else {
      value3 = (int)*(short *)(value2 + 0x12);
      if (*(short *)(value4 + 0x16) == 0) {
        value7 = *(undefined2 *)(value4 + 0x10);
        goto LAB_0047bb7b;
      }
      if (0 < *(int *)(value + 0x40)) {
        *(int *)(value4 + 0x24) = -*(int *)(value4 + 0x24);
        *(undefined4 *)(value + 0x40) = 0;
      }
      if (-value3 != *(int *)(value + 0x40) && value3 <= -*(int *)(value + 0x40)) {
        *(int *)(value4 + 0x24) = -*(int *)(value4 + 0x24);
        if ((*(byte *)(entry + 0x4b) & 2) != 0) {
          *(undefined2 *)(value4 + 0x16) = 0;
          *(undefined4 *)(value4 + 0x24) = 0;
        }
        *(int *)(value + 0x40) = -value3;
      }
      WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,*(undefined2 *)(value4 + 0x10));
      *(int *)(value + 0x40) = *(int *)(value + 0x40) + *(int *)(value4 + 0x24);
      *(short *)(value4 + 0x22) = *(short *)(value4 + 0x22) + -1;
      if (*(short *)(value4 + 0x22) == 0) {
        if (*(int *)(value4 + 0x24) == 0) {
          value3 = RandomModulo((uint)*(ushort *)(value4 + 0x16) << 1);
          *(uint *)(value4 + 0x24) = (uint)*(ushort *)(value4 + 0x16) - value3;
          shortValue2 = RandomModulo(100);
          *(short *)(value4 + 0x22) = shortValue2 + 0x32;
        }
        else {
          *(undefined4 *)(value4 + 0x24) = 0;
          shortValue2 = RandomModulo(200);
          *(short *)(value4 + 0x22) = shortValue2 + 0x32;
        }
      }
    }
    if (((*(byte *)(entry + 0x4a) & 8) == 0) &&
       (value3 = *(int *)(entry + 0x4c) + -1, *(int *)(entry + 0x4c) = value3, value3 < 0)) {
      value3 = RandomModulo(200);
      *(int *)(entry + 0x4c) = value3 + 0xb4;
      *(undefined2 *)(entry + 0x48) = 2;
    }
    break;
  case 2:
    if (*(short *)(value4 + 0x10) == 0) {
      WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,0);
      *(undefined2 *)(entry + 0x48) = 3;
    }
    else {
      shortValue2 = *(short *)(value4 + 0x10) + -1;
LAB_0047bbc2:
      *(short *)(value4 + 0x10) = shortValue2;
      WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,shortValue2);
    }
    break;
  case 3:
    *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
    WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,0);
    *(undefined2 *)(entry + 0x48) = 5;
    break;
  case 4:
    if ((shortValue2 == 0x100) && (*(int *)(entry + 0x4c) == 0)) {
      value4 = RandomModulo(0x14);
      *(int *)(entry + 0x4c) = value4 + 0xf;
      *(int *)(entry + 0x50) = *(short *)(value3 + 0x16) + -3;
    }
    else if (1 < *(int *)(entry + 0x4c)) {
      *(undefined2 *)(value3 + 0x16) = *(undefined2 *)(entry + 0x50);
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
    }
    if (shortValue == 1) {
      *(undefined2 *)(entry + 0x48) = 0;
      value3 = RandomModulo(0x1e);
      *(int *)(entry + 0x4c) = value3 + 0x28;
    }
    break;
  case 5:
    if (*(ushort *)(value4 + 0x10) < *(ushort *)(value4 + 0x14)) {
      shortValue2 = *(short *)(value4 + 0x12) + *(ushort *)(value4 + 0x10);
      goto LAB_0047bbc2;
    }
    WelcomeToTheJungle::MoveBirdAndEaseFacingAngles(entry,*(ushort *)(value4 + 0x14));
    *(undefined2 *)(entry + 0x48) = 1;
  }
  if (((*(ushort *)(entry + 0x4a) & 2) != 0) && ((*(byte *)(value + 0x13c) & 2) != 0)) {
    if ((*(ushort *)(entry + 0x4a) & 4) != 0) {
      CEntities::ReleaseEntityAndMarkDescriptorConsumed();
      return;
    }
    goto LAB_0047bd3e;
  }
  value5 = *(uint *)(value2 + 0x14);
  if (*(char *)(value + 0x75) == '\0') {
    if ((((value5 & 0xc000) != 0) &&
        (value6 = (uint)*(ushort *)(value2 + 0x18), value6 != ((EntitySceneObject *)value)->surfacePathIndex)) &&
       (((value5 & 1) != 0 && (value5 = RandomModulo(0x40), (value5 & 7) == 0)))) {
      value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value6 * 4) + 0x40 +
                       ((uint)*(ushort *)(value2 + 0x1a) * 7 + value6) * 4 + g_CollisionSurfaceTable)
      ;
      value4 = *(int *)(value2 + 0xc);
LAB_0047bd1a:
      ((EntitySceneObject *)value)->surfacePathIndex = value6;
      ((EntitySceneObject *)value)->surfaceIndex = ((EntitySceneObject *)value)->surfaceIndex + (value3 - value4);
    }
  }
  else if (((((value5 & 0x2000) == 0) && ((*(uint *)(value2 + 0x30) & 0xc000) != 0)) &&
           ((*(uint *)(value2 + 0x30) & 2) != 0)) &&
          ((value6 = (uint)*(ushort *)(value2 + 0x34), value6 != ((EntitySceneObject *)value)->surfacePathIndex &&
           (value5 = RandomModulo(0x40), (value5 & 7) == 0)))) {
    value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value6 * 4) + 0x40 +
                     ((uint)*(ushort *)(value2 + 0x36) * 7 + value6) * 4 + g_CollisionSurfaceTable);
    value4 = *(int *)(value2 + 0x28);
    goto LAB_0047bd1a;
  }
LAB_0047bd30:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag == '\0') {
    return;
  }
LAB_0047bd3e:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

