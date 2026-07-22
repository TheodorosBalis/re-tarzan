#include "tarzan_ghidra_types.hpp"

// Address: 0x00448860
// Label: InterpolateJungleSurfaceHeightAtCoord
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int InterpolateJungleSurfaceHeightAtCoord(int arg1,int arg2)

{
  int value;
  
  if ((*(uint *)(arg2 + 0x14) & 0x2000) != 0) {
    return *(int *)(arg2 + 4);
  }
  value = *(int *)(arg2 + 0x28) - *(int *)(arg2 + 0xc);
  if (value == 0) {
    return *(int *)(arg2 + 4);
  }
  return ((*(int *)(arg2 + 0x20) - *(int *)(arg2 + 4)) * (arg1 - *(int *)(arg2 + 0xc)))
         / value + *(int *)(arg2 + 4);
}

