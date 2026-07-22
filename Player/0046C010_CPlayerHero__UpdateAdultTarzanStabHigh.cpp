#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C010
// Label: CPlayerHero::UpdateAdultTarzanStabHigh
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanStabHigh(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c046. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x2e;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 2) {
        CPlayerHero::ApplyDamageContactPushback();
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0xb;
                    /* WARNING: Could not recover jumptable at 0x0046c0f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c0d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xb;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c0bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = 1;
    CPlayerHero::ApplyDamageContactPushback();
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) {
    if ((g_PlayerInputPressedMask & 0x200000) == 0) goto LAB_0046c1fb;
    *(ushort *)(g_PlayerAnimationState + 0x1e) = *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff
    ;
    value2 = g_PlayerActionState;
    if (g_PlayerCurrentCollisionMode == 1) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 0x45;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c1e3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x46;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c1c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c199. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c17c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
      return;
    }
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
LAB_0046c1fb:
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046c225. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 4) {
    if ((g_PlayerInputHeldMask & 0x1000000) == 0) {
      CPlayerHero::PlayAdultTarzanAnimation(0x84);
    }
  }
  else if ((value == 0x12) && ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
    CPlayerHero::PlayAdultTarzanAnimation(0x86);
    g_PlayerActionState = 0x2b;
    return;
  }
  return;
}

