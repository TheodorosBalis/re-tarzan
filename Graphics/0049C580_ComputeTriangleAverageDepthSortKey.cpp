#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C580
// Label: ComputeTriangleAverageDepthSortKey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int ComputeTriangleAverageDepthSortKey(void)

{
  float value;
  int value2;
  
  value = (g_ProjectCameraZ2 + g_ProjectCameraZ1 + g_ProjectCameraZ0) * _g_FloatOneThird;
  if (_g_RenderNearClipDepth < value) {
    _g_TriangleNearPlaneClipScratch = (double)(value + (float)_g_DoubleToIntRoundingBias);
    value2 = (int)g_TriangleNearPlaneClipScratch;
    return value2;
  }
  return 1;
}

