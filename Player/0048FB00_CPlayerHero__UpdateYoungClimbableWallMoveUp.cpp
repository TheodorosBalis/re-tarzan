#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FB00
// Label: CPlayerHero::UpdateYoungClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungClimbableWallMoveUp(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + 0x70;
    value2 = g_PlayerActionState;
    if (g_PlayerInteractionCollisionHeightRange <=
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
           g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x2b;
                    /* WARNING: Could not recover jumptable at 0x0048fb58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) == 0) {
      g_PlayerActionState = 0x2b;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048fb7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

