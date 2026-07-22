#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D610
// Label: CPlayerHero::TryApplyAdultTarzanTreeSurfingEdgeDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryApplyAdultTarzanTreeSurfingEdgeDamage(int arg1)

{
  switch(arg1 + -1) {
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
  case 0:
    goto LAB_0046d66e;
  default:
    return 0;
  }
  if (8 < g_PlayerLateralSurfaceOffset) {
    return 1;
  }
LAB_0046d66e:
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0x12;
  (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
  return 1;
}

