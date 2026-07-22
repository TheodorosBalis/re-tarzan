#include "tarzan_ghidra_types.hpp"

// Address: 0x004493F0
// Label: CEntities::CanStartPickupCollection
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CEntities::CanStartPickupCollection(void)

{
  uint value;
  
  value = _g_PlayerSequenceFlags;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (value = g_PlayerPickupInteractionFlags, g_PlayerPickupInteractionFlags == 0)) {
    return 1;
  }
  return value & 0xffffff00;
}

