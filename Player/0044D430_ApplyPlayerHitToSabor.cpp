#include "tarzan_ghidra_types.hpp"

// Address: 0x0044D430
// Label: ApplyPlayerHitToSabor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ApplyPlayerHitToSabor(undefined4 arg1)

{
  CEntities::FindEntityAttachmentByFlags(arg1,0x10000001);
  g_SaborBattleHudMeterValue = g_SaborBattleHudMeterValue + -1;
  SetSaborBattlePhase(8);
  SetSaborAnimationStateAndAdvance(g_SaborBattleEntity,0x12);
  g_SaborHitProcessedFlag = 1;
  return;
}

