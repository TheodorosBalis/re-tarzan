#include "tarzan_ghidra_types.hpp"

// Address: 0x00479700
// Label: CPlayerHero::UpdateTerkClimbableFall
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableFall(void)

{
  undefined2 value;
  char resultFlag;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  value = g_PlayerActionState;
  if (resultFlag != '\0') {
    g_PlayerActionState = 0xc;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterLandingRecoveryHandlerPtr)();
    return;
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

