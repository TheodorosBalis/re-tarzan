#include "tarzan_ghidra_types.hpp"

// Address: 0x004398D0
// Label: UpdateModelHeapStats
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateModelHeapStats(void)

{
  RebuildModelHeapStats(&g_ModelLoadHeapState);
  return;
}

