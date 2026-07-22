#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F120
// Label: PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
PushEntitySceneObjectOutsidePathBoundaryRadiusXZ
          (int arg1,undefined4 arg2,int arg3,int *arg4,int arg5)

{
  int entry;
  
  entry = SqrtToInt(arg2);
  if (arg5 <= entry >> 6) {
    return 0;
  }
  arg5 = arg5 - (entry >> 6);
  if (arg3 == 0) {
    *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) + (*arg4 * arg5 >> 0xc);
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\f') {
      *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) + (arg4[2] * arg5 >> 0xc);
      return 1;
    }
  }
  else if (arg3 == 1) {
    *(int *)(arg1 + 0x14) = *(int *)(arg1 + 0x14) - (*arg4 * arg5 >> 0xc);
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) != '\f') {
      *(int *)(arg1 + 0x1c) = *(int *)(arg1 + 0x1c) - (arg4[2] * arg5 >> 0xc);
    }
  }
  return 1;
}

