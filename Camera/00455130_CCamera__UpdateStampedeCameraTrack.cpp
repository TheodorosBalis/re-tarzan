#include "tarzan_ghidra_types.hpp"

// Address: 0x00455130
// Label: CCamera::UpdateStampedeCameraTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::UpdateStampedeCameraTrack(void)

{
  ushort *dataCursor;
  short shortValue;
  int value;
  int value2;
  int value3;
  uint value6;
  int value4;
  int value5;
  int localState3;
  int localState2;
  int localState;
  
  shortValue = g_PlayerActionState;
  value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x10) + 0x14 + g_CollisionSurfaceTable);
  dataCursor = (ushort *)(*(int *)(g_CollisionSurfaceTable + 0x10) + 0x10 + g_CollisionSurfaceTable);
  value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + 8 + g_CollisionSurfaceTable);
  if ((_g_PlayerSequenceFlags & 0x4000) != 0) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_StampedeYoungTarzanActionStateTable)();
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    if (g_StampedeCameraTrackPaused == 0) {
      g_StampedeCameraLeadSmoothed =
           g_StampedeCameraLeadSmoothed -
           (g_StampedeCameraLeadSmoothed - g_StampedeCameraLeadTarget >> 4);
      value4 = *(int *)(value + 0x18);
      value5 = *(int *)(dataCursor + value4 * 0xe + 0x1e) + *(int *)(value + 0x28);
      if (value2 < value5) {
        value5 = value2;
      }
      if (value4 + 8 < (int)(uint)*dataCursor) {
        if (*(int *)(dataCursor + value4 * 0xe + 0x92) == 2) {
          RequestWorldSceneAuxResourceLoadNoOp
                    (g_CurrentWorldSceneContext,g_CurrentWorldSceneAuxResourceContext,2);
        }
        if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x92) == 8) {
          RequestWorldSceneAuxResourceLoadNoOp
                    (g_CurrentWorldSceneContext,g_CurrentWorldSceneAuxResourceContext,3);
          _g_StampedeCameraCurrentTrackNode = 1;
        }
      }
      if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 4) {
        ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,1);
      }
      if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 0x10) {
        ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,2);
      }
      if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 0x20) {
        g_StampedeElephantRideState = 1;
        g_StampedeForceRunTowardExit = 1;
      }
      if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 0x40) {
        g_StampedeCameraTrackPaused = 1;
      }
      if (*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 0x80) {
        g_StampedeElephantRideState = 2;
      }
      g_StampedeLeftRailScriptedPullActive =
           (uint)(*(int *)(dataCursor + *(int *)(value + 0x18) * 0xe + 0x22) == 1);
      if ((g_NatureTerrainHazardContactFlag != 0) && (g_PlayerActionState != 4)) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 4;
        (*(code *)g_StampedeEnterTerrainHazardStumbleHandlerPtr)();
      }
      value2 = (value5 * ((value3 << 8) / value2) >> 8) + 0xdac + g_StampedeCameraLookaheadCorrection;
      if (value3 < value2) {
        value2 = value3;
      }
      InterpolateJungleSurfacePointByCoordRef(0,value2,&localState3);
      g_CameraFocusX = g_StampedeCameraTargetX - (g_StampedeCameraTargetX - localState3 >> 4);
      g_CameraFocusY = g_StampedeCameraTargetY - (g_StampedeCameraTargetY - localState2 >> 4);
      g_CameraFocusZ = g_StampedeCameraTargetZ - (g_StampedeCameraTargetZ - localState >> 4);
      g_StampedeCameraLookaheadCorrection =
           (g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObject + 0x1c)) + 0xdac;
      g_StampedeCameraTargetX = g_CameraFocusX;
      g_StampedeCameraTargetY = g_CameraFocusY;
      g_StampedeCameraTargetZ = g_CameraFocusZ;
    }
    value4 = g_StampedeCameraTargetX - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value = g_StampedeCameraTargetY - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value2 = g_StampedeCameraTargetZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value3 = SqrtToInt(value2 * value2 + value4 * value4);
    value2 = GetAngleFromXZVector12Bit(value4,value2);
    value6 = GetAngleFromXZVector12Bit(value,value3 >> 6);
    value2 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,-(value2 - 0x800U & 0xfff));
    g_CameraYaw = g_CameraYaw + (short)(value2 >> 3);
    value2 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,-(value6 & 0xfff));
    g_CameraEyeDistanceFromFocus = 0;
    g_CameraPitch = g_CameraPitch + (short)(value2 >> 3);
  }
  return;
}

