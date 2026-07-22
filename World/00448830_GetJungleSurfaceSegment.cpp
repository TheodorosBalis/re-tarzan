#include "tarzan_ghidra_types.hpp"

// Address: 0x00448830
// Label: GetJungleSurfaceSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetJungleSurfaceSegment(int arg1,undefined4 arg2)

{
  int value;
  
  value = arg1 * 4 + 4;
  FindJungleSurfaceSegmentAtCoord
            (*(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable,arg2);
  return 0;
}

