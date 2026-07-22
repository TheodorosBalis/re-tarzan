#include "tarzan_ghidra_types.hpp"

// Address: 0x00491750
// Label: CPlayerHero::TriggerYoungTreeSurfingHazardDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::TriggerYoungTreeSurfingHazardDamage(void)

{
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0x13;
  (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
  QueuePlayerDamageEvent(0,4);
  return;
}

