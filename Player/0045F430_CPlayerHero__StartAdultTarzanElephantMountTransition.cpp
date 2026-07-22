#include "tarzan_ghidra_types.hpp"

// Address: 0x0045F430
// Label: CPlayerHero::StartAdultTarzanElephantMountTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::StartAdultTarzanElephantMountTransition(void)

{
  if ((g_PlayerActionState != 1) && (g_PlayerActionState != 4)) {
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 4;
    (*(code *)g_AdultTarzanElephantEnterMountTransitionHandlerPtr)();
    _g_PlayerHeroMode = 7;
  }
  return;
}

