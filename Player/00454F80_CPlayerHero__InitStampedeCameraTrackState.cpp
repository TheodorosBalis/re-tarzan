#include "tarzan_ghidra_types.hpp"

// Address: 0x00454F80
// Label: CPlayerHero::InitStampedeCameraTrackState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::InitStampedeCameraTrackState(void)

{
  int value;
  short state;
  int value2;
  int value3;
  int localState3;
  undefined4 localState2;
  int localState;
  
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000017);
  if (value2 == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x34,0x10000017);
  }
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000017);
  if (value2 != 0) {
    *(int *)(value2 + 0xc) = *(int *)(g_CollisionSurfaceTable + 4) + 4 + g_CollisionSurfaceTable;
    SnapCameraAnchorAttachmentToNearestPathSegment(value2,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    g_CameraFocusX = *(int *)(value2 + 0x14);
    g_CameraFocusY = *(undefined4 *)(value2 + 0x18);
    g_CameraFocusZ = *(int *)(value2 + 0x1c);
  }
  g_StampedeCameraTrackPaused = 0;
  g_StampedeForceRunTowardExit = 0;
  value2 = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value2 != 0) {
    value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + 8 + g_CollisionSurfaceTable);
    value = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x10) + 0x14 + g_CollisionSurfaceTable);
    g_StampedeCameraLeadTarget = 3000;
    g_StampedeCameraLeadSmoothed = 3000;
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x10) + g_CollisionSurfaceTable + 0x4c +
                    *(int *)(value2 + 0x18) * 0x1c) + *(int *)(value2 + 0x28);
    if (value < value2) {
      value2 = value;
    }
    value2 = (((value3 << 8) / value) * value2 >> 8) + 3000;
    if (value3 < value2) {
      value2 = value3;
    }
    InterpolateJungleSurfacePointByCoordRef(0,value2,&localState3);
    g_CameraFocusY = localState2;
    g_StampedeCameraTargetY = localState2;
    g_CameraFocusX = localState3;
    g_CameraFocusZ = localState;
    g_StampedeCameraTargetX = localState3;
    g_StampedeCameraTargetZ = localState;
    value3 = localState - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value2 = localState3 - *(int *)(g_PlayerEntitySceneObjectData + 8);
    SqrtToInt(value3 * value3 + value2 * value2);
    state = GetAngleFromXZVector12Bit(value2,value3);
    g_CameraPitch = 0;
    g_CameraYaw = -(state - 0x800U & 0xfff);
    g_StampedeCameraLookaheadCorrection = 0;
  }
  return;
}

