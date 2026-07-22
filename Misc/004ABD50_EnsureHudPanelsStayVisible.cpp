#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABD50
// Label: EnsureHudPanelsStayVisible
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EnsureHudPanelsStayVisible(void)

{
  if (g_HudCollectedSketchSlideTicks < 0x78) {
    g_HudCollectedSketchSlideTicks = 0x78;
  }
  if (g_HudCollectedTARZANslotSlideTicks < 0x78) {
    g_HudCollectedTARZANslotSlideTicks = 0x78;
  }
  if (g_HudPowerFruitSelectorSlideTicks < 0x78) {
    g_HudPowerFruitSelectorSlideTicks = 0x78;
  }
  if (g_HudTokenCounterSlideTicks < 0x78) {
    g_HudTokenCounterSlideTicks = 0x78;
  }
  return;
}

