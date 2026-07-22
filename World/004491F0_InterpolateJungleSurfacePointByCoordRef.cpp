#include "tarzan_ghidra_types.hpp"

// Address: 0x004491F0
// Label: InterpolateJungleSurfacePointByCoordRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int InterpolateJungleSurfacePointByCoordRef
              (undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  int value;
  
  value = GetJungleSurfaceSegment(arg1,arg2);
  if (value != 0) {
    InterpolateJungleSurfacePointAtCoord(arg2,value,arg3);
  }
  return value;
}

