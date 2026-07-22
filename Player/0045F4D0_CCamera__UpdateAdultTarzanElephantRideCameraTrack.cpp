#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F4D0
// Label: CCamera::UpdateAdultTarzanElephantRideCameraTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::UpdateAdultTarzanElephantRideCameraTrack(void)

{
  int value;
  int value2;
  int value3;
  uint value5;
  int value4;
  int localState3;
  int localState2;
  int localState;
  
  value4 = *(int *)(*(int *)(g_CollisionSurfaceTable + 0x1c) + 0x20 + g_CollisionSurfaceTable);
  value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4) + 8 + g_CollisionSurfaceTable);
  value2 = *(int *)(g_CollisionSurfaceTable + 4) + 4 + g_CollisionSurfaceTable;
  AdvanceRuntimePathAttachmentFromCachedDirection(g_PlayerEntity);
  value = CEntities::FindEntityAttachmentByFlags(g_PlayerEntity,0x40000000);
  if (value != 0) {
    g_AdultTarzanElephantCameraYawLocked = 0;
    value5 = *(uint *)(value2 + 0x44 + *(int *)(value + 0x18) * 0x1c);
    if (value5 < 0x41) {
      if (value5 == 0x40) {
        g_AdultTarzanElephantRouteEvent40Active = 1;
      }
      else {
        switch(value5) {
        case 1:
          if ((g_AdultTarzanElephantMountTransitionBlocked == 0) && (g_PlayerActionState == 0x49)) {
            CPlayerHero::StartAdultTarzanElephantMountTransition();
            PlayAudioById(0x45,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
          }
          break;
        case 4:
          g_AdultTarzanElephantCameraLeadTarget = 1000;
          break;
        case 8:
          g_AdultTarzanElephantCameraLeadTarget = 1000;
          CPlayerHero::StartAdultTarzanElephantLevelExitDismount();
          break;
        case 0x10:
          g_AdultTarzanElephantRouteEvent10Active = 1;
          g_AdultTarzanElephantRouteEvent10Value =
               *(undefined4 *)(value2 + 0x34 + *(int *)(value + 0x18) * 0x1c);
          break;
        case 0x20:
          g_AdultTarzanElephantRouteEvent10Active = 0;
        }
      }
    }
    else if (value5 < 0x201) {
      if (value5 == 0x200) {
        g_AdultTarzanElephantRouteEvent100Active = 0;
      }
      else if (value5 == 0x80) {
        g_AdultTarzanElephantRouteEvent40Active = 0;
      }
      else if (value5 == 0x100) {
        g_AdultTarzanElephantRouteEvent100Active = 1;
        g_AdultTarzanElephantRouteEvent100Height =
             *(undefined4 *)(value2 + 0x34 + *(int *)(value + 0x18) * 0x1c);
      }
    }
    else if (value5 == 0x800) {
      RequestWorldSceneAuxResourceLoadNoOp
                (g_CurrentWorldSceneContext,g_CurrentWorldSceneAuxResourceContext,3);
    }
    else if (value5 == 0x1000) {
      ReleaseWorldSceneAuxResourceNoOp(g_CurrentWorldSceneContext,1);
    }
    if (g_AdultTarzanElephantScriptedRiseActive == 0) {
      g_AdultTarzanElephantCameraLeadSmoothed =
           g_AdultTarzanElephantCameraLeadSmoothed -
           (g_AdultTarzanElephantCameraLeadSmoothed - g_AdultTarzanElephantCameraLeadTarget >> 3);
      value2 = *(int *)(value2 + 0x3c + *(int *)(value + 0x18) * 0x1c) + *(int *)(value + 0x28);
      if (value3 < value2) {
        value2 = value3;
      }
      value2 = ((value2 << 8) >> 8) - g_AdultTarzanElephantCameraLeadSmoothed;
      if (value4 < value2) {
        value2 = value4;
      }
      if (value2 < 0) {
        value2 = 0;
      }
      InterpolateJungleSurfacePointByCoordRef(6,value2,&localState3);
      localState2 = localState2 + (*(int *)(g_PlayerEntitySceneObject + 0x18) - *(int *)(value + 0x24));
      g_CameraFocusX =
           g_ElephantRideCameraFocusSmoothedX - (g_ElephantRideCameraFocusSmoothedX - localState3 >> 3);
      g_CameraFocusY =
           g_ElephantRideCameraFocusSmoothedY - (g_ElephantRideCameraFocusSmoothedY - localState2 >> 3);
      g_CameraFocusZ =
           g_ElephantRideCameraFocusSmoothedZ - (g_ElephantRideCameraFocusSmoothedZ - localState >> 3);
      value2 = g_CameraFocusX - *(int *)(g_PlayerEntitySceneObjectData + 8);
      if (_g_PlayerHeroMode == 7) {
        value4 = g_AdultTarzanElephantCameraHeightOffset + -0x108;
      }
      else {
        value4 = (g_AdultTarzanElephantCameraHeightOffset -
                *(int *)(g_PlayerEntitySceneObjectData + 0xc)) + 0x140;
      }
      value4 = value4 + g_CameraFocusY;
      value3 = g_CameraFocusZ - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
      g_ElephantRideCameraFocusSmoothedX = g_CameraFocusX;
      g_ElephantRideCameraFocusSmoothedY = g_CameraFocusY;
      g_ElephantRideCameraFocusSmoothedZ = g_CameraFocusZ;
      value = SqrtToInt(value3 * value3 + value2 * value2);
      value2 = GetAngleFromXZVector12Bit(value2,value3);
      value5 = GetAngleFromXZVector12Bit(value4,value >> 6);
      value4 = GetWrappedSignedAngleDelta12Bit((int)g_CameraPitch,-(value5 & 0xfff));
      g_CameraPitch = g_CameraPitch + (short)(value4 >> 2);
      if (g_AdultTarzanElephantCameraYawLocked == 0) {
        value2 = GetWrappedSignedAngleDelta12Bit((int)g_CameraYaw,-(value2 - 0x800U & 0xfff));
        g_CameraYaw = g_CameraYaw + (short)(value2 >> 1);
      }
      g_CameraEyeDistanceFromFocus = 0;
      g_CameraTrackSecondaryOffset = 0;
    }
  }
  return;
}

