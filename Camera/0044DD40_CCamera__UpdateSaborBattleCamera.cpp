#include "tarzan_ghidra_types.hpp"

// Address: 0x0044DD40
// Label: CCamera::UpdateSaborBattleCamera
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CCamera::UpdateSaborBattleCamera(void)

{
  int value;
  int value2;
  byte flagByte;
  uint value6;
  int value3;
  int value4;
  int value5;
  undefined4 value7;
  
  g_OptionalHudMeterValue = g_SaborBattleHudMeterValue;
  g_OptionalHudMeterMax =
       (int)*(short *)(&g_SaborHealthByEncounterAndDifficulty +
                      (_g_CurrentSaborEncounterIndex * 3 + (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) * 2)
  ;
  value4 = *(int *)(g_PlayerEntity + 0x38);
  value2 = *(int *)(value4 + 0x14);
  value6 = *(int *)(*(int *)(g_SaborBattleEntity + 0x38) + 0x14) - value2 >> 1;
  if ((int)value6 < -0x578) {
    value6 = 0xfffffa88;
  }
  else if (0x578 < (int)value6) {
    value6 = 0x578;
  }
  value = value2 + value6;
  value5 = *(int *)(*(int *)(g_SaborBattleEntity + 0x38) + 0x18) + -0x164;
  value3 = ((int)(((value6 ^ (int)value6 >> 0x1f) - ((int)value6 >> 0x1f)) * 0x243dd) >> 0x10) + -0x70c;
  if (value3 < 0) {
    value3 = 0;
  }
  value3 = value3 + 0xa40;
  switch(g_SaborBattleCameraState) {
  case 0:
    g_SaborBattleCameraTransitionFrames = 0;
    g_SaborBattleCameraState = 1;
    return;
  case 1:
    ApproachSaborBattleCameraPose
              (value2,*(int *)(value4 + 0x18) + -0x164,*(undefined4 *)(value4 + 0x1c),0,0,0xa40,0xcc,0,
               0);
    return;
  case 2:
    ApproachSaborBattleCameraPose(value,value5,*(undefined4 *)(value4 + 0x1c),0,0,value3,0xcc,0,0);
    g_SaborBattleCameraTransitionFrames = g_SaborBattleCameraTransitionFrames + 1;
    if (0x3b < g_SaborBattleCameraTransitionFrames) {
      g_SaborBattleCameraState = 3;
      return;
    }
    break;
  case 3:
    g_CameraFocusZ = *(undefined4 *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c);
    value4 = (int)*(short *)((int)&g_SaborFightAnchor0SurfaceA + _g_CurrentSaborEncounterIndex * 2);
    g_SaborBattleCameraDistance = 0;
    g_CameraTrackSecondaryOffset = 0;
    g_CameraFocusX = value;
    g_CameraFocusY = value5;
    g_CameraEyeDistanceFromFocus = value3;
    if (*(int *)(g_PlayerEntitySceneObject + 0x10c) < value4) {
      g_SaborArenaLeftBoundaryBlockedFlag = 1;
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                (g_PlayerEntitySceneObject,value4 - *(int *)(g_PlayerEntitySceneObject + 0x10c));
    }
    if ((int)*(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) <
        *(int *)(g_PlayerEntitySceneObject + 0x10c)) {
      g_SaborArenaRightBoundaryBlockedFlag = 1;
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                (g_PlayerEntitySceneObject,
                 (int)*(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) -
                 *(int *)(g_PlayerEntitySceneObject + 0x10c));
      if ((((int)g_SaborEncounterCleanupFlags & 1 << ((byte)_g_CurrentSaborEncounterIndex & 0x1f))
           == 0) && (_g_CurrentSaborEncounterIndex != 2)) {
        QueuePlayerDamageEvent
                  (g_SaborBattleEntity,
                   (int)*(short *)(&g_SaborContactDamageByEncounterAndDifficulty +
                                  (_g_CurrentSaborEncounterIndex * 3 +
                                  (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) * 2));
        CPlayerHero::SetAdultTarzanActionState(0x3c);
        flagByte = NextRandomValue();
        if ((flagByte & 1) == 0) {
          value7 = 0x86;
        }
        else {
          value7 = 0x85;
        }
        PlayAudioById(value7,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      }
    }
    value4 = (int)*(short *)((int)&g_SaborFightAnchor0SurfaceA + _g_CurrentSaborEncounterIndex * 2);
    if (*(int *)(g_SaborEntitySceneObject + 0x10c) < value4) {
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                (g_SaborEntitySceneObject,value4 - *(int *)(g_SaborEntitySceneObject + 0x10c));
    }
    if ((int)*(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) <
        *(int *)(g_SaborEntitySceneObject + 0x10c)) {
      CEntities::MoveEntitySceneObjectXZAndSnapSurfaceFacingAngles
                (g_SaborEntitySceneObject,
                 (int)*(short *)(&g_SaborFightAnchor0SurfaceB + _g_CurrentSaborEncounterIndex * 2) -
                 *(int *)(g_SaborEntitySceneObject + 0x10c));
      return;
    }
    break;
  case 4:
    value4 = ApproachSaborBattleCameraPose
                      (value2,*(int *)(value4 + 0x18) + -0x164,*(undefined4 *)(value4 + 0x1c),0,0,0xa40
                       ,0xcc,0,0);
    if (value4 != 0) {
      g_SaborBattleCameraState = 5;
    }
  }
  return;
}

