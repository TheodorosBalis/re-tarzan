#include "tarzan_ghidra_types.hpp"

// Address: 0x00471AE0
// Label: CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue5To7
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue5To7(int arg1)

{
  if (arg1 != 5) {
    if (arg1 != 6) {
      if (arg1 != 7) {
        return 0;
      }
      if (g_PlayerLateralSurfaceOffset < -2) {
        return 1;
      }
      goto LAB_00471b3f;
    }
    if (g_PlayerLateralSurfaceOffset < -2) {
      return 1;
    }
  }
  if (2 < g_PlayerLateralSurfaceOffset) {
    return 1;
  }
LAB_00471b3f:
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 7;
  (*(code *)g_JaneSurfingHazardCueTable)();
  QueuePlayerDamageEvent(0,4);
  return 1;
}

