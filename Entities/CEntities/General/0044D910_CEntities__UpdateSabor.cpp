#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D910
// Label: CEntities::UpdateSabor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateSabor(undefined4 entry)

{
  if ((((g_GameplayRuntimeFlags & 0x80000000) != 0) && ((g_GameplayRuntimeFlags & 0x8000) != 0)) &&
     (0 < g_SaborBattleHudMeterValue)) {
    g_SaborBattleHudMeterValue = 0;
    SetSaborBattlePhase(8);
    SetSaborAnimationStateAndAdvance(g_SaborBattleEntity,0x12);
    g_SaborHitProcessedFlag = 1;
  }
  if ((g_PlayerInputHeldMask & 0x200000) == 0) {
    g_SaborPlayerHitReactionFlag = 0;
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_SaborPlayerHitReactionFlag = 1;
  }
  if ((g_PlayerInputHeldMask & 0x800000) == 0) {
    g_SaborPlayerReactionAFlag = 0;
  }
  if ((g_PlayerInputPressedMask & 0x800000) != 0) {
    g_SaborPlayerReactionAFlag = 1;
  }
  if ((g_PlayerInputHeldMask & 0x400000) == 0) {
    g_SaborPlayerReactionBFlag = 0;
  }
  if ((g_PlayerInputPressedMask & 0x400000) != 0) {
    g_SaborPlayerReactionBFlag = 1;
  }
  if (((_g_PlayerHeroMode != 1) && (g_SaborBattleHudMeterValue < 1)) &&
     ((g_PlayerActionState != 0x36 && (g_PlayerActionState != 0x37)))) {
    CPlayerHero::SetAdultTarzanActionState(0x3f);
  }
  (*(code *)(&g_SaborBattlePhaseUpdateTable)[g_SaborBattlePhase])(entry);
  UpdateSaborDistanceScaledRuntimeValue(entry);
  return;
}

