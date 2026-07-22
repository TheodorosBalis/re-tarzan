#include "tarzan_ghidra_types.hpp"

// Address: 0x00448A80
// Label: InterpolateJungleSurfaceSegmentPointAndAngle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int InterpolateJungleSurfaceSegmentPointAndAngle(int arg1,int *arg2,int *arg3)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  
  if ((arg2[5] & 0x2000U) != 0) {
    *arg3 = *arg2;
    arg3[1] = arg2[1];
    arg3[2] = arg2[2];
    return (int)(short)arg2[4];
  }
  value = arg2[8];
  value2 = arg2[2];
  value3 = arg2[1];
  arg1 = arg1 - arg2[3];
  value4 = arg2[9];
  value6 = arg2[10] - arg2[3];
  value5 = (((int)(short)arg2[0xb] - (int)(short)arg2[4]) * arg1) / value6;
  *arg3 = ((arg2[7] - *arg2) * arg1) / value6 + *arg2;
  arg3[2] = ((value4 - value2) * arg1) / value6 + arg2[2];
  if ((arg2[5] & 0x100U) != 0) {
    arg3[1] = 0x3ffffffe;
    return (short)arg2[4] + value5;
  }
  arg3[1] = ((value - value3) * arg1) / value6 + arg2[1];
  return (short)arg2[4] + value5;
}

