#include "tarzan_ghidra_types.hpp"

// Address: 0x00471A20
// Label: CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue1To4
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleTarzanSurfingWithJaneHazardCue1To4(int arg1)

{
  switch(arg1 + -1) {
  case 0:
    QueuePlayerDamageEvent(0,4);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
    (*(code *)g_JaneSurfingHazardCueTable)();
    return 1;
  case 1:
    break;
  case 2:
    if (g_PlayerLateralSurfaceOffset < -8) {
      return 1;
    }
    break;
  case 3:
    if (g_PlayerLateralSurfaceOffset < 8) {
      return 1;
    }
    goto LAB_00471aae;
  default:
    return 0;
  }
  if (g_PlayerLateralSurfaceOffset < 9) {
LAB_00471aae:
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 7;
    (*(code *)g_JaneSurfingHazardCueTable)();
    QueuePlayerDamageEvent(0,4);
  }
  return 1;
}

