#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA0D0
// Label: ResetRenderScratchPacketCount
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetRenderScratchPacketCount(void)

{
  *( undefined2 *)((int)&g_RenderScratchPacketCount + 0) = 0;
  return;
}

