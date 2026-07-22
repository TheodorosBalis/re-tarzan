#include "tarzan_ghidra_types.hpp"

// Address: 0x0040A730
// Label: CCamera::BlendOrSnapToTargetPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::BlendOrSnapToTargetPose(int *arg1,int *arg2,int *arg3)

{
  int value;
  
  if (arg3 != (int *)0x0) {
    if (g_CameraBlendTargetPose != 0) {
      g_CameraBlendTargetPose = g_CameraBlendTargetPose + -1;
      arg3 = g_CameraBlendSnapFlag;
    }
    arg1[8] = ((arg2[8] - arg1[8]) + 4 >> 2) + arg1[8];
    *arg1 = (((*arg3 >> 1) - *arg1) + *arg2) / *arg3 + *arg1;
    arg1[1] = (((arg3[1] >> 1) + arg2[1]) - arg1[1]) / arg3[1] + arg1[1];
    arg1[2] = (((arg3[2] >> 1) + arg2[2]) - arg1[2]) / arg3[2] + arg1[2];
    arg1[3] = (arg2[3] - arg1[3]) / arg3[6] + arg1[3];
    arg1[4] = (arg2[4] - arg1[4]) / arg3[7] + arg1[4];
    arg1[5] = (arg2[5] - arg1[5]) / arg3[8] + arg1[5];
    value = GetWrappedSignedAngleDelta12Bit((int)(short)arg1[0x14],(int)(short)arg2[0x14]);
    *(short *)(arg1 + 0x14) = (short)arg1[0x14] + (short)(value / arg3[3]);
    value = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)((int)arg1 + 0x52),(int)*(short *)((int)arg2 + 0x52));
    *(short *)((int)arg1 + 0x52) = *(short *)((int)arg1 + 0x52) + (short)(value / arg3[4]);
    value = GetWrappedSignedAngleDelta12Bit((int)(short)arg1[0x15],(int)(short)arg2[0x15]);
    *(short *)(arg1 + 0x15) = (short)arg1[0x15] + (short)(value / arg3[5]);
    return;
  }
  arg1[8] = arg2[8];
  *arg1 = *arg2;
  arg1[1] = arg2[1];
  arg1[2] = arg2[2];
  arg1[0x14] = arg2[0x14];
  arg1[0x15] = arg2[0x15];
  arg1[3] = arg2[3];
  arg1[4] = arg2[4];
  arg1[5] = arg2[5];
  g_CameraBlendTargetPose = 0;
  return;
}

