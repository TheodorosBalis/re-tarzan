#include "tarzan_ghidra_types.hpp"

// Address: 0x00479250
// Label: CPlayerHero::EnterTerkClimbableWallMoveUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableWallMoveUp(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if (g_PlayerCurrentAnimationId != 0x24) {
    if (g_PlayerCurrentAnimationId != 0x25) {
      g_PlayerCurrentAnimationId = 0x26;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveUpAnimationScriptA;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 0x28;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveUpAnimationScriptB;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x29;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallMoveUpAnimationScriptC;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

