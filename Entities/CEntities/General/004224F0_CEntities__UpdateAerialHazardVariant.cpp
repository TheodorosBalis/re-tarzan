#include "tarzan_ghidra_types.hpp"

// Address: 0x004224F0
// Label: CEntities::UpdateAerialHazardVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateAerialHazardVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  uint value11;
  char resultFlag;
  char resultFlag2;
  short shortValue;
  int value7;
  int value8;
  undefined4 value12;
  int value9;
  int value10;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *intCursor;
  
  value4 = entity->sceneObjects;
  if (value4 == 0) goto LAB_00422b74;
  resultFlag = CEntities::CheckPlayerDamageContact(value4);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x2003);
  }
  resultFlag2 = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag2 != '\0') {
    *(undefined2 *)(entry + 0x48) = 7;
  }
  value7 = CEntities::FindEntityAttachmentByFlags(entry,0x400);
  if ((value7 == 0) ||
     (value8 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000), value8 == 0))
  goto LAB_00422b74;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0x10f) {
    value12 = RandomModulo(4);
    switch(value12) {
    case 0:
      value12 = 0x124;
      break;
    case 1:
      value12 = 0x125;
      break;
    case 2:
      value12 = 0x126;
      break;
    case 3:
      value12 = 0x127;
      break;
    default:
      goto switchD_00422596_default;
    }
    PlayAudioById(value12,(int *)&((EntitySceneObject *)value4)->soundPosition,(undefined4 *)&((EntitySceneObject *)value4)->x);
  }
