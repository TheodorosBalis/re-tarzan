#include "tarzan_ghidra_types.hpp"

// Address: 0x004770C0
// Label: CPlayerHero::EnterTerkMoveForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkMoveForward(void)

{
  undefined *dataCursor;
  
  if ((g_PreviousPlayerActionState < 2) ||
     ((3 < g_PreviousPlayerActionState && (g_PreviousPlayerActionState != 0xe)))) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    g_PlayerCurrentAnimationId = 1;
    dataCursor = g_TerkMoveForwardAnimationScript;
  }
  else {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    g_PlayerCurrentAnimationId = 2;
    dataCursor = g_TerkMoveForwardTurnAnimationScript;
  }
  *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

