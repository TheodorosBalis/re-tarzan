#include "tarzan_ghidra_types.hpp"

// Address: 0x00448200
// Label: TraceJungleSurfaceMoveAcrossNextSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 TraceJungleSurfaceMoveAcrossNextSegment(uint *arg1,int arg2,int arg3)

{
  uint value2;
  uint value3;
  int value;
  uint value4;
  
  value2 = arg1[3];
  arg1[3] = value2 + 0x1c;
  value3 = *(uint *)(value2 + 0x30);
  if ((value3 & 0xc000) == 0) {
LAB_00448300:
    if (((((value3 & 0x2000) == 0) && (*(short *)(value2 + 0x2e) != 0)) &&
        (*(short *)(value2 + 0x4a) != 0)) &&
       (((value3 & 0x30) == 0 &&
        (arg2 - arg3 < *(int *)(value2 + 0x20) - (int)*(short *)(value2 + 0x2e))))) {
LAB_0044832c:
      value = *(int *)(value2 + 0x28);
      arg1[3] = value2;
      arg1[1] = value - 1;
      return 6;
    }
  }
  else {
    if ((value3 & 0xe000) == 0x6000) {
      arg1[4] = 0;
      return 8;
    }
    if ((value3 & 0xc000) == 0x4000) {
      return 0;
    }
    value = *(int *)(g_CollisionSurfaceTable + 4 + (uint)*(ushort *)(value2 + 0x34) * 4) + 0x34 +
            ((uint)*(ushort *)(value2 + 0x36) * 7 + (uint)*(ushort *)(value2 + 0x34)) * 4;
    value4 = value + g_CollisionSurfaceTable;
    if ((*(uint *)(value + 0x14 + g_CollisionSurfaceTable) & 0x2000) != 0) {
      return 0;
    }
    value3 = *(uint *)(value2 + 0x30);
    value = *(int *)(value4 + 4);
    if ((value3 & 0x2000) == 0) {
      if (*(int *)(value2 + 0x20) <= value) {
        return 0;
      }
      if (value <= arg2 - g_JungleSurfaceTraceProbeSpan) {
        if ((*(short *)(value2 + 0x2e) != 0) && ((value3 & 0x30) == 0)) {
          value = *(int *)(value2 + 0x20) - (int)*(short *)(value2 + 0x2e);
        }
        if (arg2 - arg3 < value) goto LAB_0044832c;
        goto LAB_00448300;
      }
    }
    else if ((value < arg2) && (g_JungleSurfaceTraceProbeSpan < arg2 - value))
    goto LAB_0044832c;
    *arg1 = (uint)*(ushort *)(value2 + 0x34);
    value = *(int *)(value2 + 0x28);
    arg1[3] = value4;
    arg1[1] = arg1[1] - value;
    arg1[1] = arg1[1] + *(int *)(value4 + 0xc);
  }
  return 0;
}

