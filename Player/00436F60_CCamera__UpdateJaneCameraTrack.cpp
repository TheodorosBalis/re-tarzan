#include "tarzan_ghidra_types.hpp"

// Address: 0x00436F60
// Label: CCamera::UpdateJaneCameraTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::UpdateJaneCameraTrack(void)

{
  int value;
  int value2;
  int value3;
  uint value5;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 100) + 0x68 + g_CollisionSurfaceTable);
  value2 = *(int *)(g_CollisionSurfaceTable + 100) + 100 + g_CollisionSurfaceTable;
  value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x94) + 0x98 + g_CollisionSurfaceTable);
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if ((value != 0) && (g_JaneCameraTrackPaused == 0)) {
    if (*(int *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c) == 1) {
      _g_JaneRouteEventEnabled = 1;
      _g_JaneRouteEventValue = *(undefined4 *)(value2 + 0x34 + *(int *)(value + 0x18) * 0x1c);
    }
    if (*(int *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c) == 2) {
      _g_JaneRouteEventEnabled = 0;
    }
    if (*(int *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c) == 4) {
      if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
        CEntities::SpawnEntityByTypeAtPosition
                  (*(int *)(g_PlayerEntitySceneObject + 0x14) + 1000,
                   *(int *)(g_PlayerEntitySceneObject + 0x18) + -600,
                   *(int *)(g_PlayerEntitySceneObject + 0x1c) + 500,0xd6,0x11);
        _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x2000;
      }
      if ((_g_PlayerHeroMode == 4) && (g_PlayerActionState != 1)) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 1;
        (*(code *)g_JaneEnterIdleHandlerPtr)();
      }
    }
    if (*(int *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c) == 8) {
      RequestWorldSceneAuxResourceLoadNoOp
                (g_CurrentWorldSceneContext,g_CurrentWorldSceneAuxResourceContext,2);
    }
    if (*(int *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c) == 0x10) {
      ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,1);
      LoadEncodedResourceId(6);
    }
    g_JaneCameraLeadSmoothed =
         g_JaneCameraLeadSmoothed - (g_JaneCameraLeadSmoothed - g_JaneCameraLeadTarget >> 4);
    value2 = *(int *)(value2 + 0x3c + *(int *)(value + 0x18) * 0x1c) + *(int *)(value + 0x28);
    if (value3 < value2) {
      value2 = value3;
    }
    value2 = (value2 * 0x10e >> 8) + 0x9c4 + g_JaneCameraForwardLookaheadZOffset;
    if (value4 < value2) {
      value2 = value4;
    }
    InterpolateJungleSurfacePointByCoordRef(0x24,value2,&localState3);
    g_CameraFocusX = g_JaneCameraFocusSmoothedX - (g_JaneCameraFocusSmoothedX - localState3 >> 4);
    g_CameraFocusY = g_JaneCameraFocusSmoothedY - (g_JaneCameraFocusSmoothedY - localState2 >> 4);
    g_CameraFocusZ = g_JaneCameraFocusSmoothedZ - (g_JaneCameraFocusSmoothedZ - localState >> 4);
    g_JaneCameraForwardLookaheadZOffset =
         (g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObject + 0x1c)) + 0x9c4;
    value4 = g_CameraFocusX - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value2 = g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value = g_CameraFocusY - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    g_JaneCameraFocusSmoothedX = g_CameraFocusX;
    g_JaneCameraFocusSmoothedY = g_CameraFocusY;
    g_JaneCameraFocusSmoothedZ = g_CameraFocusZ;
    value3 = SqrtToInt(value2 * value2 + value4 * value4);
    value2 = GetAngleFromXZVector12Bit(value4,value2);
    value5 = GetAngleFromXZVector12Bit(value,value3 >> 6);
    value2 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,-(value2 - 0x800U & 0xfff));
    g_CameraYaw = g_CameraYaw + (short)(value2 >> 3);
    value2 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,-(value5 & 0xfff));
    g_CameraPitch = g_CameraPitch + (short)(value2 >> 3);
    g_CameraEyeDistanceFromFocus = 0;
    g_CameraTrackSecondaryOffset = 0;
  }
  return;
}

