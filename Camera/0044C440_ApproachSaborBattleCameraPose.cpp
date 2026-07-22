#include "tarzan_ghidra_types.hpp"

// Address: 0x0044C440
// Label: ApproachSaborBattleCameraPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ApproachSaborBattleCameraPose
              (int cameraState,int target,int outPitch,int outYaw,int outDistance,int pathIndex,
              undefined4 flags,undefined4 arg8,undefined4 arg9)

{
  uint value;
  uint value2;
  uint value3;
  uint value4;
  uint value5;
  uint value6;
  uint value7;
  uint value8;
  uint value9;
  
  value9 = target - g_CameraFocusY;
  value8 = cameraState - g_CameraFocusX;
  value7 = outYaw - g_SaborBattleCameraDistance;
  value = outDistance - g_CameraTrackSecondaryOffset;
  value6 = outPitch - g_CameraFocusZ;
  value2 = pathIndex - g_CameraEyeDistanceFromFocus;
  value3 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,flags);
  value4 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,arg8);
  value5 = GetWrappedSignedAngleDelta12Bit((int)g_CameraRoll,arg9);
  g_CameraFocusX = g_CameraFocusX + ((int)value8 >> 2);
  g_CameraFocusY = g_CameraFocusY + ((int)value9 >> 2);
  g_CameraFocusZ = g_CameraFocusZ + ((int)value6 >> 2);
  g_SaborBattleCameraDistance = g_SaborBattleCameraDistance + ((int)value7 >> 2);
  g_CameraTrackSecondaryOffset = g_CameraTrackSecondaryOffset + ((int)value >> 2);
  g_CameraEyeDistanceFromFocus = g_CameraEyeDistanceFromFocus + ((int)value2 >> 2);
  *( undefined2 *)((int)&cameraState + 0) = (short)((int)value3 >> 2);
  g_CameraPitch = g_CameraPitch + (short)cameraState;
  g_CameraYaw = g_CameraYaw + (short)((int)value4 >> 2);
  g_CameraRoll = g_CameraRoll + (short)((int)value5 >> 2);
  return (int)(value5 | value4 | value3 | value2 | value | value7 | value6 | value9 | value8) >> 2;
}

