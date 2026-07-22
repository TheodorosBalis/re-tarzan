#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1A10
// Label: StopActiveStreamedWork
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopActiveStreamedWork(void)

{
  if (g_ActiveStreamedWorkHandle != 0) {
    g_StreamedWorkFileHandle = 0;
    StopAndSynchronizeStreamedWork();
    return;
  }
  return;
}

