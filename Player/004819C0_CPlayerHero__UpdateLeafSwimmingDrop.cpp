#include "tarzan_ghidra_types.hpp"

// Address: 0x004819C0
// Label: CPlayerHero::UpdateLeafSwimmingDrop
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateLeafSwimmingDrop(void)

{
  short *value2;
  int value;
  
  g_LeafSwimmingEarlyStageMotionTable = -(int)g_LeafSwimmingCameraOrbitAngle + 0x800;
  if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
    g_LeafSwimmingEarlyStageMotionTable = -(int)g_LeafSwimmingCameraOrbitAngle + 0x700;
  }
  if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
    g_LeafSwimmingEarlyStageMotionTable = g_LeafSwimmingEarlyStageMotionTable + 0x100;
  }
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value = GetWrappedSignedAngleDelta12Bit
                    ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                     g_LeafSwimmingEarlyStageMotionTable);
  *value2 = *value2 + (short)(value >> 4);
  if (*(short *)(g_PlayerEntitySceneObject + 0xa0) <= _g_LeafSwimmingCameraRouteNode) {
    *(short *)(g_PlayerEntitySceneObject + 0xa0) =
         *(short *)(g_PlayerEntitySceneObject + 0xa0) + 0x10;
  }
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + (_g_LeafSwimmingDropSplashTimer >> 8);
  _g_LeafSwimmingDropSplashTimer = _g_LeafSwimmingDropSplashTimer + 500;
  CPlayerHero::ApproachLeafSwimmingForwardSpeed();
  CPlayerHero::IntegrateLeafSwimmingMotionAndClearObstacleResponse();
  value = CPlayerHero::ClampLeafSwimmingToWaterSurfaceAndSpawnSplash();
  if (value != 0) {
    g_LeafSwimmingCameraDynamicPitchActive = 0;
    g_LeafSwimmingWaterfallDropActive = 1;
    DetachEntitySoundHandle(g_PlayerEntitySceneObject + 0x104);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 1;
    (*(code *)g_LeafSwimmingEnterPaddlingCallback)();
  }
  return;
}

