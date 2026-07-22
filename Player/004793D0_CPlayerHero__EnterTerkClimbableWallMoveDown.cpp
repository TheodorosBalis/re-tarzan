#include "tarzan_ghidra_types.hpp"

// Address: 0x004793D0
// Label: CPlayerHero::EnterTerkClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableWallMoveDown(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if (g_PlayerCurrentAnimationId != 0x24) {
    if (g_PlayerCurrentAnimationId != 0x25) {
      g_PlayerCurrentAnimationId = 0x27;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveDownAnimationScriptA;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 0x2b;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveDownAnimationScriptB;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x2a;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveDownAnimationScriptC;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

