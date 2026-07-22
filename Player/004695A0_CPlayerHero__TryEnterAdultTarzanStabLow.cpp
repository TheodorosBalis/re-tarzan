#include "tarzan_ghidra_types.hpp"

// Address: 0x004695A0
// Label: CPlayerHero::TryEnterAdultTarzanStabLow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 CPlayerHero::TryEnterAdultTarzanStabLow(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0))
      && ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0)) &&
     ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
    g_PlayerActionState = 0x2b;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterStabLowHandlerPtr)();
    return 1;
  }
  return 0;
}

