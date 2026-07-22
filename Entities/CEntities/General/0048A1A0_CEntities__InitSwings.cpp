#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A1A0
// Label: CEntities::InitSwings
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitSwings(uint *entry)

{
  uint value2;
  undefined4 *dataCursor;
  int value;
  short shortValue;
  undefined4 *dataCursor2;
  undefined4 *dataCursor3;
  
  shortValue = 0;
  entry[10] = entry[10] & 0xfffffffd | 1;
  if (entry[0xd] != 0) {
    shortValue = *(short *)(entry[0xd] + 0x14);
  }
  value2 = entry[0xe];
  if (value2 != 0) {
    *(undefined2 *)(value2 + 0xa6) = 1;
    ComputeEntitySceneObjectCollisionMoveDelta(0,0,value2);
    *(ushort *)(value2 + 0xa2) = *(ushort *)(value2 + 0x132) ^ 0x800;
    *(undefined4 *)(value2 + 0xb4) = 1;
    if (shortValue == 1) {
      entry[0x13] = 0;
      entry[0x14] = 0xd;
      *(int *)(value2 + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x340;
    }
    else {
      entry[0x13] = 0;
      if (shortValue == 2) {
        *(int *)(value2 + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x1588;
        entry[0x14] = 4;
      }
      else {
        *(int *)(value2 + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2d8;
        entry[0x14] = 10;
      }
    }
    *(short *)(value2 + 0xc) = (short)entry[0x13];
    dataCursor = (undefined4 *)CEntities::AllocEntityAttachment(entry,0x2c,0x8000000,&DAT_00511818);
    if (dataCursor != (undefined4 *)0x0) {
      *entry = *entry | 0x8000000;
      dataCursor2 = &DAT_00511818;
      dataCursor3 = dataCursor;
      for (value = 0xb; value != 0; value = value + -1) {
        *dataCursor3 = *dataCursor2;
        dataCursor2 = dataCursor2 + 1;
        dataCursor3 = dataCursor3 + 1;
      }
      *(undefined4 *)(value2 + 0x8c) = 0x40;
      *(undefined4 *)(value2 + 0x90) = 0x1000;
      SyncSwingStateToEntitySceneObject(value2,dataCursor);
      if (*(short *)((int)dataCursor + 0x12) != 0) {
        CEntities::LinkEntityIntoProcessingList(&g_ActiveSwingEntityList,entry);
      }
    }
    CEntities::SetEntitySceneObjectScriptAttachment(entry,(uint *)&PTR_DAT_00511808);
  }
  if ((entry[0x11] & 1) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

