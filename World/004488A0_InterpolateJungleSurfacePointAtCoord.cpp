#include "tarzan_ghidra_types.hpp"

// Address: 0x004488A0
// Label: InterpolateJungleSurfacePointAtCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int InterpolateJungleSurfacePointAtCoord(int arg1,int *arg2,int *arg3)

{
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  
  if ((arg2[5] & 0x2000U) != 0) {
    *arg3 = *arg2;
    arg3[1] = arg2[1];
    arg3[2] = arg2[2];
    return 0;
  }
  value5 = arg2[10] - arg2[3];
  if (value5 == 0) {
    *arg3 = *arg2;
    arg3[1] = arg2[1];
    arg3[2] = arg2[2];
    return 0;
  }
  value = arg2[1];
  value2 = arg2[2];
  arg1 = arg1 - arg2[3];
  value3 = arg2[8];
  value4 = arg2[9];
  *arg3 = ((arg2[7] - *arg2) * arg1) / value5 + *arg2;
  arg3[2] = arg2[2] + ((value4 - value2) * arg1) / value5;
  if ((arg2[5] & 0x100U) != 0) {
    arg3[1] = 0x3ffffffe;
    return arg1;
  }
  arg3[1] = ((value3 - value) * arg1) / value5 + arg2[1];
  return arg1;
}

