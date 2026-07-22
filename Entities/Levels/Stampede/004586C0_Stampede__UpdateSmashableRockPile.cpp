#include "tarzan_ghidra_types.hpp"

// Address: 0x004586C0
// Label: Stampede::UpdateSmashableRockPile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateSmashableRockPile(int entry)

{
  ushort *dataCursor;
  int value;
  char resultFlag;
  int value2;
  int value3;
  int *intCursor;
  short *value5;
  undefined4 value4;
  int localState;
  int localState3 [2];
  int localState2;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    value3 = *(int *)(value2 + 0xc);
    if (value3 == 7) {
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState3);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState3[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState2;
      }
      if ((g_StampedeElephantsEntity != 0) &&
         (*(int *)(*(int *)(g_StampedeElephantsEntity + 0x38) + 0x1c) + -0x27c <=
          *(int *)(*(int *)(value + 0x38) + 0x1c))) {
        *(undefined4 *)(value2 + 0xc) = 0xc;
      }
    }
    else if (value3 == 0xb) {
      entry = value2 + 0x20;
      value5 = (short *)(value2 + 0x144);
      localState = 3;
      intCursor = (int *)(value2 + 0x14);
      do {
        value3 = CEntities::AdvanceBounceMotionAndReturnImpact(*intCursor,entry);
        if (value3 == 0) {
LAB_00458805:
          value3 = intCursor[0x57];
        }
        else {
          intCursor[0x57] = intCursor[0x57] + 1;
          *(int *)(*intCursor + 0xa8) = *(int *)(*intCursor + 0xa8) >> 1;
          *(int *)(*intCursor + 0xac) = *(int *)(*intCursor + 0xac) >> 1;
          *(int *)(*intCursor + 0xb0) = *(int *)(*intCursor + 0xb0) >> 1;
          value3 = intCursor[0x57];
          if (value3 < 3) {
            value3 = RandomModulo(6);
            if (value3 == 0) {
              value3 = *(int *)(value + 0x38) + 0x14;
              value4 = 0x1cb;
            }
            else if (value3 == 1) {
              value3 = *(int *)(value + 0x38) + 0x14;
              value4 = 0x1cc;
            }
            else {
              if (value3 != 2) goto LAB_00458805;
              value3 = *(int *)(value + 0x38) + 0x14;
              value4 = 0x1cd;
            }
            PlayAudioById(value4,(int *)0,(undefined4 *)value3);
            goto LAB_00458805;
          }
        }
        if (3 < value3) {
          *(ushort *)(*intCursor + 0xe) = *(ushort *)(*intCursor + 0xe) & 0x7fff;
        }
        *(short *)(*intCursor + 0xa0) = *(short *)(*intCursor + 0xa0) + value5[-2] * 2;
        *(short *)(*intCursor + 0xa2) = *(short *)(*intCursor + 0xa2) + *value5 * 2;
        *(short *)(*intCursor + 0xa4) = *(short *)(*intCursor + 0xa4) + value5[2] * 2;
        entry = entry + 0x60;
        value5 = value5 + 8;
        localState = localState + -1;
        intCursor = intCursor + 1;
      } while (localState != 0);
      value3 = *(int *)(value2 + 0x10) + 1;
      *(int *)(value2 + 0x10) = value3;
      if (value3 == 3) {
        value2 = *(int *)(value + 0x38);
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (*(undefined4 *)(value2 + 0x14),*(int *)(value2 + 0x18) + -200,
                                   *(int *)(value2 + 0x1c) + -0x100,0x178,0x11);
        if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
          *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
          *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2054;
          *(undefined4 *)(intCursor[0xe] + 0x6c) = 0xffffff80;
          value2 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
          if (value2 != 0) {
            value4 = *(undefined4 *)(*(int *)(value + 0x38) + 0x18);
            *(undefined4 *)(value2 + 0x524) = 0x200;
            *(undefined4 *)(value2 + 0x34) = value4;
          }
        }
      }
    }
    else if (value3 == 0xc) {
      dataCursor = (ushort *)(*(int *)(value2 + 0x14) + 0xe);
      *dataCursor = *dataCursor | 0x8000;
      dataCursor = (ushort *)(*(int *)(value2 + 0x18) + 0xe);
      *dataCursor = *dataCursor | 0x8000;
      dataCursor = (ushort *)(*(int *)(value2 + 0x1c) + 0xe);
      *dataCursor = *dataCursor | 0x8000;
      PlayAudioById(0x1c6,0,*(int *)(value + 0x38) + 0x14);
      dataCursor = (ushort *)(*(int *)(value + 0x38) + 0xe);
      *dataCursor = *dataCursor & 0x7fff;
      *(undefined4 *)(value2 + 0xc) = 0xb;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

