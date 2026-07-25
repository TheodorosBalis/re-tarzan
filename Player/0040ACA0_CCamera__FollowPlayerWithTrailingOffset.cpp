#include "tarzan_ghidra_types.hpp"

// Address: 0x0040ACA0
// Label: CCamera::FollowPlayerWithTrailingOffset
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::FollowPlayerWithTrailingOffset(int cameraState,int target)

{
  int *intCursor;
  int localState3;
  int localState2;
  int localState;
  
  intCursor = (int *)(cameraState + 0x14);
  g_CameraUpdateTargetPose = *intCursor;
  g_CameraTrailingOffsetX = *(int *)(cameraState + 0x18);
  localState2 = g_CameraTrailingOffsetX + -0x700;
  _g_CameraTrailingOffsetZ = *(int *)(cameraState + 0x1c);
  localState3 = (g_LevelEntityInitScratch_Field0388 * 0x500 >> 0xc) + g_CameraUpdateTargetPose;
  localState = (g_SinCosTable12Bit * 0x500 >> 0xc) + _g_CameraTrailingOffsetZ;
  if (*(int *)(cameraState + 0x108) == 2) {
    ClipMovementAgainstNatureTerrainCollisionRegions
              (*(undefined4 *)(cameraState + 0x10c),intCursor,&localState3,0x400,&localState3);
  }
  EaseOrSnapInt3Vector(&g_CameraUpdateEyePoint,&localState3,3,target);
  CCamera::BuildTargetPoseFromLookAt(&g_CameraUpdateEyePoint,intCursor,&g_CameraUpdateTargetPose);
  _g_CameraUpdateDistanceScale = 0x118;
  CCamera::BlendOrSnapToTargetPose(&g_CameraFocusX,&g_CameraUpdateTargetPose,~-(uint)(target != 0) & 0x4be5d0);
  return;
}

