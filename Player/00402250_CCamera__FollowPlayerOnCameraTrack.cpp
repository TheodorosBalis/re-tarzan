#include "tarzan_ghidra_types.hpp"

// Address: 0x00402250
// Label: CCamera::FollowPlayerOnCameraTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::FollowPlayerOnCameraTrack(void)

{
  int *intCursor;
  int value4;
  int *intCursor2;
  int value5;
  uint value9;
  int value6;
  uint value10;
  int *intCursor3;
  int value7;
  uint value8;
  int value;
  int value2;
  int value3;
  
  intCursor2 = g_CameraFollowPlayerTarget;
  value3 = *(int *)(g_ActiveCameraAnchorEntry + 0x38);
  if (value3 != 0) {
    intCursor3 = g_CameraOverrideTargetPtr;
    if (g_CameraOverrideTargetPtr == (int *)0x0) {
      intCursor3 = (int *)(value3 + 0x14);
    }
    value3 = *(int *)(g_CollisionSurfaceTable + 4 + *(int *)(value3 + 0x110) * 4) + 0x20 +
             *(int *)(value3 + 0x110) * 4;
    value5 = value3 + g_CollisionSurfaceTable;
    value3 = intCursor3[2] - *(int *)(value3 + g_CollisionSurfaceTable);
    if (g_CameraTrackFollowSegmentProgress[2] < value3) {
      value3 = g_CameraTrackFollowSegmentProgress[2];
    }
    if (value3 < *(int *)(g_CameraTrackFollowSegmentIndex + 8)) {
      value3 = *(int *)(g_CameraTrackFollowSegmentIndex + 8);
    }
    value6 = *g_CameraFollowPlayerTarget;
    value7 = g_CameraFollowPlayerTarget[7];
    value = g_CameraFollowPlayerTarget[8];
    value4 = g_CameraFollowPlayerTarget[1];
    intCursor = g_CameraFollowPlayerTarget + 9;
    value2 = g_CameraFollowPlayerTarget[2] - g_CameraFollowPlayerTarget[9];
    value9 = GetAngleFromXZVector12Bit(value6 - value7,value2);
    if (value3 < *intCursor) {
      g_CameraFollowPlayerTarget = g_CameraFollowPlayerTarget + 7;
    }
    if (intCursor2[2] < value3) {
      g_CameraFollowPlayerTarget = g_CameraFollowPlayerTarget + -7;
    }
    if (g_CameraFollowPlayerTarget < g_CameraTrackFollowSegmentProgress) {
      g_CameraFollowPlayerTarget = g_CameraTrackFollowSegmentProgress;
    }
    g_CameraTrackFollowStartX =
         g_CameraTrackFollowStartX -
         (g_CameraTrackFollowStartX -
          (((((value6 - value7) * 0x100) / value2) * (value3 - intCursor2[2]) >> 8) + *intCursor2) >> 3);
    g_CameraTrackFollowStartY =
         g_CameraTrackFollowStartY -
         (g_CameraTrackFollowStartY -
          (((((value4 - value) * 0x100) / value2) * (value3 - intCursor2[2]) >> 8) + intCursor2[1]) >> 3);
    g_CameraTrackFollowStartZ =
         g_CameraTrackFollowStartZ - (g_CameraTrackFollowStartZ - value3 >> 3);
    value = g_CameraTrackFollowStartX - *intCursor3;
    value3 = g_CameraTrackFollowStartZ - intCursor3[2];
    value7 = g_CameraTrackFollowStartY - intCursor3[1];
    value6 = SqrtToInt(value3 * value3 + value * value);
    value3 = GetAngleFromXZVector12Bit(value,value3);
    value10 = value3 - 0x800U & 0xfff;
    value8 = (value9 & 0xfff) - 0x89f & 0xfff;
    value9 = (value9 & 0xfff) - 0x761 & 0xfff;
    if ((value8 < value10) || (value10 < 0x801)) {
      if ((value10 < value9) || (0x7ff < value10)) {
        value3 = -value10;
      }
      else {
        value3 = -value9;
      }
    }
    else {
      value3 = -value8;
    }
    value9 = GetAngleFromXZVector12Bit(value7,value6 >> 6);
    value3 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,value3);
    g_CameraYaw = g_CameraYaw + (short)(value3 >> 3);
    value3 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,-(value9 & 0xfff));
    g_CameraPitch = g_CameraPitch + (short)(value3 >> 3);
    g_CameraTrackSecondaryOffset = *(undefined4 *)(value5 + 4);
    g_CameraFocusX = g_CameraTrackFollowStartX;
    g_CameraFocusY = g_CameraTrackFollowStartY;
    g_CameraFocusZ = g_CameraTrackFollowStartZ;
  }
  return;
}

