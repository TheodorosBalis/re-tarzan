#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D6A0
// Label: CPlayerHero::TryApplyAdultTarzanTreeSurfingCenterDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryApplyAdultTarzanTreeSurfingCenterDamage(int arg1)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (arg1 == 5) {
    if (g_PlayerLateralSurfaceOffset < 3) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
    }
  }
  else if (arg1 == 6) {
    if ((-3 < g_PlayerLateralSurfaceOffset) && (g_PlayerLateralSurfaceOffset < 3)) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
      return 1;
    }
  }
  else {
    if (arg1 != 7) {
      return 0;
    }
    if (-3 < g_PlayerLateralSurfaceOffset) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
      return 1;
    }
  }
  return 1;
}

