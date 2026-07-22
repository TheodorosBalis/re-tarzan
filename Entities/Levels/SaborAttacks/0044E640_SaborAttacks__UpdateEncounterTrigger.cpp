#include "tarzan_ghidra_types.hpp"

// Address: 0x0044E640
// Label: SaborAttacks::UpdateEncounterTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::UpdateEncounterTrigger(int entry)

{
  int *intCursor;
  uint *dataCursor2;
  uint value3;
  char resultFlag;
  short shortValue2;
  int count5;
  int *intCursor2;
  int count6;
  int count7;
  int count;
  int count2;
  undefined4 value;
  uint *dataCursor;
  int count3;
  int count4;
  short shortValue;
  undefined4 value2;
  uint localState;
  
  count5 = CEntities::FindEntityAttachmentByFlags(entry,0x200);
  if (count5 == 0) goto LAB_0044ea7c;
  if ((*(byte *)(entry + 0x42) & 0x10) != 0) {
    count7 = *(int *)(count5 + 0x10);
    value = *(undefined4 *)(count5 + 0xc);
    intCursor = (int *)(count5 + 0xc);
    count3 = *(int *)(count5 + 0x14) + -0x29c;
    intCursor2 = (int *)CEntities::SpawnEntityByTypeAtPosition(value,count7 + 0x1f8,count3,0x178,0x11);
    if ((intCursor2 != (int *)0x0) && (*intCursor2 != 0)) {
      *(undefined2 *)(intCursor2[0xe] + 0xc) = 0x2013;
      *(undefined4 *)(intCursor2[0xe] + 0x10) = g_CurrentWorldSceneContext;
      *(undefined4 *)(intCursor2[0xe] + 0xb4) = 1;
      *(undefined4 *)(intCursor2[0xe] + 0xa8) = 7000;
      *(undefined4 *)(intCursor2[0xe] + 0xac) = 7000;
      *(undefined4 *)(intCursor2[0xe] + 0xb0) = 7000;
      count6 = CEntities::FindEntityAttachmentByFlags(intCursor2,0x10000000);
      if (count6 != 0) {
        *(undefined4 *)(count6 + 0x34) = 0x7fff;
        *(undefined4 *)(count6 + 0x524) = 0x200;
        *(undefined4 *)(count6 + 0x10) = 8;
      }
    }
    count7 = CEntities::SpawnEntityByTypeAtPosition(value,count7 + 0xb8,count3,0x14,0x11);
    if (count7 != 0) {
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0xb4) = 1;
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0xa8) = 9000;
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0xac) = 9000;
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0xb0) = 9000;
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0x30) = 0x800;
      *(undefined4 *)(*(int *)(count7 + 0x38) + 0x6c) = 0xffffff00;
    }
    count7 = *(int *)(entry + 0x4c) + -1;
    *(int *)(entry + 0x4c) = count7;
    if (count7 < 0) {
      count7 = *(int *)(count5 + 0x10);
      count4 = *(int *)(count5 + 0x14) + -0x29c;
      count3 = *intCursor;
      count6 = CEntities::SpawnEntityByTypeAtPosition(count3,count7 + 0x338,count4,0x14,0x11);
      if (count6 != 0) {
        *(undefined4 *)(*(int *)(count6 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(count6 + 0x38) + 0xa8) = 8000;
        *(undefined4 *)(*(int *)(count6 + 0x38) + 0xac) = 8000;
        *(undefined4 *)(*(int *)(count6 + 0x38) + 0xb0) = 8000;
        *(undefined4 *)(*(int *)(count6 + 0x38) + 0x30) = 0x800;
      }
      shortValue = 0;
      localState = 0;
      do {
        count6 = RandomModulo(0x180,count4,0x160,0x11);
        count6 = RandomModulo(0x400,(count7 + 0x238) - count6);
        count = RandomModulo(0x200);
        count6 = CEntities::SpawnEntityByTypeAtPosition((count3 - count6) + count);
        if ((count6 != 0) &&
           (count = CEntities::FindEntityAttachmentByFlags(count6,0x20000000), count != 0)) {
          count2 = RandomModulo(0x1e);
          value = RandomModulo(0x2000);
          *(int *)(count + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[localState - 0x400 & 0xfff] * (count2 + 0x32) >> 0xc
          ;
          *(int *)(count + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[localState & 0xfff] * (count2 + 0x32) >> 0xc;
          shortValue2 = RandomModulo(0x80);
          *(short *)(count + 0x54) = -0x60 - shortValue2;
          *(int *)(count + 0x24) = count7 + 0xa38;
          *(undefined2 *)(*(int *)(count6 + 0x38) + 0xc) = 0x2012;
          *(undefined4 *)(*(int *)(count6 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
          *(undefined4 *)(*(int *)(count6 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(count6 + 0x38) + 0xa8) = value;
          *(undefined4 *)(*(int *)(count6 + 0x38) + 0xac) = value;
          *(undefined4 *)(*(int *)(count6 + 0x38) + 0xb0) = value;
          *(undefined2 *)(count + 0x56) = 0xff00;
          *(short *)(*(int *)(count6 + 0x38) + 0xa2) = (shortValue + 1) * 0x200;
          *(undefined2 *)(*(int *)(count6 + 0x38) + 0xa0) = 0x400;
          count6 = RandomModulo(0x32);
          *(int *)(count + 0x18) = count6 + 0x1e;
          *(undefined4 *)(count + 0x10) = 0;
        }
        localState = localState + 0x200;
        shortValue = shortValue + 1;
      } while ((int)localState < 0x1000);
      if (*(char *)(entry + 0x3d) == '\x01') {
        value = *(undefined4 *)(count5 + 0x18);
        value2 = 0x2006;
      }
      else {
        value = *(undefined4 *)(count5 + 0x18);
        value2 = 0x2011;
      }
      DecodeEncodedEntitySceneObjectIdToSourceRef(value,value2);
      value3 = *(uint *)(g_PlayerContactSurfaceThisFrame + -8);
      count5 = g_PlayerContactSurfaceThisFrame;
      while ((value3 & 0x200) != 0) {
        value3 = *(uint *)(count5 + -0x24);
        count5 = count5 + -0x1c;
      }
      dataCursor = (uint *)(count5 + 0x14);
      value3 = *(uint *)(count5 + 0x14);
      while ((value3 & 0x200) != 0) {
        *dataCursor = value3 | 0x100;
        dataCursor2 = dataCursor + 7;
        dataCursor = dataCursor + 7;
        value3 = *dataCursor2;
      }
      PlayAudioById(0xce,(int *)0,(undefined4 *)intCursor);
      PlayForceFeedbackEffect_Stub(0,3,0x14);
      CEntities::UnlinkEntityFromProcessingList(entry);
    }
    else {
      CEntities::SpawnEntityByTypeAtPosition
                (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
                 *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x13,0x11);
      value = RandomModulo(4);
      switch(value) {
      case 0:
        value = 0xd8;
        break;
      case 1:
        value = 0xd9;
        break;
      case 2:
        value = 0xda;
        break;
      case 3:
        value = 0xdb;
        break;
      default:
        goto switchD_0044ea2b_default;
      }
      PlayAudioById(value,(int *)0,(undefined4 *)intCursor);
    }
  }
switchD_0044ea2b_default:
  *(ushort *)(entry + 0x42) = *(ushort *)(entry + 0x42) & 0xffef;
LAB_0044ea7c:
  resultFlag = IsEntitySourceRefOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

