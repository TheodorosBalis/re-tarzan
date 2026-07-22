#include "tarzan_ghidra_types.hpp"

// Address: 0x00479310
// Label: CPlayerHero::UpdateTerkClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableWallMoveUp(void)

{
  undefined2 value2;
  int value;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + -0xa0;
    value2 = g_PlayerActionState;
    if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x50) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
        g_PlayerActionState = 0x19;
                    /* WARNING: Could not recover jumptable at 0x00479385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterClimbableWallIdleHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x1d;
                    /* WARNING: Could not recover jumptable at 0x004793a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallTopOutHandlerPtr)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      g_PlayerActionState = 0x19;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004793c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallIdleHandlerPtr)();
      return;
    }
  }
  return;
}

