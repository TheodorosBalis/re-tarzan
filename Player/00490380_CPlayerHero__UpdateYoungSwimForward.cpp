#include "tarzan_ghidra_types.hpp"

// Address: 0x00490380
// Label: CPlayerHero::UpdateYoungSwimForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungSwimForward(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490416. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          return;
        }
        g_PlayerDamageFlashTicks = 0x3c;
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004903f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490485. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490468. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xc;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0049044b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::SpawnYoungWaterAttachmentEffects();
  if (g_PlayerAirMovePitchAngle != 0) {
    value = GetWrappedSignedAngleDelta12Bit(g_PlayerAirMovePitchAngle,0);
    if ((value >> 3 ^ value >> 0x1f) - (value >> 0x1f) < 2) {
      g_PlayerAirMovePitchAngle = 0;
    }
    else {
      g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle + (short)(value >> 3);
    }
    *(ushort *)(g_PlayerEntitySceneObject + 0xa4) =
         *(ushort *)(g_PlayerEntitySceneObject + 0xa4) & 0xfff;
  }
  value2 = g_PlayerActionState;
  g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle & 0xfff;
  if (((byte)g_PlayerInputHeldMask & 0xf0) == 0) {
    g_PlayerActionState = 0x27;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterWaterTurnHandlerPtr)();
  }
  else {
    CPlayerHero::SteerYoungAirMoveHeadingTowardInput();
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  value2 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags == '\0') {
    return;
  }
  g_PlayerActionState = 0x27;
  g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0049054f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_YoungEnterWaterTurnHandlerPtr)();
  return;
}

