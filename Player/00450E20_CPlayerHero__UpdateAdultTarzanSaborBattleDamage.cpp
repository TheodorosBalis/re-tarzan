#include "tarzan_ghidra_types.hpp"

// Address: 0x00450E20
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanSaborBattleDamage(void)

{
  int value;
  
  if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x3d);
    return;
  }
  if (*(int *)(g_PlayerEntitySceneObject + 0x18) < g_SaborBattleGroundY) {
    if (*(int *)(g_PlayerMotionState + 0x20) < 0) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
    }
    *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x20) + 6;
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
    if (0 < *(int *)(g_PlayerMotionState + 0x20)) {
      if (g_SaborBattleGroundY <= *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
        *(int *)(g_PlayerEntitySceneObjectData + 0xc) = g_SaborBattleGroundY;
      }
    }
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x34);
  }
  return;
}

