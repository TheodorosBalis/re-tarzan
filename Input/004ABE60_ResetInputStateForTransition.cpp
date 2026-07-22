#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABE60
// Label: ResetInputStateForTransition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ResetInputStateForTransition(void)

{
  CaptureKInputsInBuffer();
  g_InputEdgeMask = 0;
  g_InputCurrentMask = 0;
  g_InputPreviousMask = 0;
  g_SecondaryInputEdgeMask = 0;
  g_SecondaryInputCurrentMask = 0;
  _g_SecondaryInputPreviousMask = 0;
  return;
}

