#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D740
// Label: CPlayerHero::TryEnterAdultTarzanTreeSurfingCrash
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryEnterAdultTarzanTreeSurfingCrash(int arg1)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (arg1 == 8) {
    g_PlayerActionState = 0x15;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterTreeSurfingCrashHandlerPtr)();
  }
  else if (arg1 == 9) {
    if (g_PlayerLateralSurfaceOffset < 9) {
      g_PlayerActionState = 0x15;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterTreeSurfingCrashHandlerPtr)();
      return 1;
    }
  }
  else {
    if (arg1 != 10) {
      return 0;
    }
    if (-9 < g_PlayerLateralSurfaceOffset) {
      g_PlayerActionState = 0x15;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterTreeSurfingCrashHandlerPtr)();
      return 1;
    }
  }
  return 1;
}

