#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F3A0
// Label: IsEntitySceneObjectNearSurfaceCoordAttachment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool IsEntitySceneObjectNearSurfaceCoordAttachment(int arg1,int arg2,int arg3)

{
  uint value;
  uint value2;
  
  if (((*(int *)(arg2 + 0x108) == 1) && (*(int *)(arg3 + 0x108) == 1)) &&
     (*(int *)(arg2 + 0x110) == *(int *)(arg3 + 0x110))) {
    value = *(int *)(arg3 + 0x10c) - *(int *)(arg2 + 0x10c);
    value2 = (int)value >> 0x1f;
    return (int)((value ^ value2) - value2) < (int)*(short *)(arg1 + 6);
  }
  return false;
}

