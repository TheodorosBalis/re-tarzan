#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F9E0
// Label: CPlayerHero::UpdateYoungClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungClimbableWallMoveDown(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0x70;
    value2 = g_PlayerActionState;
    if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x38) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      if ((*(byte *)(g_PlayerLatchedInteractionCollisionSurface + 0x14) & 0x20) != 0) {
        g_PlayerActionState = 0x2b;
                    /* WARNING: Could not recover jumptable at 0x0048fa45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x20;
                    /* WARNING: Could not recover jumptable at 0x0048fa5f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterClimbableEdgeGrabHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      g_PlayerActionState = 0x2b;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048fa85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

