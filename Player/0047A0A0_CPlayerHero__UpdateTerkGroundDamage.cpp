#include "tarzan_ghidra_types.hpp"

// Address: 0x0047A0A0
// Label: CPlayerHero::UpdateTerkGroundDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkGroundDamage(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  CPlayerHero::ApplyDamageContactPushback();
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 0) {
    return;
  }
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 2) {
      resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
      g_PreviousPlayerActionState = g_PlayerActionState;
      if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 1;
                    /* WARNING: Could not recover jumptable at 0x0047a156. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
        return;
      }
    }
    g_PreviousPlayerActionState = g_PlayerActionState;
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
        ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) &&
       (g_PlayerCurrentCollisionMode == 2)) {
      g_PlayerActionState = 3;
                    /* WARNING: Could not recover jumptable at 0x0047a19c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterTurnAroundHandlerPtr)();
      return;
    }
  }
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0;
                    /* WARNING: Could not recover jumptable at 0x0047a1b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_TerkActionStateHandlerTable)();
  return;
}

