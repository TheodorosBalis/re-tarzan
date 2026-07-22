#include "tarzan_ghidra_types.hpp"

// Address: 0x00429630
// Label: ResetModelLoadQueueState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetModelLoadQueueState(void)

{
  g_ModelLoadQueueCooldownTicks = 0x20;
  g_ModelLoadQueueHeadIndex = 0;
  g_ModelLoadQueuePendingCount = 0;
  g_ModelLoadQueueInFlightBlock = 0;
  g_ModelLoadQueueStreamHandle = 0;
  return;
}

