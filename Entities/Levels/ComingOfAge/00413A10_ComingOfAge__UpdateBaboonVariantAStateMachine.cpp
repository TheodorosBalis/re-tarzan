#include "tarzan_ghidra_types.hpp"

// Address: 0x00413A10
// Label: ComingOfAge::UpdateBaboonVariantAStateMachine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBaboonVariantAStateMachine(int entry,int sceneObject,int attachment,int flags)

{
  short state;
  int value;
  undefined4 stateFlags;
  uint stateFlags2;
  int value2;
  int value3;
  short state2;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  state = *(short *)(attachment + 0x18);
  value = CEntities::ComputeEntitySceneObjectDataDistance3D
                    (sceneObject + 0xc,g_PlayerEntitySceneObjectData);
  switch(*(undefined2 *)(entry + 0x48)) {
  case 0:
    value = RandomModulo(0x14);
    *(int *)(entry + 0x4c) = value + 0x14;
    *(undefined2 *)(entry + 0x48) = 1;
    return;
  case 1:
    value2 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value2;
    if (value < 0x7d1) {
      if (value < 500) goto LAB_00413aff;
      if (value2 < 0x23) {
        stateFlags2 = RandomModulo(10);
        *(ushort *)(entry + 0x48) = (-(ushort)(1 < stateFlags2) & 4) + 0xd;
        return;
      }
    }
    else if (value2 < 1) {
      stateFlags = RandomModulo(4);
      switch(stateFlags) {
      case 0:
      case 1:
        *(undefined2 *)(entry + 0x48) = 0xf;
        return;
      case 2:
      case 3:
        *(undefined2 *)(entry + 0x48) = 0xd;
        return;
      default:
        return;
      }
    }
    if (value < 500) {
LAB_00413aff:
      stateFlags2 = RandomModulo(10);
      *(ushort *)(entry + 0x48) = (-(ushort)(1 < stateFlags2) & 2) + 0xd;
      return;
    }
    break;
  case 0xd:
    *(undefined2 *)(entry + 0x48) = 0xe;
    *(undefined4 *)(entry + 0x4c) = 0;
    CEntities::SelectScriptAttachmentSequence(attachment,4);
    return;
  case 0xe:
    if (flags == 0x101) {
      if (*(int *)(entry + 0x4c) == 0) {
        value = RandomModulo(2);
        *(int *)(entry + 0x4c) = value + 2;
        *(int *)(entry + 0x50) = *(short *)(attachment + 0x16) + -3;
      }
    }
    else if ((flags == 0x102) && (1 < *(int *)(entry + 0x4c))) {
      *(int *)(entry + 0x4c) = *(int *)(entry + 0x4c) + -1;
      *(undefined2 *)(attachment + 0x16) = *(undefined2 *)(entry + 0x50);
    }
    if (state == 0) {
      *(undefined2 *)(entry + 0x48) = 0;
      return;
    }
    break;
  case 0xf:
    *(undefined2 *)(entry + 0x48) = 0x13;
    CEntities::SelectScriptAttachmentSequence(attachment,1);
    return;
  case 0x11:
    value = GetAngleFromXZVector12Bit
                      (*(int *)(sceneObject + 0x14) - *(int *)(g_PlayerEntitySceneObjectData + 8),
                       *(int *)(sceneObject + 0x1c) - *(int *)(g_PlayerEntitySceneObjectData + 0x10));
    value = (value - *(short *)(sceneObject + 0xa2)) * 0x100000 >> 0x14;
    if ((-0x1f5 < value) && (value < 0x1f5)) {
      CEntities::SelectScriptAttachmentSequence(attachment,7);
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfeff;
      *(undefined2 *)(entry + 0x48) = 0x12;
      return;
    }
    goto LAB_00413d93;
  case 0x12:
    if ((flags == 0xb) && ((*(ushort *)(entry + 0x4a) & 0x100) == 0)) {
      *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) | 0x100;
      GetSceneAttachmentWorldPositionByMask(sceneObject,0x100,&localState3);
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
        state2 = ((short)((value2 >> 6) / 0x50) + (short)(value2 >> 0x1f)) -
                (short)((longlong)(value2 >> 6) * 0x66666667 >> 0x3f);
        *(short *)(value + 0x18) = state2;
        if (state2 == 0) {
          *(undefined2 *)(value + 0x18) = 1;
        }
        stateFlags2 = (uint)*(ushort *)(value + 0x18);
        value2 = *(int *)(g_PlayerEntitySceneObject + 0x18);
        value3 = *(int *)(g_PlayerEntitySceneObject + 0x1c);
        value4 = *(int *)(g_PlayerEntitySceneObject + 0x50);
        *(int *)(value + 0xc) =
             (int)(localState3 -
                  ((*(int *)(g_PlayerEntitySceneObject + 0x14) -
                   *(int *)(g_PlayerEntitySceneObject + 0x48)) * stateFlags2 +
                  *(int *)(g_PlayerEntitySceneObject + 0x14))) / (int)stateFlags2;
        *(int *)(value + 0x14) = (int)(localState - ((value3 - value4) * stateFlags2 + value3)) / (int)stateFlags2;
        *(uint *)(value + 0x10) =
             (*(int *)(value + 0x1c) / 2) * stateFlags2 + (localState2 - value2) / (int)stateFlags2;
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
    if (state != 0) {
      return;
    }
LAB_00413d93:
    *(undefined2 *)(entry + 0x48) = 0;
  }
  return;
}

