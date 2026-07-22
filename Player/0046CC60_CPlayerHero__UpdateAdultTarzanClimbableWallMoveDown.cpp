#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CC60
// Label: CPlayerHero::UpdateAdultTarzanClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanClimbableWallMoveDown(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0xb0;
    value2 = g_PlayerActionState;
    if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x58) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x1f;
                    /* WARNING: Could not recover jumptable at 0x0046ccb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableEdgeGrabHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      g_PlayerActionState = 0x24;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046ccd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

