#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9430
// Label: PopNextSortedRenderPacket
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 PopNextSortedRenderPacket(void)

{
  if (g_RenderPacketCount < 1) {
    return 0;
  }
  g_RenderPacketCount = g_RenderPacketCount + -1;
  return *(undefined4 *)(&g_SortedRenderPacketPointerTable + g_RenderPacketCount * 4);
}

