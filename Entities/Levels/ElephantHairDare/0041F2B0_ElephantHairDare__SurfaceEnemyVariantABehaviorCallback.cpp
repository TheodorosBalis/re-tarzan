#include "tarzan_ghidra_types.hpp"

// Address: 0x0041F2B0
// Label: ElephantHairDare::SurfaceEnemyVariantABehaviorCallback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::SurfaceEnemyVariantABehaviorCallback
               (int arg1,int arg2,int arg3,int arg4)

{
  short shortValue;
  int value;
  undefined4 value5;
  uint value6;
  int value2;
  int value3;
  short shortValue2;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  shortValue = *(short *)(arg3 + 0x18);
  value = CEntities::ComputeEntitySceneObjectDataDistance3D
                    (arg2 + 0xc,g_PlayerEntitySceneObjectData);
  switch(*(undefined2 *)(arg1 + 0x48)) {
  case 0:
    value = RandomModulo(0x14);
    *(int *)(arg1 + 0x4c) = value + 0x14;
    *(undefined2 *)(arg1 + 0x48) = 1;
    return;
  case 1:
    value2 = *(int *)(arg1 + 0x4c) + -1;
    *(int *)(arg1 + 0x4c) = value2;
    if (value < 0x7d1) {
      if (value < 500) goto LAB_0041f39f;
      if (value2 < 0x23) {
        value6 = RandomModulo(10);
        *(ushort *)(arg1 + 0x48) = (-(ushort)(1 < value6) & 4) + 0xd;
        return;
      }
    }
    else if (value2 < 1) {
      value5 = RandomModulo(4);
      switch(value5) {
      case 0:
      case 1:
        *(undefined2 *)(arg1 + 0x48) = 0xf;
        return;
      case 2:
      case 3:
        *(undefined2 *)(arg1 + 0x48) = 0xd;
        return;
      default:
        return;
      }
    }
    if (value < 500) {
LAB_0041f39f:
      value6 = RandomModulo(10);
      *(ushort *)(arg1 + 0x48) = (-(ushort)(1 < value6) & 2) + 0xd;
      return;
    }
    break;
  case 0xd:
    *(undefined2 *)(arg1 + 0x48) = 0xe;
    *(undefined4 *)(arg1 + 0x4c) = 0;
    CEntities::SelectScriptAttachmentSequence(arg3,4);
    return;
  case 0xe:
    if (arg4 == 0x101) {
      if (*(int *)(arg1 + 0x4c) == 0) {
        value = RandomModulo(2);
        *(int *)(arg1 + 0x4c) = value + 2;
        *(int *)(arg1 + 0x50) = *(short *)(arg3 + 0x16) + -3;
      }
    }
    else if ((arg4 == 0x102) && (1 < *(int *)(arg1 + 0x4c))) {
      *(int *)(arg1 + 0x4c) = *(int *)(arg1 + 0x4c) + -1;
      *(undefined2 *)(arg3 + 0x16) = *(undefined2 *)(arg1 + 0x50);
    }
    if (shortValue == 0) {
      *(undefined2 *)(arg1 + 0x48) = 0;
      return;
    }
    break;
  case 0xf:
    *(undefined2 *)(arg1 + 0x48) = 0x13;
    CEntities::SelectScriptAttachmentSequence(arg3,1);
    return;
  case 0x11:
    value = GetAngleFromXZVector12Bit
                      (*(int *)(arg2 + 0x14) - *(int *)(g_PlayerEntitySceneObjectData + 8),
                       *(int *)(arg2 + 0x1c) - *(int *)(g_PlayerEntitySceneObjectData + 0x10));
    value = (value - *(short *)(arg2 + 0xa2)) * 0x100000 >> 0x14;
    if ((-0x1f5 < value) && (value < 0x1f5)) {
      CEntities::SelectScriptAttachmentSequence(arg3,7);
      *(ushort *)(arg1 + 0x4a) = *(ushort *)(arg1 + 0x4a) & 0xfeff;
      *(undefined2 *)(arg1 + 0x48) = 0x12;
      return;
    }
    goto LAB_0041f633;
  case 0x12:
    if ((arg4 == 0xb) && ((*(ushort *)(arg1 + 0x4a) & 0x100) == 0)) {
      *(ushort *)(arg1 + 0x4a) = *(ushort *)(arg1 + 0x4a) | 0x100;
      GetSceneAttachmentWorldPositionByMask(arg2,0x100,&localState3);
      value = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x1a,0x11);
      if (value == 0) {
        return;
      }
      value = CEntities::CreateEntityAttachment(value,0x9c,0x10000000);
      if (value != 0) {
        *(undefined4 *)(value + 0x1c) = 6;
        value2 = localState3 - *(int *)(g_PlayerEntitySceneObjectData + 8);
        value4 = localState - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
        value3 = localState2 - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
        value2 = SqrtToInt(value3 * value3 + value4 * value4 + value2 * value2);
        shortValue2 = ((short)((value2 >> 6) / 0x50) + (short)(value2 >> 0x1f)) -
                (short)((longlong)(value2 >> 6) * 0x66666667 >> 0x3f);
        *(short *)(value + 0x18) = shortValue2;
        if (shortValue2 == 0) {
          *(undefined2 *)(value + 0x18) = 1;
        }
        value6 = (uint)*(ushort *)(value + 0x18);
        value2 = *(int *)(g_PlayerEntitySceneObject + 0x18);
        value3 = *(int *)(g_PlayerEntitySceneObject + 0x1c);
        value4 = *(int *)(g_PlayerEntitySceneObject + 0x50);
        *(int *)(value + 0xc) =
             (int)(localState3 -
                  ((*(int *)(g_PlayerEntitySceneObject + 0x14) -
                   *(int *)(g_PlayerEntitySceneObject + 0x48)) * value6 +
                  *(int *)(g_PlayerEntitySceneObject + 0x14))) / (int)value6;
        *(int *)(value + 0x14) = (int)(localState - ((value3 - value4) * value6 + value3)) / (int)value6;
        *(uint *)(value + 0x10) =
             (*(int *)(value + 0x1c) / 2) * value6 + (localState2 - value2) / (int)value6;
        if ((*(int *)(g_PlayerEntitySceneObject + 0x58) < 0x40) &&
           (-0x40 < *(int *)(g_PlayerEntitySceneObject + 0x58))) {
          *(undefined1 *)(value + 0x20) = 0;
        }
        else {
          *(undefined1 *)(value + 0x20) = 2;
          *(short *)(value + 0x18) = *(short *)(value + 0x18) * 4;
        }
      }
    }
    if (shortValue != 0) {
      return;
    }
LAB_0041f633:
    *(undefined2 *)(arg1 + 0x48) = 0;
  }
  return;
}

