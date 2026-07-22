#include "tarzan_ghidra_types.hpp"

// Address: 0x00411180
// Label: CCamera::UpdateClaytonBattleCamera
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined2 * CCamera::UpdateClaytonBattleCamera(void)

{
  ushort value2;
  int value;
  undefined2 *dataCursor;
  
  if ((g_ClaytonEntity == 0) || (*(int *)(g_ClaytonEntity + 0x38) == 0)) {
    g_ClaytonBattleCameraState = 0;
  }
  dataCursor = (undefined2 *)0x0;
  if (g_ClaytonBattleCameraState != 1) {
    if (g_ClaytonBattleCameraState == 2) {
      if (g_CameraYaw == 0) {
        value = *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x14);
        g_CameraFocusX = (*(int *)(g_PlayerEntitySceneObjectData + 4) + value) / 2;
        g_CameraFocusY =
             (*(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x18) +
             *(int *)(g_PlayerEntitySceneObjectData + 6)) / 2 + -0xf0;
        value = (*(int *)(g_PlayerEntitySceneObjectData + 4) - value) + 600 +
                g_CameraEyeDistanceFromFocus * 4;
        dataCursor = (undefined2 *)(value * 0x66666667);
        g_CameraEyeDistanceFromFocus = value / 5;
        if (g_CameraEyeDistanceFromFocus < 0x708) {
          g_CameraEyeDistanceFromFocus = 0x708;
        }
      }
      else {
        CCamera::ApproachClaytonBattleHorizontalFraming
                  ((int *)&g_CameraFocusX,
                   *(int *)(g_PlayerEntitySceneObjectData + 4) -
                   *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x14));
        dataCursor = (undefined2 *)0;
      }
      if ((g_CameraYaw != 0) && (g_CameraYaw = g_CameraYaw + 0x10, 0xfff < g_CameraYaw)) {
        g_CameraYaw = 0;
      }
    }
    else {
      if (g_ClaytonBattleCameraState != 9) {
        g_CameraFocusX = 0;
        g_CameraFocusZ = 0;
        g_CameraFocusY = *(int *)(g_PlayerEntitySceneObjectData + 6) + -0xf0;
        g_CameraEyeDistanceFromFocus = 0x12c0;
        value = GetAngleFromXZVector12Bit
                          (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                           *(undefined4 *)(g_PlayerEntitySceneObjectData + 4));
        g_CameraYaw = (short)(undefined2 *)(value + 0x400);
        g_CameraPitch = 100;
        return (undefined2 *)(value + 0x400);
      }
      if (g_CameraYaw != 0) {
        CCamera::ApproachClaytonBattleHorizontalFraming
                  ((int *)&g_CameraFocusX,
                   *(int *)(g_PlayerEntitySceneObjectData + 4) -
                   *(int *)(*(int *)(g_ClaytonEntity + 0x38) + 0x14));
      }
      g_CameraYaw = g_CameraYaw + 0x1e;
      if (0x1000 < g_CameraYaw) {
        g_ClaytonBattleCameraState = 2;
        g_CameraYaw = 0;
      }
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles(g_PlayerEntitySceneObject,0x5a);
      value2 = (ushort)g_ClaytonBattleFallPoseFrameIndex + 1;
      *( undefined2 *)((int)&g_ClaytonBattleFallPoseFrameIndex + 0) = value2;
      if (0x13 < value2) {
        *( undefined2 *)((int)&g_ClaytonBattleFallPoseFrameIndex + 0) = 0;
      }
      *(undefined2 **)g_PlayerEntitySceneObjectData =
           (undefined2 *)(uint)*(undefined2 *)
            (&g_ClaytonBattleFallPoseFrameTable +
            (uint)(ushort)g_ClaytonBattleFallPoseFrameIndex * 4);
      dataCursor = (undefined2 *)g_PlayerEntitySceneObjectData;
      g_PlayerDamageInvulnerabilityTicks = 0;
      g_PlayerDamageFlashTicks = 0;
      *(byte *)((int)g_PlayerEntitySceneObjectData + 3) =
           *(byte *)((int)g_PlayerEntitySceneObjectData + 3) | 0x80;
      if ((*(byte *)(g_PlayerContactSurfaceThisFrame + 0x14) & 8) != 0) {
        g_ClaytonBattleCameraState = 2;
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 3;
        (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
        dataCursor = (undefined2 *)0;
        g_PlayerSequenceFlags = g_PlayerSequenceFlags & 0xdfff;
        return dataCursor;
      }
    }
  }
  return dataCursor;
}

