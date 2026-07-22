#include "tarzan_ghidra_types.hpp"

// Address: 0x00476B60
// Label: CPlayerHero::EnterTerkIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkIdle(void)

{
  short shortValue;
  
  g_PlayerCurrentAnimationId = 7;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkIdleEnterAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  shortValue = RandomModulo(10);
  g_PlayerIdleFidgetDelayTicks = shortValue + 5;
  g_PlayerTiltControlEnabled = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
  return;
}

