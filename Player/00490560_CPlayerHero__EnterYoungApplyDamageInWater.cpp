#include "tarzan_ghidra_types.hpp"

// Address: 0x00490560
// Label: CPlayerHero::EnterYoungApplyDamageInWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungApplyDamageInWater(void)

{
  CPlayerHero::PlayAnimation(0x7c);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  return;
}

