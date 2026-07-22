#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AA80
// Label: ProcessPendingChunkStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessPendingChunkStream(void)

{
  int value;
  
  value = GetPendingEgfBytesRemaining();
  if (value != 0) {
    if ((((g_PendingEgfDestinationBuffer != 0) && (g_PendingEgfBytesRemaining != 0)) &&
        (g_PendingEgfChunkBytesPerTick != 0)) && (g_PendingEgfObjectOrFileHandle != 0)) {
      value = g_PendingEgfChunkBytesPerTick;
      if (g_PendingEgfBytesRemaining < g_PendingEgfChunkBytesPerTick) {
        value = g_PendingEgfBytesRemaining;
      }
      value = ReadVirtualGameFileIntoBuffer
                        (g_PendingEgfDestinationBuffer,1,value,g_PendingEgfObjectOrFileHandle);
      g_PendingEgfDestinationBuffer = g_PendingEgfDestinationBuffer + value;
      g_PendingEgfBytesRemaining = g_PendingEgfBytesRemaining - value;
      if (((0 < value) && (g_PendingEgfChunkBytesPerTick <= value)) &&
         (0 < g_PendingEgfBytesRemaining)) {
        return;
      }
    }
    ResetPendingChunkStream();
  }
  return;
}

