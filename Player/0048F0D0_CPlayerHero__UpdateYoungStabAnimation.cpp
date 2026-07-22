#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F0D0
// Label: CPlayerHero::UpdateYoungStabAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungStabAnimation(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f166. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f149. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f1d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f19b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f1b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = 1;
    CPlayerHero::ApplyDamageContactPushback();
  }
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f226. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f243. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
      return;
    }
  }
  else if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  return;
}

