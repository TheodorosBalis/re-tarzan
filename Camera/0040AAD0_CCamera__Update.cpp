#include "tarzan_ghidra_types.hpp"

// Address: 0x0040AAD0
// Label: CCamera::Update
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::Update(char arg1)

{
  short shortValue;
  int value;
  undefined *dataCursor;
  
  value = *(int *)(g_ActiveCameraAnchorEntry + 0x38);
  if (value != 0) {
    switch(g_CameraFollowMode) {
    case 0:
    case 2:
    case 3:
      return;
    case 1:
      break;
    case 4:
      CCamera::FollowPlayerWithTrailingOffset(value,arg1);
      return;
    case 5:
      g_CameraDistanceScale = 0x140;
      return;
    case 6:
      CCamera::FollowPlayerOnAnchorPath(value,arg1);
      return;
    default:
      g_CameraFocusX = *(undefined4 *)(value + 0x14);
      g_CameraFocusY = *(undefined4 *)(value + 0x18);
      g_CameraFocusZ = *(undefined4 *)(value + 0x1c);
      return;
    case 0xb:
      CCamera::FollowPlayerOnCameraTrack();
      return;
    case 0xc:
      g_CameraOverrideTargetPtr = &g_CameraOverrideTargetX;
      break;
    case 0xd:
      CCamera::UpdateYoungTarzanOnStorkCameraTrack();
      return;
    case 0xe:
      CCamera::UpdateAdultTarzanElephantRideCameraTrack();
      return;
    case 0xf:
      CCamera::UpdateLeafSwimmingCamera();
      return;
    case 0x10:
      CCamera::UpdateSaborBattleCamera();
      return;
    case 0x11:
      CCamera::UpdateStampedeCameraTrack();
      return;
    case 0x12:
      CCamera::UpdateKerchakChaseCameraTrack();
      return;
    case 0x13:
      CCamera::UpdateClaytonBattleCamera();
      return;
    case 0x14:
      CCamera::UpdateJaneCameraTrack();
      return;
    }
    if (g_CameraOverrideTargetPtr == (undefined *)0x0) {
      shortValue = *(short *)(value + 0xa2);
      dataCursor = (undefined *)(value + 0x14);
    }
    else {
      shortValue = *(short *)(value + 0xa2);
      dataCursor = g_CameraOverrideTargetPtr;
    }
    CCamera::BuildPoseFromIndexedJungleSurfacePath(value + 0x10c,dataCursor,&g_CameraUpdateEyePoint,&g_CameraUpdateTargetPose,(int)shortValue,(-(uint)(((byte)g_CameraFollowFlags & 0x80) != 0) & 2) - 1,arg1);
    CCamera::BlendOrSnapToTargetPose(&g_CameraFocusX,&g_CameraUpdateTargetPose,~-(uint)(arg1 != '\0') & 0x4be510);
    return;
  }
  return;
}

