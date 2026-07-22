#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABE80
// Label: ScanInputAndUpdateMasks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ScanInputAndUpdateMasks(void)

{
  int value;
  uint mask;
  
  mask = 0;
  value = IsGamePaused();
  if (value == 0) {
    mask = PollConfiguredInputStateThunk(0);
    if (g_ActiveTransitionPayload != 0) {
      if (mask != 0) {
        *( undefined1 *)((int)&g_GameplayStateFlags + 0) = (byte)g_GameplayStateFlags | 0x10;
      }
      mask = AdvanceLoadedPayloadPlayback(g_ActiveTransitionPayload);
    }
    if ((mask & 0x80000000) != 0) {
      EnsureHudPanelsStayVisible();
    }
    mask = mask & 0x7fffffff;
  }
  g_InputCurrentMask = mask;
  g_InputEdgeMask = g_InputPreviousMask ^ mask;
  g_InputPreviousMask = mask;
  g_SecondaryInputEdgeMask = 0;
  g_SecondaryInputCurrentMask = 0;
  _g_SecondaryInputPreviousMask = 0;
  return;
}

