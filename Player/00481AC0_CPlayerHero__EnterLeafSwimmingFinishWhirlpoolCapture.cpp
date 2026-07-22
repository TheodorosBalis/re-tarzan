#include "tarzan_ghidra_types.hpp"

// Address: 0x00481AC0
// Label: CPlayerHero::EnterLeafSwimmingFinishWhirlpoolCapture
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterLeafSwimmingFinishWhirlpoolCapture(void)

{
  g_LeafSwimmingCameraTargetDistance = g_LeafSwimmingFinishWhirlpoolCameraDistance;
  if (g_LeafSwimmingStageSet != 0) {
    g_PlayerCurrentAnimationId = 1;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_LeafSwimmingLateStageAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_LeafSwimmingEarlyStageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

