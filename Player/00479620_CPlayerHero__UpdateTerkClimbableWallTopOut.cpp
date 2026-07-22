#include "tarzan_ghidra_types.hpp"

// Address: 0x00479620
// Label: CPlayerHero::UpdateTerkClimbableWallTopOut
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableWallTopOut(void)

{
  int value;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::TrySnapDownToGround();
  if (g_PlayerJumpArcActive != '\0') {
    value = CPlayerHero::TryClampJumpArcToSurfaceCeiling(0x14e);
    if (value != 0) {
      *(int *)(g_PlayerEntitySceneObjectData + 0xc) = value;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 10;
      (*(code *)g_TerkEnterFallingHandlerPtr)();
      g_PlayerJumpArcActive = '\0';
    }
    CPlayerHero::UpdateJumpArcVerticalMotion(0);
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
  }
  return;
}

