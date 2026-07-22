#include "tarzan_ghidra_types.hpp"

// Address: 0x0048B3B0
// Label: CEntities::UpdateThrowableFromPlayer3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateThrowableFromPlayer3D(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  int value;
  byte *value6;
  char resultFlag;
  int value2;
  int value3;
  int value4;
  uint value5;
  
  value = entity->sceneObjects;
  if ((value == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x800), value2 == 0))
  goto LAB_0048b6fd;
  switch(*(undefined2 *)(entry + 0x48)) {
  case 2:
  case 3:
    goto switchD_0048b3ef_caseD_2;
  default:
    goto switchD_0048b3ef_caseD_4;
  case 5:
    *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + -0xe3;
    value2 = GetSceneAttachmentWorldPositionByMask
                      (g_PlayerEntitySceneObject,0x100,(undefined4 *)(&((EntitySceneObject *)value)->x));
    if (value2 != 0) {
      value2 = ((EntitySceneObject *)value)->next;
      if (value2 != 0) {
        *(undefined4 *)(value2 + 0x14) = ((EntitySceneObject *)value)->x;
        *(undefined4 *)(value2 + 0x18) = ((EntitySceneObject *)value)->y;
        *(undefined4 *)(value2 + 0x1c) = ((EntitySceneObject *)value)->z;
        *(undefined4 *)(value2 + 0x3c) = *(undefined4 *)(value + 0x3c);
        *(undefined4 *)(value2 + 0x40) = *(undefined4 *)(value + 0x40);
        *(undefined4 *)(value2 + 0x44) = *(undefined4 *)(value + 0x44);
      }
      goto LAB_0048b6fd;
    }
    goto switchD_0048b69c_caseD_2027;
  case 6:
    goto switchD_0048b3ef_caseD_6;
  case 7:
    break;
  }
  *(undefined2 *)(entry + 0x48) = 2;
switchD_0048b3ef_caseD_2:
  value4 = *(int *)(value2 + 0x1c);
  if ((*(int *)(value2 + 0x10) != value4) &&
     (value3 = *(int *)(value2 + 0x10) - *(int *)(value2 + 0x18), *(int *)(value2 + 0x10) = value3,
     value3 < value4)) {
    *(int *)(value2 + 0x10) = value4;
  }
  value3 = *(int *)(value2 + 0x20) + *(int *)(value2 + 0x28);
  *(int *)(value2 + 0x20) = value3;
  value4 = *(int *)(value2 + 0x2c);
  if (value4 < value3) {
    *(int *)(value2 + 0x20) = value4;
  }
  if (*(int *)(value2 + 0x20) < -value4) {
    *(int *)(value2 + 0x20) = -value4;
  }
  ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value2 + 0x20);
  if (-0x40 < *(int *)(value + 0x40)) {
    *(int *)(value + 0x40) = *(int *)(value + 0x40) + -4;
  }
  if (((*(byte *)(entry + 0x4a) & 1) != 0) &&
     (value6 = *(byte **)(entry + 0x50), value6 != (byte *)0x0)) {
    if ((*value6 & 1) == 0) {
      *(undefined4 *)(entry + 0x50) = 0;
    }
    else if (*(int *)(value6 + 0x38) != 0) {
      if (((EntitySceneObject *)value)->y < *(int *)(*(int *)(value6 + 0x38) + 0x18)) {
        ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + 6;
      }
      if (*(int *)(*(int *)(value6 + 0x38) + 0x18) < ((EntitySceneObject *)value)->y) {
        ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + -6;
      }
    }
  }
  if (*(char *)(value + 0x74) == '\0') {
    *(undefined2 *)(entry + 0x48) = 6;
  }
  else {
    *(char *)(value + 0x74) = *(char *)(value + 0x74) + -1;
  }
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(value);
  resultFlag = CEntities::CheckEntitySceneObjectVerticalImpact(value);
  if (resultFlag != '\0') {
    if ((*(byte *)(entry + 0x4a) & 8) == 0) {
      value4 = *(int *)(value2 + 0x10) >> 1;
      *(int *)(value2 + 0x20) = -(*(int *)(value2 + 0x20) >> 1);
      *(int *)(value2 + 0x10) = value4;
      *(ushort *)(entry + 0x48) = ((1 < value4) - 1 & 3) + 3;
    }
    else {
      *(undefined2 *)(entry + 0x48) = 6;
    }
  }
  value5 = (int)*(uint *)(value2 + 0x10) >> 0x1f;
  intCursor = (int *)(&((EntitySceneObject *)value)->x);
  value4 = (*(uint *)(value2 + 0x10) ^ value5) - value5;
  *intCursor = ((EntitySceneObject *)value)->x -
            ((short)(&g_SinCosTable12Bit)[*(int *)(entry + 0x4c) - 0x400U & 0xfff] * value4 >> 0xc)
  ;
  ((EntitySceneObject *)value)->z =
       ((EntitySceneObject *)value)->z -
       ((short)(&g_SinCosTable12Bit)[*(uint *)(entry + 0x4c) & 0xfff] * value4 >> 0xc);
  if ((*(byte *)(entry + 0x4a) & 2) != 0) {
    value4 = ((EntitySceneObject *)value)->next;
    if (value4 != 0) {
      *(int *)(value4 + 0x14) = *intCursor;
      *(undefined4 *)(value4 + 0x18) = ((EntitySceneObject *)value)->y;
      *(undefined4 *)(value4 + 0x1c) = ((EntitySceneObject *)value)->z;
      *(undefined4 *)(value4 + 0x3c) = *(undefined4 *)(value + 0x3c);
      *(undefined4 *)(value4 + 0x40) = *(undefined4 *)(value + 0x40);
      *(undefined4 *)(value4 + 0x44) = *(undefined4 *)(value + 0x44);
    }
    CEntities::SpawnEntityByTypeAtPosition
              (*intCursor,((EntitySceneObject *)value)->y,((EntitySceneObject *)value)->z,0x18,0x11);
  }
  if (*(short *)(entry + 0x48) == 3) {
    *(short *)(value + 0xa0) = *(short *)(value + 0xa0) + 0x200;
  }
  if ((*(byte *)(value + 0x13c) & 2) == 0) goto LAB_0048b6fd;
