#include "tarzan_ghidra_types.hpp"

// Address: 0x00431AA0
// Label: GoingApe::UpdateSmashableGround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void GoingApe::UpdateSmashableGround(int entry)

{
  uint *dataCursor;
  int value4;
  int value5;
  int value6;
  uint value9;
  char resultFlag;
  short shortValue2;
  int value7;
  int *intCursor;
  int value;
  int value2;
  int value3;
  undefined4 value8;
  uint *dataCursor2;
  short shortValue;
  uint localState;
  
  value7 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
    value4 = *(int *)(value7 + 0x10);
    value5 = *(int *)(value7 + 0xc);
    value6 = *(int *)(value7 + 0x14);
    intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition(value5,value4 + 0xc0,value6,0x178,0x11);
    if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
      *(undefined2 *)(intCursor[0xe] + 0xc) = 0x200a;
      *(undefined4 *)(intCursor[0xe] + 0x10) = g_CurrentWorldSceneContext;
      *(undefined4 *)(intCursor[0xe] + 0xb4) = 1;
      *(undefined4 *)(intCursor[0xe] + 0xa8) = 7000;
      *(undefined4 *)(intCursor[0xe] + 0xac) = 7000;
      *(undefined4 *)(intCursor[0xe] + 0xb0) = 7000;
      value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
      if (value != 0) {
        *(undefined4 *)(value + 0x34) = 0x7fff;
        *(undefined4 *)(value + 0x524) = 0x200;
        *(undefined4 *)(value + 0x10) = 8;
      }
    }
    value = CEntities::SpawnEntityByTypeAtPosition
                       (*(undefined4 *)(g_PlayerEntitySceneObject + 0x14),
                        *(undefined4 *)(g_PlayerEntitySceneObject + 0x18),
                        *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c),0x14,0x11);
    if (value != 0) {
      *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
      *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 7000;
      *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 7000;
      *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 7000;
      *(undefined4 *)(*(int *)(value + 0x38) + 0x30) = 0x800;
      *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffff00;
    }
    value = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = value;
    if (value < 0) {
      value = CEntities::SpawnEntityByTypeAtPosition(value5,value4 + 0x80,value6,0x14,0x11);
      if (value != 0) {
        *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 7000;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 7000;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 7000;
        *(undefined4 *)(*(int *)(value + 0x38) + 0x30) = 0x800;
      }
      shortValue = 0;
      localState = 0;
      do {
        value = RandomModulo(0x40,0x160,0x11);
        value2 = RandomModulo(0x40);
        value = RandomModulo(0x40,(value6 - value) + value2);
        value2 = RandomModulo(0x40);
        value = RandomModulo(0x200,((value4 + 0x100) - value) + value2);
        value2 = RandomModulo(0x200);
        value = CEntities::SpawnEntityByTypeAtPosition((value5 - value) + value2);
        if ((value != 0) &&
           (value2 = CEntities::FindEntityAttachmentByFlags(value,0x20000000), value2 != 0))
        {
          value3 = RandomModulo(0x1e);
          value8 = RandomModulo(0x1c18);
          *(int *)(value2 + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[localState - 0x400 & 0xfff] * (value3 + 0x28) >> 0xc
          ;
          *(int *)(value2 + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[localState & 0xfff] * (value3 + 0x28) >> 0xc;
          shortValue2 = RandomModulo(0x80);
          *(short *)(value2 + 0x54) = -0x60 - shortValue2;
          *(int *)(value2 + 0x24) = value4 + 0x900;
          *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2009;
          *(undefined4 *)(*(int *)(value + 0x38) + 0x10) = g_CurrentWorldSceneContext;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = value8;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = value8;
          *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = value8;
          *(undefined2 *)(value2 + 0x56) = 0xff00;
          *(short *)(*(int *)(value + 0x38) + 0xa2) = (shortValue + 1) * 0x200;
          *(undefined2 *)(*(int *)(value + 0x38) + 0xa0) = 0x400;
          value = RandomModulo(0x32);
          *(int *)(value2 + 0x18) = value + 0x1e;
          *(undefined4 *)(value2 + 0x10) = 0;
        }
        localState = localState + 0x2aa;
        shortValue = shortValue + 1;
      } while ((int)localState < 0x1550);
      DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value7 + 0x18),0x2000);
      value9 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
      value4 = g_PlayerContactSurfaceThisFrame;
      while ((value9 & 0x200) != 0) {
        value9 = *(uint *)(value4 + -0x24);
        value4 = value4 + -0x1c;
      }
      dataCursor2 = (uint *)(value4 + 0x14);
      value9 = *(uint *)(value4 + 0x14);
      while ((value9 & 0x200) != 0) {
        *dataCursor2 = value9 | 0x100;
        dataCursor = dataCursor2 + 7;
        dataCursor2 = dataCursor2 + 7;
        value9 = *dataCursor;
      }
      PlayForceFeedbackEffect_Stub(0,3,0x14);
      PlayAudioById(0xce,(int *)0,(undefined4 *)value7 + 0xc);
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
        goto switchD_00431e50_default;
      }
      PlayAudioById(value8,(int *)0,(undefined4 *)value7 + 0xc);
    }
  }
switchD_00431e50_default:
  *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

