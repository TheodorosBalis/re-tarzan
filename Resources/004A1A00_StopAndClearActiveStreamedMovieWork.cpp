#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1A00
// Label: StopAndClearActiveStreamedMovieWork
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopAndClearActiveStreamedMovieWork(void)

{
  ShutdownStreamingVideoPlayback();
  g_ActiveStreamedWorkHandle = 0;
  return;
}

