#include "tarzan_ghidra_types.hpp"

// Address: 0x0045AED0
// Label: CPlayerHero::UpdateStorkImpactReactionCooldown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkImpactReactionCooldown(void)

{
  if ((g_StorkImpactReactionCooldownActive != 0) &&
     (g_StorkImpactReactionCooldownTicks = g_StorkImpactReactionCooldownTicks + 1,
     0x60 < g_StorkImpactReactionCooldownTicks)) {
    g_StorkImpactReactionCooldownActive = 0;
    g_StorkImpactReactionCooldownTicks = 0;
  }
  return;
}

