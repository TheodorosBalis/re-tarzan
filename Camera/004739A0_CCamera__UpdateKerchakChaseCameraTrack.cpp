#include "tarzan_ghidra_types.hpp"

// Address: 0x004739A0
// Label: CCamera::UpdateKerchakChaseCameraTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::UpdateKerchakChaseCameraTrack(void)

{
  int value;
  int value2;
  uint value5;
  int value3;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + 8 + g_CollisionSurfaceTable);
  value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x10) + 0x14 + g_CollisionSurfaceTable);
  value3 = *(int *)(g_CollisionSurfaceTable + 0x10) + g_CollisionSurfaceTable;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if ((value != 0) && (g_KerchakChaseCameraTrackPaused == 0)) {
    g_KerchakChaseCameraLeadSmoothed =
         g_KerchakChaseCameraLeadSmoothed -
         (g_KerchakChaseCameraLeadSmoothed - _g_KerchakChaseCameraLeadTarget >> 4);
    value3 = *(int *)(value3 + 0x4c + *(int *)(value + 0x18) * 0x1c) + *(int *)(value + 0x28);
    if (value4 < value3) {
      value3 = value4;
    }
    value3 = (value3 * ((value2 << 8) / value4) >> 8) + 0xdac +
            g_KerchakChaseCameraForwardLookaheadZOffset;
    if (value2 < value3) {
      value3 = value2;
    }
    InterpolateJungleSurfacePointByCoordRef(0,value3,&localState3);
    g_CameraFocusX =
         g_KerchakChaseCameraFocusSmoothedX - (g_KerchakChaseCameraFocusSmoothedX - localState3 >> 4);
    g_CameraFocusY =
         g_KerchakChaseCameraFocusSmoothedY - (g_KerchakChaseCameraFocusSmoothedY - localState2 >> 4);
    g_CameraFocusZ =
         g_KerchakChaseCameraFocusSmoothedZ - (g_KerchakChaseCameraFocusSmoothedZ - localState >> 4);
    g_KerchakChaseCameraForwardLookaheadZOffset =
         (g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObject + 0x1c)) + 0x1194;
    value4 = g_CameraFocusX - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value3 = g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value = g_CameraFocusY - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    g_KerchakChaseCameraFocusSmoothedX = g_CameraFocusX;
    g_KerchakChaseCameraFocusSmoothedY = g_CameraFocusY;
    g_KerchakChaseCameraFocusSmoothedZ = g_CameraFocusZ;
    value2 = SqrtToInt(value3 * value3 + value4 * value4);
    value3 = GetAngleFromXZVector12Bit(value4,value3);
    value5 = GetAngleFromXZVector12Bit(value,value2 >> 6);
    value3 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,-(value3 - 0x800U & 0xfff));
    g_CameraYaw = g_CameraYaw + (short)(value3 >> 3);
    value3 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,-(value5 & 0xfff));
    g_CameraPitch = g_CameraPitch + (short)(value3 >> 3);
    g_CameraEyeDistanceFromFocus = 0;
    g_CameraTrackSecondaryOffset = 0;
  }
  return;
}

