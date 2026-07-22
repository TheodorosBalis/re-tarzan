#include "tarzan_ghidra_types.hpp"

// Address: 0x00478FF0
// Label: CPlayerHero::EnterTerkClimbableWallIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkClimbableWallIdle(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
      if (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x50)
      {
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_PlayerInteractionCollisionBaseY;
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x1d;
                    /* WARNING: Could not recover jumptable at 0x00479034. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterClimbableWallTopOutHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x1a;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479051. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallMoveUpHandlerPtr)();
      return;
    }
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) &&
       (*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY <
        g_PlayerInteractionCollisionHeightRange)) {
      g_PlayerActionState = 0x1b;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0047908d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallMoveDownHandlerPtr)();
      return;
    }
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x1c;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x004790b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterClimbableWallJumpOffHandlerPtr)();
      return;
    }
  }
  if (g_PlayerAnimationSurfaceSide == '\0') {
    g_PlayerCurrentAnimationId = 0x30;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkActionState_Field0300;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  else {
    g_PlayerCurrentAnimationId = 0x34;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkActionState_Field0310;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  g_PlayerTiltControlEnabled = 0;
  return;
}

