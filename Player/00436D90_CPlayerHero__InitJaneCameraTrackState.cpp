#include "tarzan_ghidra_types.hpp"

// Address: 0x00436D90
// Label: CPlayerHero::InitJaneCameraTrackState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::InitJaneCameraTrackState(void)

{
  short state;
  ushort stateFlags;
  int value;
  int value2;
  int value3;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000017);
  if (value == 0) {
    CEntities::CreateEntityAttachment(g_PlayerEntity,0x34,0x10000017);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x10000017);
  if (value != 0) {
    *(int *)(value + 0xc) =
         *(int *)(g_CollisionSurfaceTable + 0x94) + 0x94 + g_CollisionSurfaceTable;
    SnapCameraAnchorAttachmentToNearestPathSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    g_CameraFocusX = *(int *)(value + 0x14);
    g_CameraFocusY = *(int *)(value + 0x18);
    g_CameraFocusZ = *(int *)(value + 0x1c);
  }
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x94) + 0x98 + g_CollisionSurfaceTable);
    value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 100) + 0x68 + g_CollisionSurfaceTable);
    g_JaneCameraLeadTarget = 0x9c4;
    g_JaneCameraLeadSmoothed = 0x9c4;
    value = *(int *)(*(int *)(g_CollisionSurfaceTable + 100) + g_CollisionSurfaceTable + 0xa0 +
                    *(int *)(value + 0x18) * 0x1c) + *(int *)(value + 0x28);
    if (value3 < value) {
      value = value3;
    }
    value = (((value2 << 8) / value3) * value >> 8) + 0x9c4;
    if (value2 < value) {
      value = value2;
    }
    InterpolateJungleSurfacePointByCoordRef(0x24,value,&localState3);
    g_CameraFocusX = localState3;
    g_CameraFocusY = localState2;
    g_CameraFocusZ = localState;
    g_JaneCameraFocusSmoothedX = localState3;
    g_JaneCameraFocusSmoothedY = localState2;
    g_JaneCameraFocusSmoothedZ = localState;
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value2 = localState3 - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value4 = localState - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value3 = SqrtToInt(value4 * value4 + value2 * value2);
    state = GetAngleFromXZVector12Bit(value2,value4);
    g_CameraYaw = -(state - 0x800U & 0xfff);
    stateFlags = GetAngleFromXZVector12Bit(localState2 - value,value3 >> 6);
    g_CameraPitch = -(stateFlags & 0xfff);
    g_JaneCameraForwardLookaheadZOffset = 0;
    g_JaneCameraTrackPaused = 0;
  }
  return;
}

