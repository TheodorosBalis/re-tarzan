#include "tarzan_ghidra_types.hpp"

// Address: 0x00448960
// Label: SampleJungleSurfacePointWithFloorOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SampleJungleSurfacePointWithFloorOffset(int arg1,int *arg2,int *arg3)

{
  short shortValue;
  short shortValue2;
  int offset;
  int offset2;
  uint value;
  int offset3;
  int offset4;
  int offset5;
  
  offset5 = arg2[3];
  if (offset5 == arg1) {
    *arg3 = *arg2;
    arg3[1] = arg2[1];
    arg3[2] = arg2[2];
    if (*(short *)((int)arg2 + 0x12) != 0) {
      arg3[3] = arg2[1] - (int)*(short *)((int)arg2 + 0x12);
      goto LAB_00448a3d;
    }
  }
  else {
    offset4 = arg1 - offset5;
    offset5 = arg2[10] - offset5;
    offset3 = ((arg2[8] - arg2[1]) * offset4) / offset5;
    offset = arg2[2];
    offset2 = arg2[9];
    shortValue = *(short *)((int)arg2 + 0x12);
    shortValue2 = *(short *)((int)arg2 + 0x2e);
    *arg3 = ((arg2[7] - *arg2) * offset4) / offset5 + *arg2;
    arg3[1] = arg2[1] + offset3;
    arg3[2] = ((offset2 - offset) * offset4) / offset5 + arg2[2];
    if ((*(short *)((int)arg2 + 0x12) != 0) && (*(short *)((int)arg2 + 0x2e) != 0)) {
      arg3[3] = ((arg2[1] - (int)*(short *)((int)arg2 + 0x12)) -
                   (((int)shortValue2 - (int)shortValue) * offset4) / offset5) + offset3;
      goto LAB_00448a3d;
    }
  }
  arg3[3] = -0x7fffffff;
LAB_00448a3d:
  value = arg2[5];
  if (((value & 0x100) != 0) &&
     (((value & 0xc000) == 0x4000 ||
      ((((value & 0xc000) == 0x8000 && ((value & 0x80) == 0)) || (arg1 != arg2[3])))))) {
    arg3[1] = 0x3ffffffe;
  }
  return;
}

