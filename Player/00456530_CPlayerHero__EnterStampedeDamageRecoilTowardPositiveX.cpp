#include "tarzan_ghidra_types.hpp"

// Address: 0x00456530
// Label: CPlayerHero::EnterStampedeDamageRecoilTowardPositiveX
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterStampedeDamageRecoilTowardPositiveX(void)

{
  g_PlayerCurrentAnimationId = 5;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeDamageRecoilAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x700;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x200;
  g_StampedeDamageRecoilTicksRemaining = 0x40;
  _g_StampedeLateralRecoilAcceleration = 0x294;
  _g_StampedeLateralRecoilDeceleration = 0x294;
  g_StampedeLateralRecoilSpeed = 0;
  g_StampedeLateralRecoilTargetSpeed = 0x1000;
  *(undefined4 *)(g_PlayerMotionState + 0x34) = 0x294;
  *(undefined4 *)(g_PlayerMotionState + 0x38) = 0x294;
  *(undefined4 *)(g_PlayerMotionState + 0x30) = 0x2000;
  *(undefined4 *)(g_PlayerMotionState + 0x3c) = 0xffffe000;
  return;
}

