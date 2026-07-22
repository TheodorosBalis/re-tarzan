#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A2F0
// Label: CEntities::UpdateSwings
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateSwings(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  ushort value4;
  short shortValue;
  int value2;
  uint value5;
  int value3;
  
  value = entity->sceneObjects;
  if (value == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  else {
    value2 = CEntities::FindEntityAttachmentByFlags(entry,0x8000000);
    if (value2 != 0) {
      SyncSwingStateToEntitySceneObject(value,value2);
      if ((*(int *)(entry + 0x24) == 0) && (*(short *)(value2 + 0x12) != 0)) {
        CEntities::LinkEntityIntoProcessingList(&g_ActiveSwingEntityList,entry);
      }
      shortValue = *(short *)(value2 + 0xe);
      if (shortValue == 2) {
        value3 = *(int *)(value2 + 0x14) + *(int *)(value2 + 0x18);
        *(int *)(value2 + 0x14) = value3;
        if (*(int *)(value2 + 0x20) < value3) {
          *(int *)(value2 + 0x14) = *(int *)(value2 + 0x20);
        }
        *(short *)(value2 + 0x10) = *(short *)(value2 + 0x10) + 1;
        value5 = (uint)*(ushort *)(value2 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + value5 * 0xc) < 0) {
          shortValue = *(short *)(g_ActiveSwingMotionTable + value5 * 0xc + 2);
          value5 = (uint)shortValue;
          *(short *)(value2 + 0x10) = shortValue;
        }
        value4 = *(ushort *)(g_ActiveSwingMotionTable + 2 + value5 * 0xc);
        if ((value4 & 0x800) == 0) {
          value4 = value4 & 0x7ff;
        }
        else {
          value4 = value4 | 0xf800;
        }
        shortValue = (short)((uint)((int)(short)value4 * *(int *)(value2 + 0x14)) >> 8);
        *(short *)(value + 0xa0) = shortValue;
        *(short *)(value + 0x80) = -((shortValue >> 2) + shortValue);
        *(short *)(value + 0x7a) = (short)g_CurrentSwingSegmentIndex + 1;
      }
      else if (shortValue == 4) {
        value3 = *(int *)(value2 + 0x14) - *(int *)(value2 + 0x1c);
        *(int *)(value2 + 0x14) = value3;
        if (value3 < 0) {
          *(undefined4 *)(value2 + 0x14) = 0;
          *(undefined2 *)(value2 + 0xe) = 1;
        }
        *(short *)(value2 + 0x10) = *(short *)(value2 + 0x10) + 1;
        value5 = (uint)*(ushort *)(value2 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + value5 * 0xc) < 0) {
          shortValue = *(short *)(g_ActiveSwingMotionTable + value5 * 0xc + 2);
          value5 = (uint)shortValue;
          *(short *)(value2 + 0x10) = shortValue;
        }
        value4 = *(ushort *)(g_ActiveSwingMotionTable + 2 + value5 * 0xc);
        if ((value4 & 0x800) == 0) {
          value4 = value4 & 0x7ff;
        }
        else {
          value4 = value4 | 0xf800;
        }
        shortValue = (short)((uint)((int)(short)value4 * *(int *)(value2 + 0x14)) >> 8);
        *(short *)(value + 0xa0) = shortValue;
        *(short *)(value + 0x80) = -((shortValue >> 2) + shortValue);
        shortValue = (short)g_CurrentSwingSegmentIndex;
        *(undefined2 *)(value + 0x7c) = 0xffff;
        *(short *)(value + 0x7a) = shortValue + 1;
      }
      else if (shortValue == 8) {
        value3 = *(int *)(value2 + 0x14) - *(int *)(value2 + 0x1c);
        *(int *)(value2 + 0x14) = value3;
        if (value3 < 0) {
          *(undefined4 *)(value2 + 0x14) = 0;
          *(undefined2 *)(value2 + 0xe) = 1;
        }
        *(short *)(value2 + 0x10) = *(short *)(value2 + 0x10) + 1;
        value5 = (uint)*(ushort *)(value2 + 0x10);
        if (*(short *)(g_ActiveSwingMotionTable + value5 * 0xc) < 0) {
          shortValue = *(short *)(g_ActiveSwingMotionTable + value5 * 0xc + 2);
          value5 = (uint)shortValue;
          *(short *)(value2 + 0x10) = shortValue;
        }
        value4 = *(ushort *)(g_ActiveSwingMotionTable + 2 + value5 * 0xc);
        if ((value4 & 0x800) == 0) {
          value4 = value4 & 0x7ff;
        }
        else {
          value4 = value4 | 0xf800;
        }
        shortValue = (short)((uint)((int)(short)value4 * *(int *)(value2 + 0x14)) >> 8);
        *(short *)(value + 0xa0) = shortValue;
        *(short *)(value + 0x80) = -((shortValue >> 2) + shortValue);
      }
      else {
        *(undefined2 *)(value + 0xa0) = 0;
        *(undefined2 *)(value + 0x7a) = 0;
        *(undefined2 *)(value + 0x7c) = 0xffff;
        *(undefined2 *)(value2 + 0x10) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

