#include "tarzan_ghidra_types.hpp"

// Address: 0x0048A110
// Label: CCamera::ComputeLookAtAnglesAndDistance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CCamera::ComputeLookAtAnglesAndDistance(int *cameraState,int *target,ushort *outPitch)

{
  ushort value5;
  int value;
  int value2;
  int value3;
  int value4;
  
  value3 = *cameraState - *target;
  value4 = target[2] - cameraState[2];
  value2 = target[1] - cameraState[1];
  value = SqrtToInt(value3 * value3 + value4 * value4);
  value5 = GetAngleFromXZVector12Bit(value3,value4);
  outPitch[1] = value5;
  value5 = GetAngleFromXZVector12Bit(value2,value >> 6);
  *outPitch = value5 & 0xfff;
  value = SqrtToInt(value2 * value2 + value3 * value3 + value4 * value4);
  return value >> 6;
}

