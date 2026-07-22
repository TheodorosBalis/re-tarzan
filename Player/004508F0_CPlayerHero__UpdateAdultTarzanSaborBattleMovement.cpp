#include "tarzan_ghidra_types.hpp"

// Address: 0x004508F0
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleMovement(void)

{
  char resultFlag;
  ushort value;
  
  resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleHitReaction();
  if (((resultFlag != '\0') ||
      (resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleBlock(), resultFlag != '\0')) ||
     (resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleScriptedReaction(), resultFlag != '\0')) {
    return;
  }
  if ((((g_PlayerInputHeldMask & 0x80) == 0) || (g_SaborArenaLeftBoundaryBlockedFlag != 0)) &&
     (((g_PlayerInputHeldMask & 0x20) == 0 || (g_SaborArenaRightBoundaryBlockedFlag != 0)))) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    if ((g_PlayerInputHeldMask & 0x20) != 0) {
      g_SaborArenaLeftBoundaryBlockedFlag = 0;
    }
    if ((g_PlayerInputHeldMask & 0x80) != 0) {
      g_SaborArenaRightBoundaryBlockedFlag = 0;
    }
    if (*(int *)(g_PlayerMotionState + 0x10) == 0) {
      value = *g_PlayerEntitySceneObjectData;
      if (value < 0x82) {
        return;
      }
      if (0x99 < value) {
        return;
      }
      if (value == 0x82) {
        CPlayerHero::SetAdultTarzanActionState(0x34);
        return;
      }
      if (value < 0x8e) {
        value = value - 4;
      }
      else {
        value = value + 4;
      }
      *g_PlayerEntitySceneObjectData = value;
      if ((0x81 < *g_PlayerEntitySceneObjectData) && (*g_PlayerEntitySceneObjectData < 0x9a)) {
        return;
      }
      *g_PlayerEntitySceneObjectData = 0x82;
      return;
    }
  }
  else {
    if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_SaborArenaLeftBoundaryBlockedFlag = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x20;
    }
    else {
      g_SaborArenaRightBoundaryBlockedFlag = 0;
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xffffffe0;
    }
    CPlayerHero::MoveAdultTarzanInSaborBattle(*(undefined4 *)(g_PlayerMotionState + 0x10));
    CPlayerHero::AdvanceAnimationScript();
  }
  CPlayerHero::UpdateAdultTarzanSaborBattleFacing();
  return;
}

