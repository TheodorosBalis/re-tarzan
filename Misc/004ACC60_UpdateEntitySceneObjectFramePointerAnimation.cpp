#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACC60
// Label: UpdateEntitySceneObjectFramePointerAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntitySceneObjectFramePointerAnimation(int *arg1,int arg2)

{
  int entry;
  uint value;
  uint value2;
  
  entry = *(int *)(arg2 + 4);
  value = arg1[4] + arg1[3];
  arg1[4] = value;
  if (arg1[3] < 0) {
    if (-1 < (int)(value & 0xffffff00)) goto LAB_004accc0;
    value2 = arg1[2] * 0x100 + (value & 0xffffff00);
  }
  else {
    if ((int)value >> 8 < arg1[2]) goto LAB_004accc0;
    value2 = (value & 0xffffff00) + arg1[2] * -0x100;
  }
  arg1[4] = value2 ^ value & 0xff;
LAB_004accc0:
  *(undefined4 *)(entry + arg1[1] * 0x26 + 0x1e) =
       *(undefined4 *)(*arg1 + (arg1[4] >> 8) * 4 + (int)arg1);
  return;
}

