#include "tarzan_ghidra_types.hpp"

// Address: 0x00450C80
// Label: CPlayerHero::TryEnterAdultTarzanSaborBattleBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined1 CPlayerHero::TryEnterAdultTarzanSaborBattleBlock(void)

{
  if ((g_PlayerInputHeldMask & 0x80000) != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x39);
    return 1;
  }
  return 0;
}

