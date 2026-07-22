#include "tarzan_ghidra_types.hpp"

// Address: 0x004ACBF0
// Label: UpdateEntitySceneObjectFrameIndexAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntitySceneObjectFrameIndexAnimation(int *arg1,int arg2)

{
  int entry;
  uint value;
  uint value2;
  
  entry = *(int *)(arg2 + 4) + *arg1 * 0x26;
  value = arg1[2] + arg1[1];
  arg1[2] = value;
  if (arg1[1] < 1) {
    if (-1 < (int)(value & 0xffffff00)) goto LAB_004acc54;
    value2 = (uint)*(ushort *)(entry + 4) * 0x100 + (value & 0xffffff00);
  }
  else {
    if ((int)value >> 8 < (int)(uint)*(ushort *)(entry + 4)) goto LAB_004acc54;
    value2 = (value & 0xffffff00) + (uint)*(ushort *)(entry + 4) * -0x100;
  }
  arg1[2] = value2 ^ value & 0xff;
LAB_004acc54:
  *(char *)(entry + 0x15) = (char)((uint)arg1[2] >> 8);
  return;
}

