#include "tarzan_ghidra_types.hpp"

// Address: 0x00442070
// Label: CEntities::PlayTimedScriptedEntitySceneObjectEffect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
CEntities::PlayTimedScriptedEntitySceneObjectEffect(undefined4 entry3,int sceneObject,int attachment)

{
  ushort *dataCursor;
  undefined2 value3;
  undefined2 value4;
  ushort value5;
  short shortValue;
  longlong value;
  int entry;
  undefined4 inputEax;
  undefined2 value6;
  int entry2;
  ushort value2;
  
  *(short *)(attachment + 0x14) = *(short *)(attachment + 0x14) + -1;
  value6 = (undefined2)((uint)inputEax >> 0x10);
  value3 = 0;
  if (*(short *)(attachment + 0x14) < 0) {
    do {
      *(short *)(attachment + 0x16) = *(short *)(attachment + 0x16) + 1;
      entry = g_CurrentWorldSceneContext;
      value2 = *(ushort *)(*(int *)(attachment + 0xc) + *(short *)(attachment + 0x16) * 4);
      entry2 = *(int *)(attachment + 0xc) + *(short *)(attachment + 0x16) * 4;
      if (-1 < (short)value2) break;
      value6 = (undefined2)((uint)entry2 >> 0x10);
      switch(value2) {
      case 0x8000:
        *(undefined2 *)(attachment + 0x16) = 0xffff;
        value3 = 2;
        break;
      case 0x8001:
        entry2 = CEntities::AdvanceScriptAttachmentSequence(attachment);
        value3 = 3;
        break;
      case 0x8002:
        entry2 = CONCAT31((int3)((uint)entry2 >> 8),~*(byte *)(sceneObject + 0x75));
        *(byte *)(sceneObject + 0x75) = ~*(byte *)(sceneObject + 0x75);
        break;
      case 0x8003:
        entry2 = CEntities::ReleaseEntityToFreeList((byte *)entry3);
        goto LAB_004422a8;
      case 0x8004:
        entry2 = CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry3);
LAB_004422a8:
        value2 = 0;
        goto LAB_004422ad;
      case 0x8005:
        value3 = *(undefined2 *)(entry2 + 2);
        break;
      case 0x8006:
        value3 = *(undefined2 *)(entry2 + 2);
        value2 = *(ushort *)(sceneObject + 0xc);
        break;
      case 0x8007:
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 4;
        break;
      case 0x8008:
        if ((*(byte *)(attachment + 0x1e) & 4) == 0) {
          value6 = *(undefined2 *)(entry2 + 2);
          *(undefined2 *)(sceneObject + 0x78) = 0;
          *(undefined2 *)(sceneObject + 0x76) = value6;
          *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 1;
        }
        else {
          value4 = *(undefined2 *)(entry2 + 2);
          entry2 = CONCAT22(value6,value4);
          *(undefined2 *)(sceneObject + 0x78) = 0;
          *(undefined2 *)(sceneObject + 0xc) = value4;
          *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 1;
        }
        break;
      case 0x8009:
        *(undefined2 *)(sceneObject + 0x78) = *(undefined2 *)(entry2 + 2);
        break;
      case 0x800a:
        value4 = *(undefined2 *)(entry2 + 2);
        entry2 = CONCAT22(value6,value4);
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(undefined2 *)(sceneObject + 0x76) = value4;
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 0x82;
        break;
      case 0x800b:
        dataCursor = (ushort *)(entry2 + 2);
        entry2 = 0;
        *(short *)(attachment + 0x1c) = (short)(0x100 / (ulonglong)(longlong)(int)(*dataCursor + 1));
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 2;
        break;
      case 0x800c:
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(undefined2 *)(attachment + 0x1e) = 0;
        break;
      case 0x800d:
        value5 = *(ushort *)(entry2 + 2);
        *(undefined2 *)(attachment + 0x1e) = 6;
        *(undefined2 *)(sceneObject + 0x76) = *(undefined2 *)(sceneObject + 0xc);
        entry2 = 0;
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(short *)(attachment + 0x1c) = (short)(0x100 / (ulonglong)(longlong)(int)(value5 + 1));
        break;
      case 0x800e:
        *(ushort *)(sceneObject + 0xe) = *(ushort *)(sceneObject + 0xe) ^ 2;
        break;
      case 0x800f:
        *(ushort *)(sceneObject + 0xe) = *(ushort *)(sceneObject + 0xe) ^ 4;
        break;
      case 0x8010:
        *(ushort *)(sceneObject + 0xe) = *(ushort *)(sceneObject + 0xe) ^ 8;
        break;
      case 0x8011:
        *(ushort *)(sceneObject + 0xe) = *(ushort *)(sceneObject + 0xe) & 0xfff1;
        break;
      case 0x8012:
        entry2 = PlayAudioById(*(undefined2 *)(entry2 + 2),(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
        break;
      case 0x8013:
        entry2 = PlayAudioById(*(undefined2 *)(entry2 + 2),(int *)0,(undefined4 *)sceneObject + 0x14);
        break;
      case 0x8014:
        entry2 = PlayAudioById(*(undefined2 *)(entry2 + 2),(int *)0,(undefined4 *)0);
        break;
      default:
        entry2 = 0;
        if (*(code **)(&g_ScriptAttachmentTimedOpcodeCallbackTable + (short)(value2 >> 8 & 0xf) * 8)
            != (code *)0x0) {
          entry2 = (**(code **)(&g_ScriptAttachmentTimedOpcodeCallbackTable +
                              (short)(value2 >> 8 & 0xf) * 8))(entry3,attachment,value2);
        }
        break;
      case 0x8016:
        if (*(ushort *)(entry2 + 2) == 0x8000) {
          *(int *)(sceneObject + 0x10) = g_CurrentWorldSceneContext;
          entry2 = entry;
        }
        else {
          entry2 = g_WorldEntitySceneObjectArrayBase + (uint)*(ushort *)(entry2 + 2) * 0x68;
          *(int *)(sceneObject + 0x10) = entry2;
        }
      }
    } while ((short)value2 < 0);
LAB_004422ad:
    if ((*(byte *)(attachment + 0x1e) & 4) == 0) {
      *(ushort *)(sceneObject + 0xc) = value2;
    }
    else {
      *(ushort *)(sceneObject + 0x76) = value2;
    }
    shortValue = *(short *)(*(int *)(attachment + 0xc) + 2 + *(short *)(attachment + 0x16) * 4);
    value6 = (undefined2)((uint)entry2 >> 0x10);
    *(short *)(attachment + 0x14) = shortValue;
    if ((*(byte *)(attachment + 0x1e) & 0x80) != 0) {
      value = 0x100 / (longlong)(shortValue + 2);
      value6 = (undefined2)((ulonglong)value >> 0x10);
      *(short *)(attachment + 0x1c) = (short)value;
    }
  }
  if ((*(byte *)(attachment + 0x1e) & 2) != 0) {
    *(short *)(sceneObject + 0x78) = *(short *)(sceneObject + 0x78) + *(short *)(attachment + 0x1c);
  }
  if (0xff < *(short *)(sceneObject + 0x78)) {
    *(undefined2 *)(sceneObject + 0x78) = 0;
    *(undefined2 *)(attachment + 0x1e) = 0;
    *(undefined2 *)(sceneObject + 0xc) = *(undefined2 *)(sceneObject + 0x76);
  }
  return CONCAT22(value6,value3);
}

