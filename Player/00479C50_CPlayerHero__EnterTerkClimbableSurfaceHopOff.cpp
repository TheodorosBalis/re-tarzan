#include "tarzan_ghidra_types.hpp"

// Address: 0x00479C50
// Label: CPlayerHero::EnterTerkClimbableSurfaceHopOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableSurfaceHopOff(void)

{
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x37;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfaceHopOffAnimationScriptB;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x33;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfaceHopOffAnimationScriptA;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

