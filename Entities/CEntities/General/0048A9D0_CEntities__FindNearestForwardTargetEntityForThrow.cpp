#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A9D0
// Label: CEntities::FindNearestForwardTargetEntityForThrow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::FindNearestForwardTargetEntityForThrow(void)

{
  int foundIndex;
  int foundIndex3;
  int foundIndex4;
  undefined4 value2;
  uint value3;
  int foundIndex5;
  uint value4;
  int *intCursor;
  undefined *dataCursor;
  int foundIndex2;
  uint value;
  undefined *localState;
  int localState2;
  
  foundIndex2 = 0;
  foundIndex5 = 0;
  localState = &DAT_0078ea01;
  localState2 = 0;
  foundIndex4 = g_PlayerEntitySceneObjectData;
  intCursor = g_LateEntityList;
  if (0 < *g_LateEntityList) {
    do {
      foundIndex = intCursor[foundIndex5 + 1];
      foundIndex5 = foundIndex5 + 1;
      for (foundIndex3 = *(int *)(foundIndex + 0x38); foundIndex3 != 0; foundIndex3 = *(int *)(foundIndex3 + 0x34)) {
        value4 = ((int)*(short *)(g_PlayerEntitySceneObject + 0x142) - *(int *)(foundIndex3 + 0x18)) +
                *(int *)(foundIndex4 + 0xc);
        if ((int)value4 < 0) {
          value = *(int *)(foundIndex4 + 8) - *(int *)(foundIndex3 + 0x14);
          foundIndex4 = *(int *)(foundIndex4 + 0x10) - *(int *)(foundIndex3 + 0x1c);
          dataCursor = (undefined *)(foundIndex4 * foundIndex4 + value * value + value4 * value4);
          value2 = GetAngleFromXZVector12Bit(value,foundIndex4);
          value3 = GetWrappedSignedAngleDelta12Bit
                            ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),value2);
          foundIndex4 = g_PlayerEntitySceneObjectData;
          if ((((int)dataCursor < (int)localState) &&
              ((int)((value3 ^ (int)value3 >> 0x1f) - ((int)value3 >> 0x1f)) < 0x100)) &&
             (foundIndex2 = GetAngleFromXZVector12Bit
                                 ((value ^ (int)value >> 0x1f) - ((int)value >> 0x1f),
                                  (value4 ^ (int)value4 >> 0x1f) - ((int)value4 >> 0x1f)),
             foundIndex4 = g_PlayerEntitySceneObjectData, 0x200 < foundIndex2)) {
            localState = dataCursor;
            localState2 = foundIndex;
          }
        }
        intCursor = g_LateEntityList;
        foundIndex2 = localState2;
      }
    } while (foundIndex5 < *intCursor);
    return foundIndex2;
  }
  return 0;
}