switchD_0048b3ef_caseD_6:
  if (((*(ushort *)(entry + 0x4a) & 8) != 0) && (*(char *)(value + 0x74) != '\0')) {
    CEntities::ApplyPowerFruitAreaDamage(value);
    CEntities::SpawnPowerFruitExplosionDebrisCloud(value);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
  if (((*(ushort *)(entry + 0x4a) & 4) != 0) && (*(char *)(value + 0x74) == '\0')) {
    CEntities::SpawnPowerFruitBurstDebris(value,value2);
    CEntities::ReleaseEntityToFreeList((byte *)entry);
    return;
  }
switchD_0048b3ef_caseD_4:
  PlayAudioById(0xb8,0,(undefined4 *)(&((EntitySceneObject *)value)->x));
  value2 = CEntities::SpawnEntityByTypeAtPosition
                    (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y,
                     ((EntitySceneObject *)value)->z,0x13,0x11);
  if ((value2 != 0) && (value2 = *(int *)(value2 + 0x38), value2 != 0)) {
    switch(*(undefined2 *)(value + 0xc)) {
    case 0x2026:
      *(undefined4 *)(value2 + 0x24) = 0x600;
      *(undefined4 *)(value2 + 0x20) = 0x1000;
      *(undefined4 *)(value2 + 0x28) = 0x1000;
      break;
    default:
      goto switchD_0048b69c_caseD_2027;
    case 0x202b:
      *(undefined4 *)(value2 + 0x28) = 0x1000;
      *(undefined4 *)(value2 + 0x20) = 0x600;
      *(undefined4 *)(value2 + 0x24) = 0x600;
      break;
    case 0x202c:
      *(undefined4 *)(value2 + 0x20) = 0x1000;
      *(undefined4 *)(value2 + 0x24) = 0x800;
      *(undefined4 *)(value2 + 0x28) = 0x800;
      break;
    case 0x202e:
      *(undefined4 *)(value2 + 0x28) = 0x600;
      *(undefined4 *)(value2 + 0x20) = 0x1000;
      *(undefined4 *)(value2 + 0x24) = 0x1000;
    }
    *(undefined4 *)(value2 + 0x30) = 0;
  }
switchD_0048b69c_caseD_2027:
  CEntities::ReleaseEntityToFreeList((byte *)entry);
LAB_0048b6fd:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

