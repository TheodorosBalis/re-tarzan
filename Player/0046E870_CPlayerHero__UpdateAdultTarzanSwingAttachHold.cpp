#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E870
// Label: CPlayerHero::UpdateAdultTarzanSwingAttachHold
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSwingAttachHold(void)

{
  if (g_CurrentSwingEntity != 0) {
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  return;
}

