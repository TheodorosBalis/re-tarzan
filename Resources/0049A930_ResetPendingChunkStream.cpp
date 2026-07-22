#include "tarzan_ghidra_types.hpp"

// Address: 0x0049A930
// Label: ResetPendingChunkStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetPendingChunkStream(void)

{
  if (g_PendingEgfObjectOrFileHandle != 0) {
    CloseVirtualGameFileHandle(g_PendingEgfObjectOrFileHandle);
  }
  g_PendingEgfBytesRemaining = 0;
  g_PendingEgfChunkBytesPerTick = 0;
  g_PendingEgfDestinationBuffer = 0;
  g_PendingEgfObjectOrFileHandle = 0;
  return;
}

