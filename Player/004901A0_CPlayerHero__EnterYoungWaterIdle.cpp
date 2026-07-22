#include "tarzan_ghidra_types.hpp"

// Address: 0x004901A0
// Label: CPlayerHero::EnterYoungWaterIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungWaterIdle(void)

{
  CPlayerHero::PlayAnimation(0x79);
  g_PlayerTiltControlEnabled = 0;
  return;
}

