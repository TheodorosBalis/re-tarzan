#include "tarzan_ghidra_types.hpp"

// Address: 0x004508A0
// Label: CPlayerHero::TryEnterAdultTarzanSaborBattleMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 CPlayerHero::TryEnterAdultTarzanSaborBattleMovement(void)

{
  if (((((byte)g_PlayerInputHeldMask & 0x80) == 0) || (g_SaborArenaLeftBoundaryBlockedFlag != 0)) &&
     ((((byte)g_PlayerInputHeldMask & 0x20) == 0 || (g_SaborArenaRightBoundaryBlockedFlag != 0)))) {
    return 0;
  }
  CPlayerHero::SetAdultTarzanActionState(0x35);
  return 1;
}

