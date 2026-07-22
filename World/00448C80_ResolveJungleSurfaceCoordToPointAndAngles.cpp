#include "tarzan_ghidra_types.hpp"

// Address: 0x00448C80
// Label: ResolveJungleSurfaceCoordToPointAndAngles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4
ResolveJungleSurfaceCoordToPointAndAngles
          (undefined4 arg1,undefined4 arg2,undefined4 arg3,undefined4 arg4)

{
  undefined4 value;
  
  value = FindJungleSurfaceSegmentAtCoord(arg1,arg2);
  InterpolateJungleSurfacePointAtCoord(arg2,value,arg3);
  ComputeJungleSurfaceSegmentAngles(value,arg4);
  return value;
}

