#include "tarzan_ghidra_types.hpp"

// Address: 0x00446270
// Label: CWorld::UpdateHud
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CWorld::UpdateHud(void)

{
  UpdateHudHealthBar();
  UpdateOptionalHudMeterFill();
  UpdateHudPowerFruitSelector();
  UpdateHudLivesCounterAndHeroAvatar();
  UpdateHudCollectedSketchPanel();
  UpdateHudCollectedTARZANLettersPanel();
  UpdateHudTokenCounterAndExtraLifeAward();
  UpdateHudExtraLifeMeter();
  return;
}

