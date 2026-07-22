#include "tarzan_ghidra_types.hpp"

// Address: 0x00436CA0
// Label: CEntities::ComputeSignedPlayerFacingDistanceXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

uint CEntities::ComputeSignedPlayerFacingDistanceXZ(int *entry)

{
  int value;
  undefined4 value4;
  uint value5;
  int value2;
  int value3;
  
  value2 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *entry;
  value3 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - entry[2];
  value = SqrtToInt(value3 * value3 + value2 * value2);
  value5 = value >> 6;
  value4 = GetAngleFromXZVector12Bit(value2,value3);
  value = GetWrappedAngleDistance12Bit(value4,(int)*(short *)(g_PlayerEntitySceneObject + 0x132));
  if (0x400 < value) {
    value5 = ~value5 + 1;
  }
  return value5;
}

