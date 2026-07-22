#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AD80
// Label: CCamera::FollowPlayerOnAnchorPath
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::FollowPlayerOnAnchorPath(int cameraState,int target)

{
  int value;
  short shortValue;
  int value2;
  int value3;
  int value4;
  int value5;
  
  if (*(int *)(cameraState + 0x108) == 1) {
    if (g_CameraOverrideTargetPtr == 0) {
      value5 = cameraState + 0x14;
      shortValue = *(short *)(cameraState + 0xa2);
    }
    else {
      shortValue = *(short *)(cameraState + 0xa2);
      value5 = g_CameraOverrideTargetPtr;
    }
    CCamera::BuildPoseFromIndexedJungleSurfacePath
              (cameraState + 0x10c,value5,&g_CameraUpdateEyePoint,&g_CameraUpdateTargetPose,(int)shortValue,
               (-(uint)(((byte)g_CameraFollowFlags & 0x80) != 0) & 2) - 1,1);
    CCamera::BlendOrSnapToTargetPose
              (&g_CameraFocusX,&g_CameraUpdateTargetPose,~-(uint)(target != 0) & 0x4be4d8);
  }
  else if (*(int *)(cameraState + 0x108) == 2) {
    value5 = *(int *)(cameraState + 0x10c);
    value2 = *(int *)(value5 + 0x34);
    if (value2 != 0) {
      value = value2 + 0x34 + value5;
      value3 = *(int *)(value + 0x2c);
      value5 = *(int *)(cameraState + 0x1c) - *(int *)(value2 + 0x6c + value5);
      if (*(int *)(value + 4) <= value5) {
        value5 = *(int *)(value + 4) + -1;
      }
      value4 = FindJungleSurfaceSegmentAtCoord(value,value5);
      value2 = value3 + value + 0x5c + (((value4 - value) + -0x30) / 0x1c) * 0x1c;
      InterpolateJungleSurfacePointAtCoord
                (((*(int *)(value2 + 0x28) - *(int *)(value2 + 0xc)) * (value5 - *(int *)(value4 + 0xc))
                 ) / (*(int *)(value4 + 0x28) - *(int *)(value4 + 0xc)) + *(int *)(value2 + 0xc),value2,
                 &g_CameraUpdateEyePoint);
      InterpolateJungleSurfacePointAtCoord(value5,value4,&g_CameraUpdateTargetPose);
      _g_CameraUpdateTargetDistance =
           CCamera::ComputeLookAtAnglesAndDistance
                     (&g_CameraUpdateEyePoint,&g_CameraUpdateTargetPose,
                      &g_CameraUpdateTargetPitchYaw);
      _g_CameraAnchorPathProgress = 0;
      _g_CameraAnchorPathSegment = 0;
      _g_CameraUpdateDistanceScale = 0x140;
      g_CameraUpdateTargetPose = *(undefined4 *)(cameraState + 0x14);
      g_CameraTrailingOffsetX = *(undefined4 *)(cameraState + 0x18);
      _g_CameraTrailingOffsetZ = *(undefined4 *)(cameraState + 0x1c);
      CCamera::BlendOrSnapToTargetPose
                (&g_CameraFocusX,&g_CameraUpdateTargetPose,~-(uint)(target != 0) & 0x4be600);
    }
  }
  _g_AnchorPathCameraScratch_Field0008 = 0;
  _g_AnchorPathCameraScratch_Field000C = (ushort)g_RockinTheBoatShipSwayVelocity & 0xfff;
  return;
}

