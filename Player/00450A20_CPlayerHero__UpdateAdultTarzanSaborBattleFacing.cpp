#include "tarzan_ghidra_types.hpp"

// Address: 0x00450A20
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleFacing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleFacing(void)

{
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    if (((byte)g_PlayerInputHeldMask & 0x80) != 0) {
      CPlayerHero::FlipAdultTarzanSaborBattleFacing();
      return;
    }
  }
  else if (((byte)g_PlayerInputHeldMask & 0x20) != 0) {
    CPlayerHero::FlipAdultTarzanSaborBattleFacing();
    return;
  }
  return;
}

