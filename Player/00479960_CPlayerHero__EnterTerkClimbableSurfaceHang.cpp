#include "tarzan_ghidra_types.hpp"

// Address: 0x00479960
// Label: CPlayerHero::EnterTerkClimbableSurfaceHang
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkClimbableSurfaceHang(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0x10) != 0)) {
    g_PlayerActionState = 0x16;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00479988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterClimbableSurfacePullUpHandlerPtr)();
    return;
  }
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x34;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkActionState_Field0310;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x30;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkActionState_Field0300;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

