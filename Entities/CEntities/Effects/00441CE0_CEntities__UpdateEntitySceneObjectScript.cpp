#include "tarzan_ghidra_types.hpp"

// Address: 0x00441CE0
// Label: CEntities::UpdateEntitySceneObjectScript
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::UpdateEntitySceneObjectScript(undefined4 entry3,int sceneObject,int attachment)

{
  longlong value;
  bool flagByte;
  short shortValue;
  short shortValue2;
  undefined4 inputEax;
  undefined2 value2;
  int entry;
  int entry2;
  ushort value3;
  
  *(short *)(attachment + 0x14) = *(short *)(attachment + 0x14) + -1;
  value2 = (undefined2)((uint)inputEax >> 0x10);
  entry2 = CONCAT22(value2,*(short *)(attachment + 0x14));
  shortValue = 0;
  flagByte = false;
  if (*(short *)(attachment + 0x14) < 0) {
    do {
      *(short *)(attachment + 0x16) = *(short *)(attachment + 0x16) + 1;
      shortValue2 = *(short *)(attachment + 0x16);
      entry2 = CONCAT22((short)((uint)entry2 >> 0x10),shortValue2);
      entry = *(int *)(attachment + 0xc);
      value3 = *(ushort *)(entry + shortValue2 * 2);
      if (-1 < (short)value3) break;
      switch(value3) {
      case 0x8000:
        *(undefined2 *)(attachment + 0x16) = 0;
        if (shortValue == 0) {
          shortValue = 2;
        }
        break;
      case 0x8001:
        entry2 = CEntities::AdvanceScriptAttachmentSequence(attachment);
        if (shortValue == 0) {
          shortValue = 3;
        }
        break;
      case 0x8002:
        entry2 = CONCAT31((int3)((uint)entry2 >> 8),~*(byte *)(sceneObject + 0x75));
        *(byte *)(sceneObject + 0x75) = ~*(byte *)(sceneObject + 0x75);
        break;
      case 0x8003:
        entry2 = CEntities::ReleaseEntityToFreeList((byte *)entry3);
        goto LAB_00441fa0;
      case 0x8004:
        entry2 = CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry3);
LAB_00441fa0:
        value3 = 0;
        goto LAB_00441fa5;
      case 0x8005:
        shortValue = (short)(entry2 + 1);
        *(short *)(attachment + 0x16) = shortValue;
        shortValue = *(short *)(entry + shortValue * 2);
        entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),shortValue);
        break;
      case 0x8006:
        shortValue = (short)(entry2 + 1);
        *(short *)(attachment + 0x16) = shortValue;
        value3 = *(ushort *)(sceneObject + 0xc);
        shortValue = *(short *)(entry + shortValue * 2);
        entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),shortValue);
        break;
      case 0x8007:
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 4;
        break;
      case 0x8008:
        if ((*(byte *)(attachment + 0x1e) & 4) == 0) {
          shortValue2 = (short)(entry2 + 1);
          *(short *)(attachment + 0x16) = shortValue2;
          value2 = *(undefined2 *)(entry + shortValue2 * 2);
          entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),value2);
          *(undefined2 *)(sceneObject + 0x78) = 0;
          *(undefined2 *)(sceneObject + 0x76) = value2;
          *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 1;
        }
        else {
          shortValue2 = (short)(entry2 + 1);
          *(short *)(attachment + 0x16) = shortValue2;
          value2 = *(undefined2 *)(entry + shortValue2 * 2);
          entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),value2);
          *(undefined2 *)(sceneObject + 0x78) = 0;
          *(undefined2 *)(sceneObject + 0xc) = value2;
          *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 1;
        }
        break;
      case 0x8009:
        shortValue2 = (short)(entry2 + 1);
        *(short *)(attachment + 0x16) = shortValue2;
        value2 = *(undefined2 *)(entry + shortValue2 * 2);
        entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),value2);
        *(undefined2 *)(sceneObject + 0x78) = value2;
        break;
      case 0x800a:
        shortValue2 = (short)(entry2 + 1);
        *(short *)(attachment + 0x16) = shortValue2;
        value2 = *(undefined2 *)(entry + shortValue2 * 2);
        entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),value2);
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(undefined2 *)(sceneObject + 0x76) = value2;
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 0x82;
        break;
      case 0x800b:
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        value = 0x100 / (longlong)(*(short *)(entry + (short)(shortValue2 + 1) * 2) + 1);
        entry2 = (int)value;
        *(short *)(attachment + 0x1c) = (short)value;
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(byte *)(attachment + 0x1e) = *(byte *)(attachment + 0x1e) | 2;
        break;
      case 0x800c:
        *(undefined2 *)(sceneObject + 0x78) = 0;
        *(undefined2 *)(attachment + 0x1e) = 0;
        break;
      case 0x800d:
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        shortValue2 = *(short *)(entry + (short)(shortValue2 + 1) * 2);
        *(undefined2 *)(attachment + 0x1e) = 6;
        *(undefined2 *)(sceneObject + 0x76) = *(undefined2 *)(sceneObject + 0xc);
        *(undefined2 *)(sceneObject + 0x78) = 0;
        value = 0x100 / (longlong)(shortValue2 + 1);
        entry2 = (int)value;
        *(short *)(attachment + 0x1c) = (short)value;
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
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        entry2 = PlayAudioById((int)*(short *)(entry + (short)(shortValue2 + 1) * 2),(int *)sceneObject + 0x104,(undefined4 *)sceneObject + 0x14);
        break;
      case 0x8013:
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        entry2 = PlayAudioById((int)*(short *)(entry + (short)(shortValue2 + 1) * 2),(int *)0,(undefined4 *)sceneObject + 0x14);
        break;
      case 0x8014:
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        entry2 = PlayAudioById((int)*(short *)(entry + (short)(shortValue2 + 1) * 2),(int *)0,(undefined4 *)0);
        break;
      case 0x8015:
        flagByte = true;
        shortValue2 = (short)(entry2 + 1);
        *(short *)(attachment + 0x16) = shortValue2;
        value2 = *(undefined2 *)(entry + shortValue2 * 2);
        entry2 = CONCAT22((short)((uint)(entry2 + 1) >> 0x10),value2);
        *(undefined2 *)(attachment + 0x14) = value2;
        break;
      case 0x8016:
        *(short *)(attachment + 0x16) = shortValue2 + 1;
        entry2 = g_CurrentWorldSceneContext;
        entry = (int)*(short *)(entry + (short)(shortValue2 + 1) * 2);
        if (entry == 0x8000) {
          *(int *)(sceneObject + 0x10) = g_CurrentWorldSceneContext;
        }
        else {
          entry2 = g_WorldEntitySceneObjectArrayBase + entry * 0x68;
          *(int *)(sceneObject + 0x10) = entry2;
        }
        break;
      default:
        entry2 = 0;
        if (*(code **)(&g_ScriptAttachmentWordOpcodeCallbackTable + (short)(value3 >> 8 & 0xf) * 8)
            != (code *)0x0) {
          entry2 = (**(code **)(&g_ScriptAttachmentWordOpcodeCallbackTable +
                              (short)(value3 >> 8 & 0xf) * 8))(entry3,attachment,value3);
        }
      }
    } while ((short)value3 < 0);
LAB_00441fa5:
    if ((*(byte *)(attachment + 0x1e) & 4) == 0) {
      *(ushort *)(sceneObject + 0xc) = value3;
    }
    else {
      *(ushort *)(sceneObject + 0x76) = value3;
    }
    value2 = (undefined2)((uint)entry2 >> 0x10);
    if (!flagByte) {
      *(undefined2 *)(attachment + 0x14) = **(undefined2 **)(attachment + 0xc);
    }
    if ((*(byte *)(attachment + 0x1e) & 0x80) != 0) {
      value = 0x100 / (longlong)(*(short *)(attachment + 0x14) + 2);
      value2 = (undefined2)((ulonglong)value >> 0x10);
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
  return CONCAT22(value2,shortValue);
}

