#include "tarzan_ghidra_types.hpp"

// Address: 0x004383E0
// Label: GetInputs
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetInputs(void)

{
  uint value;
  uint value2;
  
  ScanInputAndUpdateMasks();
  value = (&g_InputEdgeMask)[g_PlayerInputSourceIndex * 3];
  value2 = (&g_InputCurrentMask)[g_PlayerInputSourceIndex * 3];
  g_PlayerInputPressedMask = value2 & value;
  g_PlayerInputHeldMask = (value == 0 | value2) & g_PlayerInputHeldMask | value2 & value;
  g_SecondaryInputHeldMask = (&g_InputCurrentMask)[g_SecondaryInputSourceIndex * 3];
  _g_SecondaryInputPressedMask =
       (&g_InputEdgeMask)[g_SecondaryInputSourceIndex * 3] &
       (&g_InputCurrentMask)[g_SecondaryInputSourceIndex * 3];
  return;
}

