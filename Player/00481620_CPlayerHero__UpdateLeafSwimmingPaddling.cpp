#include "tarzan_ghidra_types.hpp"

// Address: 0x00481620
// Label: CPlayerHero::UpdateLeafSwimmingPaddling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateLeafSwimmingPaddling(void)

{
  short *value2;
  int value;
  
  g_LeafSwimmingEarlyStageMotionTable = 0x800 - g_LeafSwimmingCameraOrbitAngle;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_LeafSwimmingWhirlpoolPullStrength;
  if (g_LeafSwimmingCurrentRouteNode == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      g_LeafSwimmingEarlyStageMotionTable = g_LeafSwimmingEarlyStageMotionTable + -0x200;
    }
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      g_LeafSwimmingEarlyStageMotionTable = g_LeafSwimmingEarlyStageMotionTable + 0x200;
    }
  }
  else {
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      g_LeafSwimmingEarlyStageMotionTable = g_LeafSwimmingEarlyStageMotionTable + 0x200;
    }
    if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
      g_LeafSwimmingEarlyStageMotionTable = g_LeafSwimmingEarlyStageMotionTable + -0x200;
    }
  }
  if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_LeafSwimmingWhirlpoolOuterRadius;
    _g_LeafSwimmingBoostInputSeen = 1;
  }
  g_LeafSwimmingCurrentRouteNode = 0;
  if ((((byte)g_PlayerInputHeldMask & 0x40) == 0) || (0x1f < g_LeafSwimmingSurfaceSpeed)) {
    g_LeafSwimmingSurfaceDriftX = g_LeafSwimmingSurfaceDriftX + 1;
    if (g_LeafSwimmingCameraTargetDistance < g_LeafSwimmingLateStageMotionTable) {
      g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingCameraTargetDistance + 0x18;
    }
    if (0x20 < g_LeafSwimmingSurfaceDriftX) {
      g_LeafSwimmingSurfaceSpeed = 0;
      g_LeafSwimmingSurfaceDriftX = 0x20;
    }
  }
  else {
    g_LeafSwimmingCurrentRouteNode = 1;
    *(int *)(g_PlayerMotionState + 0x1c) = -g_LeafSwimmingWhirlpoolInnerRadius;
    g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingCameraTargetDistance + -0x18;
    g_LeafSwimmingSurfaceSpeed = g_LeafSwimmingSurfaceSpeed + 1;
    g_LeafSwimmingSurfaceDriftX = 0;
  }
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa2);
  value = GetWrappedSignedAngleDelta12Bit
                    ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),
                     g_LeafSwimmingEarlyStageMotionTable);
  *value2 = *value2 + (short)(value >> 3);
  value2 = (short *)(g_PlayerEntitySceneObject + 0xa0);
  value = GetWrappedSignedAngleDelta12Bit((int)*(short *)(g_PlayerEntitySceneObject + 0xa0),0);
  *value2 = *value2 + (short)(value >> 2);
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x20;
  CPlayerHero::ClampLeafSwimmingToWaterSurfaceAndSpawnSplash();
  CPlayerHero::ApproachLeafSwimmingForwardSpeed();
  CPlayerHero::IntegrateLeafSwimmingMotionAndClearObstacleResponse();
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::UpdateLeafSwimmingPostDropVisualRecovery();
  if (g_LeafSwimmingBonusTimerActive != 0) {
    return;
  }
  CPlayerHero::SpawnLeafSwimmingPaddleSplashEffects();
  return;
}

