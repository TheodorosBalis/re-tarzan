#include "tarzan_ghidra_types.hpp"

// Address: 0x00493840
// Label: ResolveEntitySceneObjectTerrainCollision
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
ResolveEntitySceneObjectTerrainCollision(int *arg1,int *arg2,int *arg3,int *arg4)

{
  int entry;
  int entry2;
  int entry3;
  
  entry2 = arg3[2];
  entry = arg2[2];
  entry3 = arg2[1];
  *arg4 = *arg2 + *arg3;
  arg4[1] = entry3;
  arg4[2] = entry2 + entry;
  entry2 = ResolvePositionAgainstTerrainCollisionRegion(arg1,arg4,0xaf,arg4);
  if (entry2 != 0) {
    if (*arg1 != 2) {
      return 0;
    }
    entry2 = ResolvePositionAgainstTerrainCollisionRegion(arg1,arg4,0xaf,arg4);
    if (entry2 != 0) {
      if (*arg1 != 2) {
        return 0;
      }
      entry2 = ResolvePositionAgainstTerrainCollisionRegion(arg1,arg4,0xaf,arg4);
      if (entry2 != 0) {
        if (*arg1 != 2) {
          return 0;
        }
        entry2 = ResolvePositionAgainstTerrainCollisionRegion(arg1,arg4,0xaf,arg4);
        if (entry2 != 0) {
          if (*arg1 != 2) {
            return 0;
          }
          *arg4 = *arg2;
          arg4[1] = arg2[1];
          arg4[2] = arg2[2];
        }
      }
    }
  }
  if (*arg1 == 2) {
    if (*( undefined1 *)((int)&g_LevelTransitionContext + 2) == '\v') {
      entry3 = -entry3;
    }
    else {
      entry3 = FindNearestNatureTerrainGroundOffset(&g_CurrentWorldSceneContext,arg4,200);
    }
    arg1[6] = *arg2;
    arg1[7] = arg2[1];
    arg1[8] = arg2[2];
    entry2 = *arg2;
    arg4[1] = entry3;
    *arg4 = *arg4 - entry2;
    arg4[2] = arg4[2] - arg2[2];
  }
  return 0;
}

