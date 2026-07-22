#include "tarzan_ghidra_types.hpp"

// Address: 0x00479770
// Label: CPlayerHero::EnterTerkClimbableWallJumpOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableWallJumpOff(void)

{
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x2e;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallJumpOffAnimationScriptB;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x2d;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallJumpOffAnimationScriptA;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

