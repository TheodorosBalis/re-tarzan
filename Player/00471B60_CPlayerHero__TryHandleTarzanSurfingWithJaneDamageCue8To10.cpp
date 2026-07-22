#include "tarzan_ghidra_types.hpp"

// Address: 0x00471B60
// Label: CPlayerHero::TryHandleTarzanSurfingWithJaneDamageCue8To10
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleTarzanSurfingWithJaneDamageCue8To10(int arg1)

{
  if (arg1 == 8) {
    QueuePlayerDamageEvent(0,6);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 8;
    (*(code *)g_JaneSurfingEnterCollisionReactionHandlerPtr)();
  }
  else if (arg1 == 9) {
    if (g_PlayerLateralSurfaceOffset < 9) goto LAB_00471b8d;
  }
  else {
    if (arg1 != 10) {
      return 0;
    }
    if (-9 < g_PlayerLateralSurfaceOffset) {
LAB_00471b8d:
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)g_JaneSurfingEnterCollisionReactionHandlerPtr)();
      QueuePlayerDamageEvent(0,6);
      return 1;
    }
  }
  return 1;
}

