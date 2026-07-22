#include "tarzan_ghidra_types.hpp"

// Address: 0x0042A5A0
// Label: GoingApe::UpdateBirdCarriedThrowable
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateBirdCarriedThrowable(int entry,int sceneObject)

{
  int *intCursor;
  ushort value13;
  int value4;
  int value5;
  int value6;
  int value7;
  int value8;
  int value9;
  int value10;
  int value;
  int value2;
  uint value11;
  uint value12;
  int value3;
  
  value9 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value9 != 0) {
    value3 = 0;
    value11 = 0;
    value10 = *(int *)(sceneObject + 0x14) - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value2 = *(int *)(sceneObject + 0x1c) - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value10 = SqrtToInt(value2 * value2 + value10 * value10);
    value12 = value10 >> 6;
    if (((int)value12 < 0x200) && ((*(byte *)(entry + 0x4b) & 1) != 0)) {
      value11 = value12 * 2;
      value3 = (int)(short)(&g_SinCosTable12Bit)[(value12 & 0x7ff) * 2] >> 4;
      if (0 < *(int *)(entry + 0x50)) {
        value11 = ~value11 & 0xfff;
      }
    }
    *(short *)(sceneObject + 0xa0) =
         (short)((int)((value11 - (int)*(short *)(sceneObject + 0xa0)) * 0x100000) >> 0x17) +
         *(short *)(sceneObject + 0xa0);
    *(int *)(sceneObject + 0x40) = (value3 - *(int *)(sceneObject + 0x40) >> 3) + *(int *)(sceneObject + 0x40);
    value13 = *(ushort *)(entry + 0x4a);
    if ((value13 & 0x100) == 0) {
      if ((value13 & 0x80) != 0) {
        *(ushort *)(entry + 0x4a) = value13 & 0xff7f;
        value10 = CEntities::SpawnEntityByTypeAtPosition
                          (*(undefined4 *)(sceneObject + 0x14),*(undefined4 *)(sceneObject + 0x18),
                           *(undefined4 *)(sceneObject + 0x1c),0x1a,0x11);
        *(int *)(value9 + 0x28) = value10;
        if (value10 != 0) {
          *(byte *)(entry + 0x4b) = *(byte *)(entry + 0x4b) | 1;
        }
      }
    }
    else {
      value10 = *(int *)(*(int *)(value9 + 0x28) + 0x38);
      *(undefined4 *)(value10 + 0x14) = *(undefined4 *)(sceneObject + 0x14);
      *(undefined4 *)(value10 + 0x18) = *(undefined4 *)(sceneObject + 0x18);
      *(undefined4 *)(value10 + 0x1c) = *(undefined4 *)(sceneObject + 0x1c);
      intCursor = (int *)(*(int *)(*(int *)(value9 + 0x28) + 0x38) + 0x18);
      *intCursor = *intCursor + *(int *)(sceneObject + 0x40) + 0x28;
    }
    if ((((int)value12 < 100) && (*(int *)(entry + 0x50) < 1)) &&
       ((*(byte *)(entry + 0x4b) & 1) != 0)) {
      if (*(short *)(value9 + 0x20) == 0x10) {
        PlayAudioById(0x14d,(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
      }
      value10 = RandomModulo(0x1e);
      *(int *)(entry + 0x50) = value10 + 0x32;
      value10 = *(int *)(sceneObject + 0x3c);
      value2 = *(int *)(sceneObject + 0x14);
      value3 = *(int *)(sceneObject + 0x1c);
      value4 = *(int *)(sceneObject + 0x44);
      value5 = *(int *)(g_PlayerEntitySceneObjectData + 8);
      value6 = *(int *)(g_PlayerEntitySceneObject + 0x54);
      value7 = *(int *)(g_PlayerEntitySceneObject + 0x5c);
      value8 = *(int *)(g_PlayerEntitySceneObjectData + 0x10);
      value = SqrtToInt((((*(int *)(g_PlayerEntitySceneObject + 0x58) +
                           *(int *)(g_PlayerEntitySceneObjectData + 0xc)) -
                          (*(int *)(sceneObject + 0x18) + *(int *)(sceneObject + 0x40))) * 2) / 6);
      value11 = (value >> 6) + 1;
      if (5 < (int)value11) {
        value = CEntities::CreateEntityAttachment(*(undefined4 *)(value9 + 0x28),0x9c,0x10000000);
        if (value == 0) {
          CEntities::ReleaseEntityToFreeList(*(undefined4 *)(value9 + 0x28));
          *(undefined4 *)(value9 + 0x28) = 0;
          *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfe7f;
          return;
        }
        *(short *)(value + 0x18) = (short)value11;
        *(undefined4 *)(value + 0x1c) = 6;
        *(undefined1 *)(value + 0x20) = 0;
        *(undefined4 *)(value + 0x10) = 0;
        *(int *)(value + 0xc) = ((value10 + value2) - (value6 + value5)) / (int)(value11 & 0xffff);
        *(int *)(value + 0x14) = ((value4 + value3) - (value7 + value8)) / (int)(value11 & 0xffff);
        *(ushort *)(entry + 0x4a) = *(ushort *)(entry + 0x4a) & 0xfe7f;
        return;
      }
    }
    else {
      *(int *)(entry + 0x50) = *(int *)(entry + 0x50) + -1;
    }
  }
  return;
}

