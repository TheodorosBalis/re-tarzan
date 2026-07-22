#include "tarzan_ghidra_types.hpp"

// Address: 0x00491890
// Label: CPlayerHero::TryHandleYoungTreeSurfingDamageCue8To10
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryHandleYoungTreeSurfingDamageCue8To10(int arg1)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (arg1 == 8) {
    g_PlayerActionState = 0x16;
    g_PreviousPlayerActionState = value;
    (*(code *)g_YoungEnterTreeSurfingHazardDamageHandlerPtr)();
  }
  else if (arg1 == 9) {
    if (g_PlayerLateralSurfaceOffset < 9) {
      g_PlayerActionState = 0x16;
      g_PreviousPlayerActionState = value;
      (*(code *)g_YoungEnterTreeSurfingHazardDamageHandlerPtr)();
      return 1;
    }
  }
  else {
    if (arg1 != 10) {
      return 0;
    }
    if (-9 < g_PlayerLateralSurfaceOffset) {
      g_PlayerActionState = 0x16;
      g_PreviousPlayerActionState = value;
      (*(code *)g_YoungEnterTreeSurfingHazardDamageHandlerPtr)();
      return 1;
    }
  }
  return 1;
}

