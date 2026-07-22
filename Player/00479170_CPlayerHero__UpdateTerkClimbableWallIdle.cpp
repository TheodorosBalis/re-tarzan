#include "tarzan_ghidra_types.hpp"

// Address: 0x00479170
// Label: CPlayerHero::UpdateTerkClimbableWallIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkClimbableWallIdle(void)

{
  undefined2 value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
      if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x50)
      {
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x1d;
                    /* WARNING: Could not recover jumptable at 0x004791c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterClimbableWallTopOutHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x1a;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x004791e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallMoveUpHandlerPtr)();
      return;
    }
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) &&
       (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY <
        g_PlayerInteractionCollisionHeightRange)) {
      g_PlayerActionState = 0x1b;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0047921c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallMoveDownHandlerPtr)();
      return;
    }
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x1c;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479245. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallJumpOffHandlerPtr)();
      return;
    }
  }
  return;
}

