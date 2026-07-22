#include "tarzan_ghidra_types.hpp"

// Address: 0x00448F10
// Label: CCamera::BuildPoseFromIndexedJungleSurfacePath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::BuildPoseFromIndexedJungleSurfacePath
               (undefined4 *cameraState,undefined4 target,undefined4 outPitch,undefined4 outYaw,
               undefined4 outDistance,undefined4 pathIndex,undefined4 flags)

{
  int value;
  
  value = cameraState[1] * 4 + 4;
  CCamera::BuildPoseFromJungleSurfacePath
            (*(int *)(value + g_CollisionSurfaceTable) + value + g_CollisionSurfaceTable,*cameraState,
             target,outPitch,outYaw,outDistance,pathIndex,flags);
  return;
}

