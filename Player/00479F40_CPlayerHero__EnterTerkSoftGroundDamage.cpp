#include "tarzan_ghidra_types.hpp"

// Address: 0x00479F40
// Label: CPlayerHero::EnterTerkSoftGroundDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkSoftGroundDamage(void)

{
  g_PlayerCurrentAnimationId = 0x1d;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkSoftGroundDamageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}

