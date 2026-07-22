#include "tarzan_ghidra_types.hpp"

// Address: 0x00476E70
// Label: CPlayerHero::EnterTerkTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkTurnAround(void)

{
  undefined *dataCursor;
  
  switch(g_PreviousPlayerActionState) {
  case 1:
    g_PlayerCurrentAnimationId = 0xb;
    dataCursor = _g_TerkTurnAroundTiming;
    break;
  default:
    g_PlayerCurrentAnimationId = 9;
    dataCursor = PTR_DAT_0050c264;
    break;
  case 0xd:
  case 0x11:
  case 0x12:
    g_PlayerCurrentAnimationId = 10;
    *(undefined4 *)(g_PlayerAnimationState + 0xc) = _g_TerkTurnAroundAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
    return;
  }
  *(undefined **)(g_PlayerAnimationState + 0xc) = dataCursor;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  return;
}

