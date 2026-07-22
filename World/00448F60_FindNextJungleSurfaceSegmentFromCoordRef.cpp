#include "tarzan_ghidra_types.hpp"

// Address: 0x00448F60
// Label: FindNextJungleSurfaceSegmentFromCoordRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FindNextJungleSurfaceSegmentFromCoordRef(int *arg1,undefined4 arg2,undefined4 arg3)

{
  int foundIndex;
  uint value;
  
  g_JungleSurfaceTraceProbeSpan = 0x20;
  foundIndex = GetJungleSurfaceSegment(arg1[1],*arg1);
  if ((*(uint *)(foundIndex + 0x14) & 0x2000) != 0) {
    return 0;
  }
  g_NextJungleSurfaceProbeDistance = *(int *)(foundIndex + 0x28) - *arg1;
  _g_NextJungleSurfaceProbeSurfaceIndex = arg1[1];
  _g_NextJungleSurfaceProbeCoord = *arg1 + g_NextJungleSurfaceProbeDistance;
  g_NextJungleSurfaceProbeSegment = foundIndex;
  value = TraceJungleSurfaceMoveAcrossNextSegment
                    (&g_NextJungleSurfaceProbeSurfaceIndex,arg2,arg3);
  if (((value & 2) != 0) && (0 < g_NextJungleSurfaceProbeDistance)) {
    g_NextJungleSurfaceProbeSegment = g_NextJungleSurfaceProbeSegment + 0x1c;
  }
  return g_NextJungleSurfaceProbeSegment;
}

