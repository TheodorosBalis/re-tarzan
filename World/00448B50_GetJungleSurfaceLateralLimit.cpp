#include "tarzan_ghidra_types.hpp"

// Address: 0x00448B50
// Label: GetJungleSurfaceLateralLimit
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetJungleSurfaceLateralLimit(int arg1,int arg2)

{
  Entity *entity2 = (Entity *)arg2;
  int value;
  
  if (arg2 == 0) {
    return 0;
  }
  if ((*(uint *)(arg2 + 0x14) & 0x2000) != 0) {
    return (int)*(short *)(arg2 + 0x10);
  }
  value = *(int *)(arg2 + 0x28) - entity2->previous;
  if (value == 0) {
    return (int)*(short *)(arg2 + 0x10);
  }
  return (((int)*(short *)(arg2 + 0x2c) - (int)*(short *)(arg2 + 0x10)) *
         (arg1 - entity2->previous)) / value + (int)*(short *)(arg2 + 0x10);
}

