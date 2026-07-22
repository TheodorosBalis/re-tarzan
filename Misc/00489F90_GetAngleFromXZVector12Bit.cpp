#include "tarzan_ghidra_types.hpp"

// Address: 0x00489F90
// Label: GetAngleFromXZVector12Bit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetAngleFromXZVector12Bit(int arg1,int arg2)

{
  int value;
  
  if (arg1 == 0) {
    if (arg2 == 0) {
      return 0;
    }
  }
  else if (arg1 == -0x80000000) {
    arg1 = -0x7fffffff;
  }
  if (arg2 == -0x80000000) {
    arg2 = -0x7fffffff;
  }
  if (arg1 < 0) {
    value = -arg1;
    if (-1 < arg2) {
      if (arg2 <= value) {
        return *(short *)(&g_AngleFromVectorQuadrantTable + ((arg2 << 9) / value) * 2) + 0xc00;
      }
      return 0x1000 - *(short *)(&g_AngleFromVectorQuadrantTable +
                                ((arg1 * -0x200) / arg2) * 2);
    }
    if (value < -arg2) {
      return *(short *)(&g_AngleFromVectorQuadrantTable + ((arg1 * -0x200) / -arg2) * 2) +
             0x800;
    }
    return 0xc00 - *(short *)(&g_AngleFromVectorQuadrantTable + ((arg2 * -0x200) / value) * 2);
  }
  if (arg2 < 0) {
    if (-arg2 <= arg1) {
      return *(short *)(&g_AngleFromVectorQuadrantTable + ((arg2 * -0x200) / arg1) * 2) +
             0x400;
    }
    return 0x800 - *(short *)(&g_AngleFromVectorQuadrantTable + ((arg1 << 9) / -arg2) * 2);
  }
  if (arg1 < arg2) {
    return (int)*(short *)(&g_AngleFromVectorQuadrantTable + ((arg1 << 9) / arg2) * 2);
  }
  return 0x400 - *(short *)(&g_AngleFromVectorQuadrantTable + ((arg2 << 9) / arg1) * 2);
}

