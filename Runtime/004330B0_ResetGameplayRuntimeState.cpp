#include "tarzan_ghidra_types.hpp"

// Address: 0x004330B0
// Label: ResetGameplayRuntimeState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetGameplayRuntimeState(void)

{
  int value;
  int value2;
  
  g_ActiveCameraAnchorEntry = g_EntityPoolBase;
  g_PlayerEntity = g_EntityPoolBase;
  *( undefined2 *)((int)&g_GameplayStateFlags + 0) = 0;
  g_PlayerCollisionFacingFlags = 0;
  g_PlayerFacingCurrentCollisionSurface = 0;
  g_PlayerJumpArcActive = 0;
  _g_PlayerCollisionSnapRange = 0x40;
  g_CurrentSwingSegmentIndex = 0;
  g_CurrentSwingEntity = 0;
  g_PlayerSequenceFlags = 0;
  g_PlayerHealth = 0x100;
  g_PlayerDamageInvulnerabilityTicks = 0x1e;
  g_PlayerDamageFlashTicks = 0;
  g_PlayerSequenceDelayTicks = 0;
  g_PlayerBlockDamageGuardActive = 0;
  g_PendingAdultTarzanActionState = 0;
  g_PreviousPlayerActionState = 0;
  g_PlayerActionState = 0;
  g_CameraOverrideTargetPtr = 0;
  g_PlayerLateralSurfaceOffset = 0;
  g_PlayerAirMoveHeadingAngle = 0;
  g_PlayerAirMovePitchAngle = 0;
  g_PlayerGroundContactEntitySceneObject = 0;
  g_PlayerCollisionContactFlags = 0;
  g_LastProcessedSurfaceTriggerPacket = 0;
  g_PlayerLoopingSoundHandle = 0;
  _g_PlayerLoopingSoundHandleState = 0;
  _g_PlayerLoopingSoundHandleCookie = 0;
  g_PlayerAttackHitSfxPlayed = 1;
  g_SelectedPowerFruitType = 0;
  g_PowerFruitPickupFlashType = 0;
  g_PowerFruitPickupFlashTicks = 0;
  g_PlayerThrowLowArcSelected = 0;
  g_SelectedThrowablePowerFruitType = 0;
  g_PlayerGroundSnapOffset = 0;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = 0xffffffe2;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  g_PlayerCurrentCollisionMode =
       CPlayerHero::ApplyCheckpointPlacementToEntitySceneObject(g_PlayerEntitySceneObject);
  value2 = g_PlayerEntitySceneObjectData;
  value = g_PlayerEntitySceneObject;
  g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x48) =
       *(undefined4 *)(g_PlayerEntitySceneObjectData + 8);
  *(undefined4 *)(value + 0x4c) = *(undefined4 *)(value2 + 0xc);
  *(undefined4 *)(value + 0x50) = *(undefined4 *)(value2 + 0x10);
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x44) = 0;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x40) = 0;
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x3c) = 0;
  if (g_ForcedPlayerHeroMode != 0) {
    _g_PlayerHeroMode = g_ForcedPlayerHeroMode;
  }
  CPlayerHero::ShowGroundShadow();
  switch(_g_PlayerHeroMode) {
  case 1:
  case 3:
    CPlayerHero::EnterAdultTarzanMode();
    return;
  case 2:
    CPlayerHero::EnterYoungTarzanMode();
    return;
  case 4:
    CPlayerHero::EnterJaneMode();
    return;
  case 5:
    CPlayerHero::EnterTarzanSurfingWithJaneMode();
    return;
  case 6:
    CPlayerHero::EnterTerkMode();
    return;
  case 7:
    CPlayerHero::EnterAdultTarzanOnElephantMode();
    return;
  case 8:
    CPlayerHero::EnterYoungTarzanOnStorkMode();
    return;
  case 9:
    CPlayerHero::EnterStampedeYoungTarzanMode();
    return;
  case 10:
    CPlayerHero::EnterJaneElephantKerchakChaseMode();
    return;
  case 0xb:
  case 0xc:
    CPlayerHero::EnterYoungTarzanOrTerkLeafSwimmingMode();
    return;
  default:
    return;
  }
}

