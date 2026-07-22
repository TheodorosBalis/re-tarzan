#include "tarzan_ghidra_types.hpp"

// Address: 0x00476F50
// Label: CPlayerHero::UpdateTerkTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkTurnAround(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (((g_PlayerCurrentAnimationId != 10) && ((_g_PlayerSequenceFlags & 0xf000) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476fa3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 6) {
    if (g_PlayerCurrentAnimationId == 10) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_TerkEnterBlockHandlerPtr)();
      g_PlayerCurrentAnimationId = 0x1b;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkActionState_Field02AC;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
    }
    else if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) {
      resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
      value2 = g_PlayerActionState;
      if ((resultFlag == '\0') &&
         (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 &&
          (g_PlayerCollisionFacingFlags == '\0')))) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
      }
    }
  }
  else if (value == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004770b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterFallingHandlerPtr)();
    return;
  }
  return;
}

