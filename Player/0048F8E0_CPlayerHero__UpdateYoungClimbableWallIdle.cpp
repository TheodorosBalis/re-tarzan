#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F8E0
// Label: CPlayerHero::UpdateYoungClimbableWallIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungClimbableWallIdle(void)

{
  undefined2 value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x2e;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f91e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterClimbableSurfaceJumpOffAltHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      if (((byte)g_PlayerInputHeldMask & 0x40) != 0) {
        g_PlayerActionState = 0x2d;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f9a3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterClimbableWallMoveUpHandlerPtr)();
        return;
      }
    }
    else {
      if (0x37 < *(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY)
      {
        g_PlayerActionState = 0x2c;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f984. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterClimbableWallMoveDownHandlerPtr)();
        return;
      }
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
      value = g_PlayerActionState;
      if ((*(byte *)(g_PlayerLatchedInteractionCollisionSurface + 0x14) & 0x20) != 0) {
        g_PlayerActionState = 0x2b;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048f967. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterClimbableWallIdleHandlerPtr)();
        return;
      }
    }
  }
  return;
}

