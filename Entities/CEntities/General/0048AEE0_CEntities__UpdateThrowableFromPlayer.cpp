#include "tarzan_ghidra_types.hpp"

// Address: 0x0048AEE0
// Label: CEntities::UpdateThrowableFromPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateThrowableFromPlayer(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  short shortValue;
  int value2;
  undefined4 value9;
  byte *value10;
  int value3;
  char resultFlag;
  int value4;
  int value5;
  uint value6;
  uint value7;
  uint value8;
  int value;
  
  value2 = entity->sceneObjects;
  if ((value2 == 0) ||
     (value4 = CEntities::FindEntityAttachmentByFlags(entry,0x800), value4 == 0))
  goto LAB_0048b34a;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 2:
  case 3:
    goto switchD_0048af20_caseD_2;
  default:
    goto switchD_0048af20_caseD_4;
  case 5:
    *(short *)(value2 + 0xa0) = *(short *)(value2 + 0xa0) + -0xb6;
    value4 = GetSceneAttachmentWorldPositionByMask
                      (g_PlayerEntitySceneObject,0x100,(undefined4 *)(&((EntitySceneObject *)value2)->x));
    if (value4 != 0) {
      value4 = ((EntitySceneObject *)value2)->next;
      if (value4 != 0) {
        *(undefined4 *)(value4 + 0x14) = ((EntitySceneObject *)value2)->x;
        *(undefined4 *)(value4 + 0x18) = ((EntitySceneObject *)value2)->y;
        *(undefined4 *)(value4 + 0x1c) = ((EntitySceneObject *)value2)->z;
        *(undefined4 *)(value4 + 0x3c) = *(undefined4 *)(value2 + 0x3c);
        *(undefined4 *)(value4 + 0x40) = *(undefined4 *)(value2 + 0x40);
        *(undefined4 *)(value4 + 0x44) = *(undefined4 *)(value2 + 0x44);
      }
      goto LAB_0048b34a;
    }
    goto switchD_0048b2e9_caseD_2027;
  case 6:
    goto switchD_0048af20_caseD_6;
  case 7:
    break;
  }
  *(undefined2 *)(entry + 0x48) = 2;
  GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x100,&((EntitySceneObject *)value2)->x);
  ((EntitySceneObject *)value2)->surfacePathIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
  ((EntitySceneObject *)value2)->surfaceIndex = *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
  value9 = *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
  *(undefined4 *)(value2 + 0x6c) = 0xffffffe2;
  ((EntitySceneObject *)value2)->pad108 = value9;
  ComputeEntitySceneObjectCollisionMoveDelta
            ((-(uint)(*(char *)(value2 + 0x75) != '\0') & 0xfffffec0) + 0xa0,0,value2);
