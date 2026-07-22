#include "tarzan_ghidra_types.hpp"

// Address: 0x004695F0
// Label: CPlayerHero::EnterAdultTarzanTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanTurnAround(void)

{
  undefined4 value;
  
  if (g_PreviousPlayerActionState == 1) {
    value = 0xb;
  }
  else {
    value = 10;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value);
  *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  return;
}

