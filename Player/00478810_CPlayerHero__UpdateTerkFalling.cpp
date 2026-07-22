#include "tarzan_ghidra_types.hpp"

// Address: 0x00478810
// Label: CPlayerHero::UpdateTerkFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkFalling(void)

{
  short shortValue;
  char resultFlag;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 8)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  resultFlag = TryStartPlayerAttachmentInteraction();
  if (resultFlag != '\0') {
    return;
  }
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateRunInputAndMovement();
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  shortValue = g_PlayerActionState;
  if (resultFlag == '\0') {
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerActionState = 0xc;
  g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x004788c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_TerkEnterLandingRecoveryHandlerPtr)();
  return;
}

