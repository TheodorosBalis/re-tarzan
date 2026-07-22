#include "tarzan_ghidra_types.hpp"

// Address: 0x00480B90
// Label: CCamera::UpdateLeafSwimmingCamera
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CCamera::UpdateLeafSwimmingCamera(void)

{
  short shortValue;
  ushort value5;
  int value;
  int value2;
  uint value6;
  int value3;
  int value4;
  
  CEntities::UpdateRandomAmbientSoundCue();
  if (g_LeafSwimmingCameraInitialized == 0) {
    g_CameraFocusX =
         ((short)(&g_SinCosTable12Bit)[(int)g_LeafSwimmingCameraOrbitAngle + 0x400U & 0xfff] *
          g_LeafSwimmingLateStageMotionTable >> 0xc) + *(int *)(g_PlayerEntitySceneObjectData + 8);
    g_CameraFocusZ =
         ((short)(&g_SinCosTable12Bit)[(int)g_LeafSwimmingCameraOrbitAngle - 0x800U & 0xfff] *
          g_LeafSwimmingLateStageMotionTable >> 0xc) +
         *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    g_CameraFocusY = *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0x200;
    value4 = g_CameraFocusY - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value = g_CameraFocusX - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value3 = g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    g_LeafSwimmingCameraOrbitPointX = g_CameraFocusX;
    g_LeafSwimmingCameraOrbitPointY = g_CameraFocusY;
    g_LeafSwimmingCameraOrbitPointZ = g_CameraFocusZ;
    value2 = SqrtToInt(value * value + value3 * value3);
    SqrtToInt(value4 * value4 + value * value + value3 * value3);
    shortValue = GetAngleFromXZVector12Bit(-value,value3);
    g_CameraYaw = shortValue - 0x800U & 0xfff;
    value5 = GetAngleFromXZVector12Bit(value4,value2 >> 6);
    g_CameraPitch = -(value5 & 0xfff);
    g_LeafSwimmingCameraYawTarget = 0;
    g_LeafSwimmingCameraVerticalOrbitOffset = 0x200;
    CPlayerHero::AdvanceLeafSwimmingSurfaceTrack();
    g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingLateStageMotionTable;
    g_CameraEyeDistanceFromFocus = g_LeafSwimmingLateStageMotionTable;
    g_LeafSwimmingCameraTargetDistanceScale = g_LeafSwimmingDefaultCameraDistanceScale;
    g_CameraTrackSecondaryOffset = g_LeafSwimmingDefaultCameraDistanceScale;
    g_CameraPitch = -0xe26;
    g_LeafSwimmingCameraInitialized = 1;
  }
  value = g_LeafSwimmingLateStageMotionTable + 0x100;
  if (g_LeafSwimmingCameraDistanceBoostActive == 0) {
    value = g_LeafSwimmingLateStageMotionTable;
  }
  if (g_LeafSwimmingMidStageMotionTable == 0) {
    if (g_LeafSwimmingCameraDistanceBoostActive == 0) {
      g_CameraTrackSecondaryOffset = 0x100;
      g_LeafSwimmingCameraOrbitPointX =
           g_LeafSwimmingCameraOrbitPointX -
           (g_LeafSwimmingCameraOrbitPointX -
            (((short)(&g_SinCosTable12Bit)[0x400U - (int)g_LeafSwimmingCameraOrbitAngle & 0xfff] *
              value >> 0xc) + *(int *)(g_PlayerEntitySceneObjectData + 8)) >> 5);
      g_LeafSwimmingCameraOrbitPointY =
           g_LeafSwimmingCameraOrbitPointY -
           (g_LeafSwimmingCameraOrbitPointY -
            (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_LeafSwimmingCameraVerticalOrbitOffset
            ) >> 5);
      g_LeafSwimmingCameraOrbitPointZ =
           g_LeafSwimmingCameraOrbitPointZ -
           (g_LeafSwimmingCameraOrbitPointZ -
            (((short)(&g_SinCosTable12Bit)[-(int)g_LeafSwimmingCameraOrbitAngle - 0x800U & 0xfff] *
              value >> 0xc) + *(int *)(g_PlayerEntitySceneObjectData + 0x10)) >> 5);
      value3 = g_LeafSwimmingCameraOrbitPointX - *(int *)(g_PlayerEntitySceneObjectData + 8);
      value4 = g_LeafSwimmingCameraOrbitPointZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
      value = (g_LeafSwimmingCameraOrbitPointY - *(int *)(g_PlayerEntitySceneObjectData + 0xc)) +
              -0x400;
      value2 = SqrtToInt(value3 * value3 + value4 * value4);
      SqrtToInt(value * value + value3 * value3 + value4 * value4);
      value3 = GetAngleFromXZVector12Bit(-value3,value4);
      if (g_LeafSwimmingCameraDynamicPitchActive == 0) {
        value = -0xe26;
        g_LeafSwimmingCameraVerticalOrbitOffset = 0x200;
      }
      else {
        value6 = GetAngleFromXZVector12Bit(value,value2 >> 6);
        value = 0x100 - (value6 & 0xfff);
        g_LeafSwimmingCameraVerticalOrbitOffset = 0x180;
      }
      value = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,value);
      g_CameraPitch = g_CameraPitch + (short)(value >> 4);
      value = GetWrappedSignedAngleDelta12Bit((int)(short)g_CameraYaw,value3 - 0x800U & 0xfff);
      g_CameraYaw = g_CameraYaw + (short)(value >> 2);
      g_CameraFocusX = *(int *)(g_PlayerEntitySceneObjectData + 8);
      g_CameraFocusY = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
      g_CameraFocusZ = *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    }
    g_CameraEyeDistanceFromFocus =
         g_CameraEyeDistanceFromFocus -
         (g_CameraEyeDistanceFromFocus - g_LeafSwimmingCameraTargetDistance >> 4);
    g_CameraTrackSecondaryOffset =
         g_CameraTrackSecondaryOffset -
         (g_CameraTrackSecondaryOffset - g_LeafSwimmingCameraTargetDistanceScale >> 5);
  }
  return;
}

