#include "tarzan_ghidra_types.hpp"

// Address: 0x00456690
// Label: CPlayerHero::EnterUnusedStampedeForcedAirborneMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterUnusedStampedeForcedAirborneMotion(void)

{
  g_PlayerCurrentAnimationId = 3;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeFallingAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x700;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x200;
  _g_StampedeLateralRecoilAcceleration = 0;
  _g_StampedeLateralRecoilDeceleration = 0;
  g_StampedeLateralRecoilSpeed = 0;
  g_StampedeLateralRecoilTargetSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x34) = 0x294;
  *(undefined4 *)(g_PlayerMotionState + 0x38) = 0x294;
  *(undefined4 *)(g_PlayerMotionState + 0x30) = 0x4000;
  *(undefined4 *)(g_PlayerMotionState + 0x3c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 1;
  return;
}

