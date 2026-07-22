#include "tarzan_ghidra_types.hpp"

// Address: 0x00450CD0
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleBlock(void)

{
  int value;
  
  if ((*g_PlayerEntitySceneObjectData < 0x7d) && ((g_PlayerInputHeldMask & 0x80000) == 0)) {
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0;
    *(ushort *)(g_PlayerAnimationState + 0x16) = 0x82 - *g_PlayerEntitySceneObjectData;
    if ((*(short *)(g_PlayerAnimationState + 0x16) < 1) ||
       (0xb < *(short *)(g_PlayerAnimationState + 0x16))) {
      CPlayerHero::SetAdultTarzanActionState(0x34);
      return;
    }
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x34);
  }
  return;
}

