#include "tarzan_ghidra_types.hpp"

// Address: 0x00448350
// Label: TraceJungleSurfaceMoveAcrossPreviousSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TraceJungleSurfaceMoveAcrossPreviousSegment(uint *arg1,int arg2,int arg3)

{
  uint value3;
  uint value4;
  int value;
  int value2;
  uint value5;
  uint value6;
  
  value5 = arg1[3];
  value3 = *(uint *)(value5 + 0x14);
  if ((value3 & 0xc000) == 0) goto LAB_0044848c;
  if (((value3 & 0xc000) == 0x4000) && (*(int *)(value5 + 0xc) == 0)) {
    arg1[4] = 0;
    return 8;
  }
  value6 = (uint)*(ushort *)(value5 + 0x18);
  value2 = *(int *)(g_CollisionSurfaceTable + 4 + value6 * 4) + 0x34 +
          ((uint)*(ushort *)(value5 + 0x1a) * 7 + value6) * 4 + g_CollisionSurfaceTable;
  value4 = *(uint *)(value5 + 0xc);
  value = *(int *)(value2 + 4);
  if (value4 == 0) {
    if ((value < arg2) && (g_JungleSurfaceTraceProbeSpan < arg2 - value)) {
      arg1[1] = 0;
      return 6;
    }
    value = *(int *)(value2 + 0xc);
  }
  else {
    if (*(int *)(value5 + 4) <= value) goto LAB_0044848c;
    if (value <= arg2 - g_JungleSurfaceTraceProbeSpan) {
      if (arg2 - arg3 < value) {
        arg1[1] = value4;
        return 6;
      }
      if (((*(short *)(value5 + 0x12) != 0) && ((value3 & 0x30) == 0)) &&
         (arg2 - arg3 < *(int *)(value5 + 4) - (int)*(short *)(value5 + 0x12))) {
        arg1[1] = value4;
        return 6;
      }
      goto LAB_0044848c;
    }
    value = *(int *)(value2 + 0xc);
  }
  if (value != 0) {
    *arg1 = value6;
    value5 = arg1[1] - *(int *)(value5 + 0xc);
    arg1[1] = value5;
    value = *(int *)(value2 + 0xc);
    arg1[3] = value2 - 0x1c;
    arg1[1] = value + value5;
    return 0;
  }
LAB_0044848c:
  if (*(uint *)(value5 + 0xc) == 0) {
    arg1[1] = 0;
    return 6;
  }
  if (((*(short *)(value5 + 0x12) != 0) && (*(short *)(value5 - 10) != 0)) &&
     (((value3 & 0x30) == 0 &&
      (arg2 - arg3 < *(int *)(value5 + 4) - (int)*(short *)(value5 + 0x12))))) {
    arg1[1] = *(uint *)(value5 + 0xc);
    return 6;
  }
  arg1[3] = value5 - 0x1c;
  return 0;
}

