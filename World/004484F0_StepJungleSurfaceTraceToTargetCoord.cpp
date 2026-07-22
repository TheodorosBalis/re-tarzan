#include "tarzan_ghidra_types.hpp"

// Address: 0x004484F0
// Label: StepJungleSurfaceTraceToTargetCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 StepJungleSurfaceTraceToTargetCoord(int arg1,undefined4 arg2,undefined4 arg3)

{
  int value;
  undefined4 value2;
  
  if (*(int *)(arg1 + 8) != 0) {
    if (0 < *(int *)(arg1 + 8)) {
      value = *(int *)(arg1 + 0xc);
      if ((*(uint *)(value + 0x14) & 0x2000) != 0) {
        *(undefined4 *)(arg1 + 4) = *(undefined4 *)(value + 0xc);
        return 6;
      }
      if (*(int *)(arg1 + 4) < *(int *)(value + 0x28)) {
        return 1;
      }
      value2 = TraceJungleSurfaceMoveAcrossNextSegment(arg1,arg2,arg3);
      return value2;
    }
    if (*(int *)(arg1 + 4) < *(int *)(*(int *)(arg1 + 0xc) + 0xc)) {
      value2 = TraceJungleSurfaceMoveAcrossPreviousSegment(arg1,arg2,arg3);
      return value2;
    }
    if ((*(int *)(arg1 + 4) == 0) && ((*(uint *)(*(int *)(arg1 + 0xc) + 0x14) & 0xc000) == 0))
    {
      return 6;
    }
  }
  return 1;
}

