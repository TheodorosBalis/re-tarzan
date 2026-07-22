#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E860
// Label: CPlayerHero::UpdateYoungPound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungPound(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
LAB_0048e949:
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
LAB_0048e91e:
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
      g_PlayerActionState = 0x30;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
      goto LAB_0048eb17;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode != 4) {
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          return;
        }
        goto LAB_0048e91e;
      }
      goto LAB_0048e949;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode != 0) {
      if (g_PlayerCurrentCollisionMode < 3) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        value2 = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
        DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
        return;
      }
    }
  }
  value2 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
    DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
    return;
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputHeldMask & 0x80000) != 0)) {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterBlockHandlerPtr)();
    DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
    return;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag != '\0') {
    value = CPlayerHero::AdvanceAnimationScript();
    if ((value == 8) && ((g_PlayerInputHeldMask & 0x100000) == 0)) {
      DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
      CPlayerHero::PlayAnimation(0x1f);
    }
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = value2;
  (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
LAB_0048eb17:
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  return;
}

