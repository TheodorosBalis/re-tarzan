#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CD50
// Label: CPlayerHero::UpdateAdultTarzanClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanClimbableWallMoveUp(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0xb0;
    value2 = g_PlayerActionState;
    if (g_PlayerInteractionCollisionHeightRange <=
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x24;
                    /* WARNING: Could not recover jumptable at 0x0046cdab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableWallIdleHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) == 0) {
      g_PlayerActionState = 0x24;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046cdd1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

