#include "tarzan_ghidra_types.hpp"

// Address: 0x00479AB0
// Label: CPlayerHero::EnterTerkClimbableSurfacePullUp
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableSurfacePullUp(void)

{
  switch(g_PlayerCurrentAnimationId) {
  case 0x30:
  case 0x31:
    g_PlayerCurrentAnimationId = 0x32;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfacePullUpAnimationScriptA;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  default:
    g_PlayerCurrentAnimationId = 0x38;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfacePullUpAnimationScriptC;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  case 0x34:
  case 0x35:
    g_PlayerCurrentAnimationId = 0x36;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfacePullUpAnimationScriptB;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
}

