#include "tarzan_ghidra_types.hpp"

// Address: 0x00448CC0
// Label: CCamera::BuildPoseFromJungleSurfacePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CCamera::BuildPoseFromJungleSurfacePath
              (int cameraState,int target,undefined4 *outPitch,int *outYaw,undefined4 *outDistance,
              undefined4 pathIndex,int flags,int arg8)

{
  Entity *entity = (Entity *)cameraState;
  int value;
  short shortValue;
  int value2;
  int value3;
  int *intCursor;
  undefined4 value5;
  int value4;
  int localState3;
  int localState2;
  int localState;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  
  if (*(int *)(cameraState + 0x2c) != 0) {
    value4 = *(int *)(cameraState + 0x2c) + 0x2c + cameraState;
    value2 = (*(int *)(value4 + 4) * target) / *(int *)(cameraState + 4);
    value3 = FindJungleSurfaceSegmentAtCoord(value4,value2);
    if ((*(byte *)(value3 + 0x14) & 1) == 0) {
      value2 = InterpolateJungleSurfaceSegmentPointAndAngle(value2,value3,&localState3);
      outDistance[8] = 0x140 - (value2 >> 3);
    }
    else {
      outDistance[8] = 0x140 - ((int)*(short *)(value3 + 0x10) >> 3);
      intCursor = (int *)FindJungleSurfaceSegmentAtCoord(cameraState,*(undefined4 *)(value3 + 0xc));
      value5 = CCamera::ComputeLookAtAnglesAndDistance((int *)value3,(int *)intCursor,(ushort *)outDistance + 0x14);
      outDistance[5] = value5;
      if ((intCursor[5] & 0x2000U) != 0) {
        intCursor = intCursor + -7;
      }
      shortValue = GetAngleFromXZVector12Bit(intCursor[7] - *intCursor,intCursor[9] - intCursor[2]);
      *(short *)((int)outDistance + 0x52) = *(short *)((int)outDistance + 0x52) + shortValue;
      outDistance[3] = 0;
      outDistance[4] = 0;
      *outDistance = *outPitch;
      outDistance[1] = outPitch[1];
      outDistance[2] = outPitch[2];
      intCursor = (int *)FindJungleSurfaceSegmentAtCoord(cameraState,target);
      if ((intCursor[5] & 0x2000U) != 0) {
        intCursor = intCursor + -7;
      }
      shortValue = GetAngleFromXZVector12Bit(intCursor[7] - *intCursor,intCursor[9] - intCursor[2]);
      *(ushort *)((int)outDistance + 0x52) = *(short *)((int)outDistance + 0x52) - shortValue & 0xfff;
      value2 = (int)(outDistance[5] * outDistance[8]) / 0x140;
      outDistance[5] = value2;
      if ((*(byte *)(value3 + 0x14) & 2) == 0) {
        value2 = InterpolateJungleSurfaceHeightAtCoord(target,intCursor,value2);
        shortValue = GetAngleFromXZVector12Bit(outPitch[1] - value2);
        *(short *)(outDistance + 0x14) = *(short *)(outDistance + 0x14) + shortValue;
      }
      CCamera::ProjectForwardPoint(outDistance,&localState3);
    }
    if (arg8 == 0) {
      *outYaw = ((localState3 - *outYaw) + 8 >> 3) + *outYaw;
      outYaw[1] = ((localState2 - outYaw[1]) + 8 >> 3) + outYaw[1];
      outYaw[2] = ((localState - outYaw[2]) + 8 >> 3) + outYaw[2];
    }
    else {
      *outYaw = localState3;
      outYaw[1] = localState2;
      outYaw[2] = localState;
    }
    value2 = outDistance[8];
    value = (outDistance[5] * value2) / 0x140;
    outDistance[5] = value;
    localState6 = *outPitch;
    localState5 = outPitch[1];
    localState4 = outPitch[2];
    if (flags < 0) {
      value4 = *(int *)(value4 + 0xc);
    }
    else {
      value4 = *(int *)(value4 + 0x10);
    }
    CCamera::BuildTargetPoseFromLookAt(outYaw,&localState6,outDistance);
    *(ushort *)((int)outDistance + 0x52) = *(ushort *)((int)outDistance + 0x52) & 0xfff;
    outDistance[3] = (value * value4) / value2;
    return value3;
  }
  return 0;
}

