#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC820
// Label: ComputeEntitySfxSpatialParams
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ComputeEntitySfxSpatialParams(int *arg1)

{
  ProjectTriangleVertexAndReturnViewCoords
            ((float)(*arg1 - g_CameraFocusX),(float)(arg1[1] - g_CameraFocusY),
             (float)(arg1[2] - g_CameraFocusZ),&g_EntitySfxSpatialX,&g_EntitySfxSpatialY,
             &g_EntitySfxSpatialZ);
  g_EntitySfxSpatialX = g_EntitySfxSpatialX * _g_EntitySfxSpatialXYScale;
  g_EntitySfxSpatialY = g_EntitySfxSpatialY * _g_EntitySfxSpatialXYScale;
  g_EntitySfxSpatialZ = g_EntitySfxSpatialZ * _g_EntitySfxSpatialZScale;
  return;
}

