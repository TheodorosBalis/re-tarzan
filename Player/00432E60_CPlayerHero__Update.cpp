#include "tarzan_ghidra_types.hpp"

// Address: 0x00432E60
// Label: CPlayerHero::Update
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::Update(void)

{
  short shortValue;
  int value;
  
  if ((g_PlayerAnimationState != 0 && g_PlayerMotionState != 0) && g_PlayerEntitySceneObject != 0) {
    if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
      if (g_PlayerSequenceDelayTicks == 0) {
        *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8040;
      }
      else {
        g_PlayerSequenceDelayTicks = g_PlayerSequenceDelayTicks + -1;
      }
    }
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      ProcessPlayerDamageAndDeath();
      g_PlayerSurfaceTriggerPacket = g_PlayerSurfaceTriggerPacket & 0xf000ffff;
      g_PendingPlayerDamage = 0;
      if ((g_GameplayRuntimeFlags & 0x80000000) != 0) {
        if (((byte)g_PlayerInputPressedMask & 1) != 0) {
          RespawnAndReinitializeGameplayWorld();
        }
        if (((g_GameplayRuntimeFlags & 0x10) != 0) && ((g_SecondaryInputHeldMask & 0x400) != 0)) {
          _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x8000;
          g_PlayerSequenceDelayTicks = 0;
        }
        if (((g_GameplayRuntimeFlags & 0x20) != 0) && ((g_SecondaryInputHeldMask & 0x800) != 0)) {
          _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x4000;
          *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
        }
      }
    }
    else {
      g_PlayerInputHeldMask = g_PlayerInputHeldMask & 0xffff0000;
    }
    UpdateSelectedPowerFruitTypeFromInput();
    g_PlayerBlockDamageGuardActive = 0;
    if (g_PlayerAnimationEffectEntitySceneObject != 0) {
      *(undefined2 *)(g_PlayerAnimationEffectEntitySceneObject + 0xe) = 0;
    }
    switch(_g_PlayerHeroMode) {
    case 1:
    case 3:
      CPlayerHero::UpdateAdultTarzan();
      break;
    case 2:
      CPlayerHero::UpdateYoungTarzan();
      break;
    case 4:
      CPlayerHero::UpdateJane();
      break;
    case 5:
      CPlayerHero::UpdateTarzanSurfingWithJane();
      break;
    case 6:
      CPlayerHero::UpdateTerk();
      break;
    case 7:
      CPlayerHero::UpdateAdultTarzanOnElephant();
      break;
    case 8:
      CPlayerHero::UpdateYoungTarzanOnStork();
      break;
    case 9:
      CPlayerHero::UpdateStampedeYoungTarzan();
      break;
    case 10:
      CPlayerHero::UpdateJaneElephantKerchakChase();
      break;
    case 0xb:
    case 0xc:
      CPlayerHero::UpdateYoungTarzanOrTerkLeafSwimming();
    }
    g_PlayerDamageContactEntitySceneObject = 0;
    g_PlayerSpecialAttachmentEntry = FindPlayerSpecialAttachmentEntry();
    UpdatePlayerSpecialAttachmentPosition();
    shortValue = g_LastProcessedSurfaceTriggerPacket;
    if ((short)g_PlayerSurfaceTriggerPacket != g_LastProcessedSurfaceTriggerPacket) {
      if ((g_PlayerSurfaceTriggerPacket & 0xc000) != 0) {
        CPlayerHero::ApplySurfaceResourceTrigger(g_PlayerSurfaceTriggerPacket);
      }
      shortValue = (short)g_PlayerSurfaceTriggerPacket;
      if ((g_PlayerSurfaceTriggerPacket & 0x2000) != 0) {
        SelectBackgroundMusicTrackForLevel(g_PlayerSurfaceTriggerPacket & 0xff);
        shortValue = (short)g_PlayerSurfaceTriggerPacket;
      }
    }
    g_LastProcessedSurfaceTriggerPacket = shortValue;
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x80,&g_CameraOverrideTargetX);
      g_PlayerFacingCurrentCollisionSurface = 0;
      g_CameraOverrideTargetPtr = -(uint)(value != 0) & 0x51ce08;
    }
    if (g_PlayerAttackHitSfxPlayed == '\0') {
      value = GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x20,&DAT_0051ce18);
      g_PlayerAttackHitPositionPtr = -(uint)(value != 0) & 0x51ce18;
    }
    else {
      g_PlayerAttackHitPositionPtr = 0;
    }
    g_PlayerSurfaceTriggerPacket = g_PlayerSurfaceTriggerPacket & 0xf00ffff;
    g_PlayerPendingDamageSourceFlags = g_PendingPlayerDamageSourceEntity;
    g_PendingPlayerDamageSourceEntity = 0;
  }
  return;
}