switchD_0048af20_caseD_2:
  value = *(int *)(value4 + 0x1c);
  if ((*(int *)(value4 + 0x10) != value) &&
     (value5 = *(int *)(value4 + 0x10) - *(int *)(value4 + 0x18), *(int *)(value4 + 0x10) = value5,
     value5 < value)) {
    *(int *)(value4 + 0x10) = value;
  }
  value5 = *(int *)(value4 + 0x20) + *(int *)(value4 + 0x28);
  *(int *)(value4 + 0x20) = value5;
  value = *(int *)(value4 + 0x2c);
  if (value < value5) {
    *(int *)(value4 + 0x20) = value;
  }
  if (*(int *)(value4 + 0x20) < -value) {
    *(int *)(value4 + 0x20) = -value;
  }
  ((EntitySceneObject *)value2)->y = ((EntitySceneObject *)value2)->y + *(int *)(value4 + 0x20);
  if (-0x40 < *(int *)(value2 + 0x40)) {
    *(int *)(value2 + 0x40) = *(int *)(value2 + 0x40) + -4;
  }
  if (((*(byte *)(entry + 0x4a) & 1) != 0) &&
     (value10 = *(byte **)(entry + 0x50), value10 != (byte *)0x0)) {
    if ((*value10 & 1) == 0) {
      *(undefined4 *)(entry + 0x50) = 0;
    }
    else {
      value = *(int *)(value10 + 0x38);
      if (value != 0) {
        value5 = ((EntitySceneObject *)value2)->y;
        value3 = *(int *)(value + 0x18);
        value7 = (value5 - value3) + 0x40;
        value6 = (((EntitySceneObject *)value2)->x - *(int *)(value + 0x14)) + 0x40;
        value8 = (int)value6 >> 0x1f;
        if ((int)((value7 ^ (int)value7 >> 0x1f) - ((int)value7 >> 0x1f)) <
            (int)((value6 ^ value8) - value8)) {
          if ((int)value7 < 0) {
LAB_0048b0aa:
            ((EntitySceneObject *)value2)->y = value5 + 2;
          }
          else {
            ((EntitySceneObject *)value2)->y = value5 + -8;
          }
        }
        else if ((int)value7 < 0) {
          if ((~value7 + 1 & 0xfffffff0) != 0) goto LAB_0048b0aa;
          ((EntitySceneObject *)value2)->y = value3 + -0x40;
        }
        else if ((int)value7 >> 4 == 0) {
          ((EntitySceneObject *)value2)->y = value3 + -0x40;
        }
        else {
          ((EntitySceneObject *)value2)->y = value5 - ((int)value7 >> 4);
        }
      }
    }
  }
  if (*(char *)(value2 + 0x74) == '\0') {
    *(undefined2 *)(entry + 0x48) = 6;
  }
  else {
    *(char *)(value2 + 0x74) = *(char *)(value2 + 0x74) + -1;
  }
  resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value2);
  if (resultFlag != '\0') {
    if ((*(byte *)(entry + 0x4a) & 8) == 0) {
      value = *(int *)(value4 + 0x10) >> 1;
      *(int *)(value4 + 0x20) = -(*(int *)(value4 + 0x20) >> 1);
      *(int *)(value4 + 0x10) = value;
      *(ushort *)(entry + 0x48) = ((1 < value) - 1 & 3) + 3;
    }
    else {
      *(undefined2 *)(entry + 0x48) = 6;
    }
  }
  value6 = *(uint *)(value4 + 0x10);
  if (*(char *)(value2 + 0x75) != '\0') {
    value6 = ~value6 + 1;
  }
  ComputeEntitySceneObjectCollisionMoveDelta(value6,0,value2);
  intCursor = (int *)(&((EntitySceneObject *)value2)->x);
  *intCursor = ((EntitySceneObject *)value2)->x + *(int *)(value2 + 0x54);
  ((EntitySceneObject *)value2)->z = ((EntitySceneObject *)value2)->z + *(int *)(value2 + 0x5c);
  if ((*(byte *)(entry + 0x4a) & 2) != 0) {
    value = ((EntitySceneObject *)value2)->next;
    if (value != 0) {
      *(int *)(value + 0x14) = *intCursor;
      *(undefined4 *)(value + 0x18) = ((EntitySceneObject *)value2)->y;
      *(undefined4 *)(value + 0x1c) = ((EntitySceneObject *)value2)->z;
      *(undefined4 *)(value + 0x3c) = *(undefined4 *)(value2 + 0x3c);
      *(undefined4 *)(value + 0x40) = *(undefined4 *)(value2 + 0x40);
      *(undefined4 *)(value + 0x44) = *(undefined4 *)(value2 + 0x44);
    }
    CEntities::SpawnEntityByTypeAtPosition
              (*intCursor,((EntitySceneObject *)value2)->y,((EntitySceneObject *)value2)->z,0x18,0x11);
  }
  if (((EntitySceneObject *)value2)->pad108 == 2) {
    shortValue = ((EntitySceneObject *)value2)->yaw;
    *(int *)(entry + 0x4c) = (int)shortValue;
    if (*(char *)(value2 + 0x75) == '\0') {
      *(uint *)(entry + 0x4c) = (int)shortValue ^ 0x800;
    }
    *(undefined2 *)(entry + 0x46) = 0x10;
    *(undefined4 *)(entry + 0x2c) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x80);
    *(undefined4 *)(entry + 0x30) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x84);
    goto LAB_0048b34a;
  }
  ((EntitySceneObject *)value2)->yaw = *(undefined2 *)(value2 + 0x132);
  if (*(short *)(entry + 0x48) == 3) {
    *(short *)(value2 + 0xa0) = *(short *)(value2 + 0xa0) + 0x200;
  }
  if ((*(byte *)(value2 + 0x13c) & 2) == 0) goto LAB_0048b34a;
switchD_0048af20_caseD_6:
  if (((*(ushort *)(entry + 0x4a) & 8) != 0) && (*(char *)(value2 + 0x74) != '\0')) {
    CEntities::ApplyPowerFruitAreaDamage(value2);
    CEntities::SpawnPowerFruitExplosionDebrisCloud(value2);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  if (((*(ushort *)(entry + 0x4a) & 4) != 0) && (*(char *)(value2 + 0x74) == '\0')) {
    CEntities::SpawnPowerFruitBurstDebris(value2,value4);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
switchD_0048af20_caseD_4:
  PlayAudioById(0xb8,0,(undefined4 *)(&((EntitySceneObject *)value2)->x));
  value4 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value2)->x,((EntitySceneObject *)value2)->y,
                     ((EntitySceneObject *)value2)->z,0x13,0x11);
  if ((value4 != 0) && (value4 = *(int *)(value4 + 0x38), value4 != 0)) {
    switch(*(undefined2 *)(value2 + 0xc)) {
    case 0x2026:
      *(undefined4 *)(value4 + 0x24) = 0x600;
      *(undefined4 *)(value4 + 0x20) = 0x1000;
      *(undefined4 *)(value4 + 0x28) = 0x1000;
      break;
    default:
      goto switchD_0048b2e9_caseD_2027;
    case 0x202b:
      *(undefined4 *)(value4 + 0x28) = 0x1000;
      *(undefined4 *)(value4 + 0x20) = 0x600;
      *(undefined4 *)(value4 + 0x24) = 0x600;
      break;
    case 0x202c:
      *(undefined4 *)(value4 + 0x20) = 0x1000;
      *(undefined4 *)(value4 + 0x24) = 0x800;
      *(undefined4 *)(value4 + 0x28) = 0x800;
      break;
    case 0x202e:
      *(undefined4 *)(value4 + 0x28) = 0x600;
      *(undefined4 *)(value4 + 0x20) = 0x1000;
      *(undefined4 *)(value4 + 0x24) = 0x1000;
    }
    *(undefined4 *)(value4 + 0x30) = 0;
  }
switchD_0048b2e9_caseD_2027:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
LAB_0048b34a:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

