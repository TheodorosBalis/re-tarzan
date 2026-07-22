#include "tarzan_ghidra_types.hpp"

// Address: 0x00432AC0
// Label: CPlayerHero::InitializeForLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::InitializeForLevel(void)

{
  int value;
  int value2;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  g_PlayerCurrentAnimationId = 0;
  g_PlayerEntitySceneObjectData = 0;
  g_PlayerEntitySceneObject = 0;
  g_PlayerMotionState = 0;
  g_PlayerAnimationState = 0;
  g_PlayerAnimationEffectEntitySceneObject = 0;
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
  g_ActiveCameraAnchorEntry = g_EntityPoolBase;
  g_PlayerEntity = g_EntityPoolBase;
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
  _g_PlayerDefaultBonusPickupValue = 100;
  dataCursor = &g_EntityDefaultTemplate;
  dataCursor2 = g_EntityPoolBase;
  for (value2 = 0x15; value2 != 0; value2 = value2 + -1) {
    *dataCursor2 = *dataCursor;
    dataCursor = dataCursor + 1;
    dataCursor2 = dataCursor2 + 1;
  }
  ResetPowerFruitSelectionState();
  *g_PlayerEntity = 1;
  g_PlayerEntity[10] = 0;
  *(undefined2 *)((int)g_PlayerEntity + 0x46) = 2;
  g_CameraFollowMode = 0;
  g_PlayerEntitySceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,1);
  if (g_PlayerEntitySceneObject != 0) {
    g_PlayerEntitySceneObjectData = g_PlayerEntitySceneObject + 0xc;
    *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = 1;
    g_PlayerMotionState = CEntities::CreateRuntimeMotionStateAttachment(g_PlayerEntity);
    g_PlayerAnimationState = CEntities::CreateEntitySceneObjectScriptAttachment(g_PlayerEntity);
    g_PlayerCurrentCollisionMode =
         CPlayerHero::ApplyCheckpointPlacementToEntitySceneObject(g_PlayerEntitySceneObject);
    value2 = g_PlayerEntitySceneObject;
    g_PlayerMoveHeadingAngle = *(undefined2 *)(g_PlayerEntitySceneObject + 0xa2);
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x48) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(undefined4 *)(value2 + 0x4c) = *(undefined4 *)(value2 + 0x18);
    *(undefined4 *)(value2 + 0x50) = *(undefined4 *)(value2 + 0x1c);
    g_PlayerGroundShadowProbeEntitySceneObject = CreateEntityEntitySceneObject((uint *)g_PlayerEntity,2);
    if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
      *(int *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10) =
           g_WorldEntitySceneObjectArrayBase + 0x3a8;
      *(undefined2 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xc) = 0x2010;
      value = g_PlayerGroundShadowProbeEntitySceneObject;
      value2 = g_PlayerEntitySceneObject;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x14) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value2 + 0x18);
      *(undefined4 *)(value + 0x1c) = *(undefined4 *)(value2 + 0x1c);
      *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
           *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) | 0x8441;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x30) = 0x400;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x6c) = 0xffffffec;
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x6c) = 0xffffffe2;
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa6) = 1;
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x108) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x108);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x110) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x110);
      *(undefined4 *)(g_PlayerGroundShadowProbeEntitySceneObject + 0x10c) =
           *(undefined4 *)(g_PlayerEntitySceneObject + 0x10c);
    }
    *(uint *)(g_PlayerEntitySceneObject + 0x13c) = *(uint *)(g_PlayerEntitySceneObject + 0x13c) | 1;
    *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
    g_PlayerPickupTriggerRadius = 0xf0;
    g_PlayerMaxHealth = 0x100;
    switch(_g_PlayerHeroMode) {
    case 1:
    case 3:
      CPlayerHero::EnterAdultTarzanMode();
      CPlayerHero::CreateAnimationEffectEntitySceneObject();
      return;
    case 2:
      CPlayerHero::EnterYoungTarzanMode();
      CPlayerHero::CreateAnimationEffectEntitySceneObject();
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
      break;
    case 0xb:
    case 0xc:
      CPlayerHero::EnterYoungTarzanOrTerkLeafSwimmingMode();
      return;
    }
  }
  return;
}

