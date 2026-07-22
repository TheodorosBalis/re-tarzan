#include "tarzan_ghidra_types.hpp"

// Address: 0x00438450
// Label: ResetMenuInputState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetMenuInputState(void)

{
  g_PlayerInputHeldMask = 0;
  g_SecondaryInputHeldMask = 0;
  g_PlayerInputPressedMask = 0;
  _g_SecondaryInputPressedMask = 0;
  return;
}

