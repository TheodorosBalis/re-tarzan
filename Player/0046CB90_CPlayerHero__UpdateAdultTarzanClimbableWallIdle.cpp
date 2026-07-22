#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CB90
// Label: CPlayerHero::UpdateAdultTarzanClimbableWallIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanClimbableWallIdle(void)

{
  undefined2 value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x27;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046cbce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableSurfaceJumpOffAltHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
      g_PlayerActionState = 0x25;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046cbf4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableWallMoveDownHandlerPtr)();
      return;
    }
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) &&
       (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY <
        g_PlayerInteractionCollisionHeightRange + -0xb0)) {
      g_PlayerActionState = 0x26;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046cc36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableWallMoveUpHandlerPtr)();
      return;
    }
  }
  return;
}

