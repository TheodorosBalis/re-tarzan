#include "tarzan_ghidra_types.hpp"

// Address: 0x004929B0
// Label: CPlayerHero::UpdateYoungSwingAttachHold
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungSwingAttachHold(void)

{
  if (g_CurrentSwingEntity != 0) {
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  return;
}

