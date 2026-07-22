#include "tarzan_ghidra_types.hpp"

// Address: 0x00448FE0
// Label: FindPreviousJungleSurfaceSegmentFromCoordRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FindPreviousJungleSurfaceSegmentFromCoordRef(int *arg1,undefined4 arg2,undefined4 arg3)

{
  int foundIndex;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  foundIndex = GetJungleSurfaceSegment(arg1[1],*arg1);
  if (*(int *)(foundIndex + 0xc) == *arg1) {
    _g_JungleSurfaceSearchScratch_Field0008 = arg1[1];
    _g_JungleSurfaceSearchScratch_Field0010 = 0xffffffff;
    _g_JungleSurfaceSearchScratch_Field000C = *arg1 + -1;
    g_JungleSurfaceSearchScratch_Field0014 = foundIndex;
    if (*arg1 == *(int *)(foundIndex + 0xc)) {
      TraceJungleSurfaceMoveAcrossPreviousSegment
                (&g_JungleSurfaceSearchScratch_Field0008,arg2,arg3);
      foundIndex = g_JungleSurfaceSearchScratch_Field0014;
    }
  }
  return foundIndex;
}

