#include "tarzan_ghidra_types.hpp"

// Address: 0x00448BA0
// Label: ComputeJungleSurfaceSegmentAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ComputeJungleSurfaceSegmentAngles(int *arg1,undefined2 *arg2)

{
  undefined2 value;
  
  if ((arg1[5] & 0x2000U) != 0) {
    arg1 = arg1 + -7;
  }
  value = GetAngleFromXZVector12Bit(arg1[10] - arg1[3],arg1[8] - arg1[1]);
  *arg2 = value;
  value = GetAngleFromXZVector12Bit(arg1[7] - *arg1,arg1[9] - arg1[2]);
  arg2[1] = value;
  arg2[2] = 0;
  return;
}

