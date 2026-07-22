#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F240
// Label: CPlayerHero::InitElephantRideCameraTrackState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::InitElephantRideCameraTrackState(void)

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
         *(int *)(g_CollisionSurfaceTable + 0x1c) + 0x1c + g_CollisionSurfaceTable;
    SnapCameraAnchorAttachmentToNearestPathSegment(value,*(int *)(g_PlayerEntity + 0x38) + 0x14);
    g_CameraFocusX = *(int *)(value + 0x14);
    g_CameraFocusY = *(int *)(value + 0x18);
    g_CameraFocusZ = *(int *)(value + 0x1c);
    g_ElephantRideCameraFocusSmoothedX = g_CameraFocusX;
    g_ElephantRideCameraFocusSmoothedY = g_CameraFocusY;
    g_ElephantRideCameraFocusSmoothedZ = g_CameraFocusZ;
  }
  g_AdultTarzanElephantCameraLeadTarget = 3000;
  g_AdultTarzanElephantCameraLeadSmoothed = 3000;
  g_AdultTarzanElephantCameraHeightOffset = 0;
  g_AdultTarzanElephantCameraYawLocked = 0;
  g_AdultTarzanElephantLevelExitDismountActive = 0;
  g_AdultTarzanElephantScriptedRiseActive = 0;
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x1c) + 0x20 + g_CollisionSurfaceTable);
    value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + 8 + g_CollisionSurfaceTable);
    value = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + g_CollisionSurfaceTable + 0x40 +
                    *(int *)(value + 0x18) * 0x1c) + *(int *)(value + 0x28);
    if (value3 < value) {
      value = value3;
    }
    value = (((value2 << 8) / value3) * value >> 8) - g_AdultTarzanElephantCameraLeadSmoothed;
    if (value2 < value) {
      value = value2;
    }
    if (value < 0) {
      value = 0;
    }
    InterpolateJungleSurfacePointByCoordRef(6,value,&localState3);
    g_CameraFocusX = localState3;
    g_CameraFocusY = localState2;
    g_CameraFocusZ = localState;
    g_ElephantRideCameraFocusSmoothedX = localState3;
    g_ElephantRideCameraFocusSmoothedY = localState2;
    g_ElephantRideCameraFocusSmoothedZ = localState;
    value = *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value2 = localState3 - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value4 = localState - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    value3 = SqrtToInt(value4 * value4 + value2 * value2);
    state = GetAngleFromXZVector12Bit(value2,value4);
    g_CameraYaw = -(state - 0x800U & 0xfff);
    stateFlags = GetAngleFromXZVector12Bit(localState2 - value,value3 >> 6);
    g_CameraPitch = -(stateFlags & 0xfff);
    _g_ElephantRideAndChaseState_Field003C = 0;
  }
  return;
}

