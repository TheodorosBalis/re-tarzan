#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D0B0
// Label: CPlayerHero::EnterYoungTarzanTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTarzanTurnAround(void)

{
  undefined4 value;
  
  if (g_PreviousPlayerActionState == 1) {
    value = 0xb;
  }
  else {
    value = 10;
  }
  CPlayerHero::PlayAnimation(value);
  *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  return;
}

