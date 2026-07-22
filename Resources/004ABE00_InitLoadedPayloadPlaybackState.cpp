#include "tarzan_ghidra_types.hpp"

// Address: 0x004ABE00
// Label: InitLoadedPayloadPlaybackState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitLoadedPayloadPlaybackState(undefined4 *arg1)

{
  g_ActiveTransitionPayload = arg1;
  arg1[3] = 0;
  arg1[4] = 0;
  g_PrngStateA = *arg1;
  g_PrngStateB = arg1[1];
  TotalGameLoopTicks = arg1[2];
  return;
}