switchD_00422596_default:
  if ((*(ushort *)(entry + 0x48) < 6) && (*(ushort *)(entry + 0x48) != 4)) {
    value6 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value5 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value9 = ((EntitySceneObject *)value4)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
  }
  else {
    value6 = ((EntitySceneObject *)value4)->x - *(int *)(value8 + 0xc);
    value5 = ((EntitySceneObject *)value4)->y - *(int *)(value8 + 0x10);
    value9 = ((EntitySceneObject *)value4)->z - *(int *)(value8 + 0x14);
  }
  intCursor = (int *)(&((EntitySceneObject *)value4)->x);
  value10 = SqrtToInt(value5 * value5 + value6 * value6 + value9 * value9);
  value = value10 >> 6;
  value2 = SqrtToInt(value6 * value6 + value9 * value9);
  switch(*(undefined2 *)(entry + 0x48)) {
  case 1:
  case 2:
  case 3:
  case 6:
  case 7:
    value12 = RandomModulo(0x14);
    *(undefined4 *)(value4 + 0x40) = value12;
    break;
  default:
    *(undefined4 *)(value4 + 0x40) = 0;
  }
  if ((*(ushort *)(entry + 0x48) != 0) && (*(ushort *)(entry + 0x48) < 8)) {
    value3 = GetAngleFromXZVector12Bit(value6,value9);
    value3 = (value3 - ((EntitySceneObject *)value4)->yaw) * 0x100000;
    ((EntitySceneObject *)value4)->yaw =
         (short)((int)((value3 >> 0x14) + (value3 >> 0x1f & 3U)) >> 2) + ((EntitySceneObject *)value4)->yaw;
  }
  if (*(ushort *)(entry + 0x48) < 8) {
    switch(*(ushort *)(entry + 0x48)) {
    case 0:
      if (*(int *)(entry + 0x4c) != 0) {
        *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      }
      if ((value < *(int *)(value8 + 0x18)) && (*(int *)(entry + 0x4c) == 0)) {
        *(undefined2 *)(entry + 0x48) = 1;
        CEntities::SelectScriptAttachmentSequence(value7,1);
        *(undefined4 *)(entry + 0x4c) = *(undefined4 *)(value8 + 0x1c);
        if ((entity->descriptor != 0) &&
           ((*(byte *)(*(int *)(entity->descriptor + 0x10) + 3) & 2) != 0)) {
          *(undefined4 *)(entry + 0x4c) = 10;
        }
      }
      break;
    case 1:
      value7 = ComputeDistance3D(*intCursor,((EntitySceneObject *)value4)->y,
                                ((EntitySceneObject *)value4)->z,*(undefined4 *)(value8 + 0xc),
                                *(undefined4 *)(value8 + 0x10),*(undefined4 *)(value8 + 0x14));
      if (*(int *)(value8 + 0x20) < value7) {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      else {
        value7 = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        value = value / 0x6e;
        if (value == 0) {
          value = 1;
        }
        *intCursor = *intCursor - value6 / value;
        ((EntitySceneObject *)value4)->y =
             ((EntitySceneObject *)value4)->y - ((((EntitySceneObject *)value4)->y - value7) + 300) / value;
        ((EntitySceneObject *)value4)->z = ((EntitySceneObject *)value4)->z - value9 / value;
        if (value2 >> 6 < 200) {
          *(undefined2 *)(entry + 0x48) = 2;
        }
      }
      break;
    case 2:
      if (value2 >> 6 < 200) {
        *(undefined2 *)(entry + 0x48) = 3;
        if ((*(byte *)(entry + 0x4b) & 2) == 0) {
          *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
        }
      }
      else {
        *(undefined2 *)(entry + 0x48) = 1;
      }
      break;
    case 3:
      value7 = ComputeDistance3D(*intCursor,((EntitySceneObject *)value4)->y,
                                ((EntitySceneObject *)value4)->z,*(undefined4 *)(value8 + 0xc),
                                *(undefined4 *)(value8 + 0x10),*(undefined4 *)(value8 + 0x14));
      if (*(int *)(value8 + 0x20) < value7) {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      else {
        *(short *)(value4 + 0xa0) =
             ((short)((0x200 - *(short *)(value4 + 0xa0)) * 0x10) >> 5) + *(short *)(value4 + 0xa0);
        value7 = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        value8 = (int)(value + (value10 >> 0x1f & 0x3fU)) >> 6;
        if (value8 == 0) {
          value8 = 1;
        }
        *intCursor = *intCursor - value6 / value8;
        value7 = ((EntitySceneObject *)value4)->y - ((((EntitySceneObject *)value4)->y - value7) + 0x80) / value8;
        ((EntitySceneObject *)value4)->y = value7;
        ((EntitySceneObject *)value4)->z = ((EntitySceneObject *)value4)->z - value9 / value8;
        if ((resultFlag != '\0') || (*(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0x80 <= value7)) {
          *(undefined2 *)(entry + 0x48) = 4;
        }
      }
      break;
    case 4:
      if (((*(byte *)(entry + 0x4b) & 2) == 0) || (value <= *(int *)(value8 + 0x1c))) {
        value12 = RandomModulo(0x1000);
        *(undefined4 *)(value8 + 0x24) = value12;
        value12 = RandomModulo(0x1e5);
        *(undefined4 *)(value8 + 0x28) = value12;
        value4 = RandomModulo(0x1e);
        *(int *)(value8 + 0x2c) = value4 + 0x50;
        *(undefined2 *)(entry + 0x48) = 5;
        CEntities::SelectScriptAttachmentSequence(value7,2);
      }
      else {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      break;
    case 5:
      *(short *)(value4 + 0xa0) = (short)(*(short *)(value4 + 0xa0) * 0x30) >> 6;
      if (*(int *)(value8 + 0x2c) < 8) {
        CEntities::SelectScriptAttachmentSequence(value7,1);
        *(ushort *)(entry + 0x48) = ((0 < *(int *)(entry + 0x4c)) - 1 & 4) + 2;
      }
      else {
        *intCursor = *intCursor -
                   ((int)(short)(&g_SinCosTable12Bit)[*(int *)(value8 + 0x24) - 0x400U & 0xfff] *
                    *(int *)(value8 + 0x2c) >> 0xc);
        ((EntitySceneObject *)value4)->z =
             ((EntitySceneObject *)value4)->z -
             ((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value8 + 0x24) & 0xfff] *
              *(int *)(value8 + 0x2c) >> 0xc);
        ((EntitySceneObject *)value4)->y =
             ((EntitySceneObject *)value4)->y -
             ((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value8 + 0x28) & 0xfff] *
              *(int *)(value8 + 0x2c) >> 0xc);
        value11 = *(uint *)(value8 + 0x2c);
        value4 = RandomModulo(2);
        *(uint *)(value8 + 0x2c) = value11 - value11 / (value4 + 3U);
      }
      break;
    case 6:
      value10 = value / 0x6e;
      if (value10 == 0) {
        value10 = 1;
      }
      *intCursor = *intCursor - value6 / value10;
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y - value5 / value10;
      ((EntitySceneObject *)value4)->z = ((EntitySceneObject *)value4)->z - value9 / value10;
      if ((value < 0x32) || (value10 == 1)) {
        *(undefined2 *)(entry + 0x48) = 0;
        *(undefined4 *)(entry + 0x4c) = 0x3c;
        CEntities::SelectScriptAttachmentSequence(value7,0);
        *intCursor = *(int *)(value8 + 0xc);
        ((EntitySceneObject *)value4)->y = *(undefined4 *)(value8 + 0x10);
        ((EntitySceneObject *)value4)->z = *(undefined4 *)(value8 + 0x14);
        ((EntitySceneObject *)value4)->yaw = 0;
        *(undefined2 *)(value4 + 0xa0) = 0;
      }
      break;
    case 7:
      if ((*(byte *)(entry + 0x4b) & 1) == 0) {
        *(undefined2 *)(entry + 0x48) = 6;
      }
      else {
        CEntities::ProcessEntityDeathAndRelease(entry,1);
      }
    }
  }
LAB_00422b74:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

