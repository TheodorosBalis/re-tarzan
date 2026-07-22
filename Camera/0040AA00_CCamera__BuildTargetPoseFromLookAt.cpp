#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AA00
// Label: CCamera::BuildTargetPoseFromLookAt
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

struct CameraPosePrefix {
  undefined4 x;
  undefined4 y;
  undefined4 z;
};

void CCamera::BuildTargetPoseFromLookAt(undefined4 lookAtSource,undefined4 *sourcePose,undefined4 *targetPose)

{
  CameraPosePrefix *sourcePrefix;
  CameraPosePrefix *targetPrefix;
  int lookAtDistance;
  
  sourcePrefix = (CameraPosePrefix *)sourcePose;
  targetPrefix = (CameraPosePrefix *)targetPose;
  *targetPrefix = *sourcePrefix;
  lookAtDistance = CCamera::ComputeLookAtAnglesAndDistance((int *)lookAtSource,(int *)sourcePose,
                                                           (ushort *)(targetPose + 0x14));
  targetPose[5] = lookAtDistance;
  targetPose[3] = 0;
  targetPose[4] = 0;
  return;
}
