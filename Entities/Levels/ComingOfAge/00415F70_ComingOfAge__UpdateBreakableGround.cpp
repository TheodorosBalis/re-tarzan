#include "tarzan_ghidra_types.hpp"

// Address: 0x00415F70
// Label: ComingOfAge::UpdateBreakableGround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComingOfAge::UpdateBreakableGround(int entry)

{
  int *intCursor;
  uint *dataCursor2;
  uint value9;
  char resultFlag;
  short shortValue2;
  int value5;
  int *intCursor2;
  int value6;
  int value7;
  int value;
  int value2;
  undefined4 value8;
  uint *dataCursor;
  int value3;
  int value4;
  short shortValue;
  uint localState;
  
  value5 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (value5 == 0) goto LAB_00416384;
  if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
    value7 = *(int *)(value5 + 0x10);
    value8 = *(undefined4 *)(value5 + 0xc);
    intCursor = (int *)(value5 + 0xc);
    value3 = *(int *)(value5 + 0x14) + -0x29c;
    intCursor2 = (int *)CEntities::SpawnEntityByTypeAtPosition(value8,value7 + 0x1f8,value3,0x178,0x11);
    if ((intCursor2 != (int *)0x0) && (*intCursor2 != 0)) {
      *(undefined2 *)(intCursor2[0xe] + 0xc) = 0x200c;
      *(undefined4 *)(intCursor2[0xe] + 0x10) = g_CurrentWorldSceneContext;
      *(undefined4 *)(intCursor2[0xe] + 0xb4) = 1;
      *(undefined4 *)(intCursor2[0xe] + 0xa8) = 7000;
      *(undefined4 *)(intCursor2[0xe] + 0xac) = 7000;
      *(undefined4 *)(intCursor2[0xe] + 0xb0) = 7000;
      value6 = CEntities::FindEntityAttachmentByFlags(intCursor2,0x10000000);
      if (value6 != 0) {
        *(undefined4 *)(value6 + 0x34) = 0x7fff;
        *(undefined4 *)(value6 + 0x524) = 0x200;
        *(undefined4 *)(value6 + 0x10) = 8;
      }
    }
    value7 = CEntities::SpawnEntityByTypeAtPosition(value8,value7 + 0xb8,value3,0x14,0x11);
    if (value7 != 0) {
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0xb4) = 1;
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0xa8) = 9000;
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0xac) = 9000;
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0xb0) = 9000;
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0x30) = 0x800;
      *(undefined4 *)(*(int *)(value7 + 0x38) + 0x6c) = 0xffffff00;
    }
    value7 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value7;
    if (value7 < 0) {
      value7 = *(int *)(value5 + 0x10);
      value4 = *(int *)(value5 + 0x14) + -0x29c;
      value3 = *intCursor;
      value6 = CEntities::SpawnEntityByTypeAtPosition(value3,value7 + 0x338,value4,0x14,0x11);
      if (value6 != 0) {
        *(undefined4 *)(*(int *)(value6 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value6 + 0x38) + 0xa8) = 8000;
        *(undefined4 *)(*(int *)(value6 + 0x38) + 0xac) = 8000;
        *(undefined4 *)(*(int *)(value6 + 0x38) + 0xb0) = 8000;
        *(undefined4 *)(*(int *)(value6 + 0x38) + 0x30) = 0x800;
      }
      shortValue = 0;
      localState = 0;
      do {
        value6 = RandomModulo(0x180,value4,0x160,0x11);
        value6 = RandomModulo(0x400,(value7 + 0x238) - value6);
        value = RandomModulo(0x200);
        value6 = CEntities::SpawnEntityByTypeAtPosition((value3 - value6) + value);
        if ((value6 != 0) &&
           (value = CEntities::FindEntityAttachmentByFlags(value6,0x20000000), value != 0)) {
          value2 = RandomModulo(0x1e);
          value8 = RandomModulo(0x2000);
          *(int *)(value + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[localState - 0x400 & 0xfff] * (value2 + 0x32) >> 0xc
          ;
          *(int *)(value + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[localState & 0xfff] * (value2 + 0x32) >> 0xc;
          shortValue2 = RandomModulo(0x80);
          *(short *)(value + 0x54) = -0x60 - shortValue2;
          *(int *)(value + 0x24) = value7 + 0xa38;
          *(undefined2 *)(*(int *)(value6 + 0x38) + 0xc) = 0x200b;
          *(undefined4 *)(*(int *)(value6 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
          *(undefined4 *)(*(int *)(value6 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value6 + 0x38) + 0xa8) = value8;
          *(undefined4 *)(*(int *)(value6 + 0x38) + 0xac) = value8;
          *(undefined4 *)(*(int *)(value6 + 0x38) + 0xb0) = value8;
          *(undefined2 *)(value + 0x56) = 0xff00;
          *(short *)(*(int *)(value6 + 0x38) + 0xa2) = (shortValue + 1) * 0x200;
          *(undefined2 *)(*(int *)(value6 + 0x38) + 0xa0) = 0x400;
          value6 = RandomModulo(0x32);
          *(int *)(value + 0x18) = value6 + 0x1e;
          *(undefined4 *)(value + 0x10) = 0;
        }
        localState = localState + 0x200;
        shortValue = shortValue + 1;
      } while ((int)localState < 0x1000);
      DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value5 + 0x18),0x200a);
      value9 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
      value5 = g_PlayerContactSurfaceThisFrame;
      while ((value9 & 0x200) != 0) {
        value9 = *(uint *)(value5 + -0x24);
        value5 = value5 + -0x1c;
      }
      dataCursor = (uint *)(value5 + 0x14);
      value9 = *(uint *)(value5 + 0x14);
      while ((value9 & 0x200) != 0) {
        *dataCursor = value9 | 0x100;
        dataCursor2 = dataCursor + 7;
        dataCursor = dataCursor + 7;
        value9 = *dataCursor2;
      }
      PlayAudioById(0xce,(int *)0,(undefined4 *)intCursor);
      PlayForceFeedbackEffect_Stub(0,3,0x14);
      CEntities::UnlinkEntityFromProcessingList(entry);
    }
    else {
      value8 = RandomModulo(4);
      switch(value8) {
      case 0:
        value8 = 0xd8;
        break;
      case 1:
        value8 = 0xd9;
        break;
      case 2:
        value8 = 0xda;
        break;
      case 3:
        value8 = 0xdb;
        break;
      default:
        goto switchD_00416333_default;
      }
      PlayAudioById(value8,(int *)0,(undefined4 *)intCursor);
    }
  }
switchD_00416333_default:
  *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
LAB_00416384:
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

