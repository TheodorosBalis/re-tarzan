#include "tarzan_ghidra_types.hpp"

// Address: 0x00469550
// Label: CPlayerHero::TryEnterAdultTarzanThrowLow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::TryEnterAdultTarzanThrowLow(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0))
      && (g_HudPowerFruitSelectorScene != 0)) && ((g_PlayerInputHeldMask & 0x800000) != 0)) {
    g_PlayerActionState = 0x29;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterThrowLowHandlerPtr)();
    return 1;
  }
  return 0;
}

