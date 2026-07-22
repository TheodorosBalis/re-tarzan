#include "tarzan_ghidra_types.hpp"

// Address: 0x00465200
// Label: TarzanToTheRescue::ClearTrackedKnifeEnemyAndRelease
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::ClearTrackedKnifeEnemyAndRelease(void)

{
  g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = 0;
  CEntities::ProcessEntityDeathAndRelease();
  return;
}

