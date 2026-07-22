#include "tarzan_ghidra_types.hpp"

// Address: 0x004917D0
// Label: CPlayerHero::TryHandleYoungTreeSurfingHazardCue1To4
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleYoungTreeSurfingHazardCue1To4(int arg1)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  switch(arg1 + -1) {
  case 0:
    goto switchD_004917da_caseD_0;
  case 1:
    break;
  case 2:
    if (g_PlayerLateralSurfaceOffset < -8) {
      return 1;
    }
    break;
  case 3:
    if (7 < g_PlayerLateralSurfaceOffset) {
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
    }
    return 1;
  default:
    return 0;
  }
  if (g_PlayerLateralSurfaceOffset < 9) {
switchD_004917da_caseD_0:
    CPlayerHero::TriggerYoungTreeSurfingHazardDamage();
  }
  return 1;
}

