#include "tarzan_ghidra_types.hpp"

// Address: 0x00469500
// Label: CPlayerHero::TryEnterAdultTarzanThrowHigh
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::TryEnterAdultTarzanThrowHigh(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0))
      && (g_HudPowerFruitSelectorScene != 0)) && ((g_PlayerInputHeldMask & 0x400000) != 0)) {
    g_PlayerActionState = 0x28;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterThrowHighHandlerPtr)();
    return 1;
  }
  return 0;
}

