#include "tarzan_ghidra_types.hpp"

// Address: 0x00450A10
// Label: CPlayerHero::FlipAdultTarzanSaborBattleFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::FlipAdultTarzanSaborBattleFacing(void)

{
  *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  return;
}

