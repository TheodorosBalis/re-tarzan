#include "tarzan_ghidra_types.hpp"

// Address: 0x00448C00
// Label: UpdateEntitySceneObjectSurfaceAnglesFromSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntitySceneObjectSurfaceAnglesFromSegment(int *arg1,int arg2)

{
  undefined2 value;
  undefined4 value2;
  
  if ((arg1[5] & 0x2000U) != 0) {
    arg1 = arg1 + -7;
  }
  value = GetAngleFromXZVector12Bit(arg1[10] - arg1[3],arg1[8] - arg1[1]);
  *(undefined2 *)(arg2 + 0x10) = value;
  value = GetAngleFromXZVector12Bit(arg1[7] - *arg1,arg1[9] - arg1[2]);
  *(undefined2 *)(arg2 + 0x12) = value;
  *(undefined2 *)(arg2 + 0x14) = 0;
  value2 = GetAngleFromXZVector12Bit
                    (arg1[10] - arg1[3],
                     (((int)*(short *)((int)arg1 + 0x12) - (int)*(short *)((int)arg1 + 0x2e))
                     - arg1[1]) + arg1[8]);
  *(undefined4 *)(arg2 + 0x18) = value2;
  return;
}

