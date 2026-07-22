#include "tarzan_ghidra_types.hpp"

// Address: 0x0046B510
// Label: CPlayerHero::UpdateAdultTarzanPound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanPound(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface == '\0') {
LAB_0046b631:
    value2 = g_PlayerActionState;
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode == 1) {
        if (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 0x41;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          return;
        }
      }
      else if (g_PlayerCurrentCollisionMode == 2) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        value2 = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterMoveForwardHandlerPtr)();
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xd;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        if ((((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0) &&
           ((g_PlayerInputPressedMask & 0x200000) != 0)) {
          *(ushort *)(g_PlayerAnimationState + 0x1e) =
               *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff;
          value2 = g_PlayerActionState;
          if (g_PlayerCurrentCollisionMode == 1) {
            if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
              g_PlayerActionState = 0x46;
              g_PreviousPlayerActionState = value2;
              (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
              DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
              return;
            }
            g_PlayerActionState = 0x45;
            g_PreviousPlayerActionState = value2;
            (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
            DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
            return;
          }
          if (g_PlayerCurrentCollisionMode == 2) {
            if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
              g_PlayerActionState = 5;
              g_PreviousPlayerActionState = value2;
              (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
              DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
              return;
            }
            g_PlayerActionState = 6;
            g_PreviousPlayerActionState = value2;
            (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
            DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
            return;
          }
        }
        value2 = g_PlayerActionState;
        if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputHeldMask & 0x80000) != 0)) {
          g_PlayerActionState = 10;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterBlockHandlerPtr)();
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          return;
        }
      }
    }
    CPlayerHero::UpdateMovementAndCollision(1);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    value2 = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      return;
    }
    value = CPlayerHero::AdvanceAnimationScript();
    if ((value == 8) && ((g_PlayerInputHeldMask & 0x100000) == 0)) {
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      CPlayerHero::PlayAdultTarzanAnimation(0x20);
    }
    return;
  }
  if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x1000) == 0) {
    if (g_PlayerDamageInvulnerabilityTicks != 0) {
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero::ApplyDamageContactPushback();
      goto LAB_0046b631;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      CPlayerHero::ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
    }
    else {
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
      g_PreviousPlayerActionState = g_PlayerActionState;
    }
    g_PlayerActionState = 0xb;
    (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
  }
  else {
    if (g_PlayerCurrentCollisionMode == 5) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      return;
    }
    g_PlayerActionState = 0x2e;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      return;
    }
  }
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  return;
}

