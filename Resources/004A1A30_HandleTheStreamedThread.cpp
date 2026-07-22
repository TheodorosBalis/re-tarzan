#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1A30
// Label: HandleTheStreamedThread
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int HandleTheStreamedThread(void)

{
  if (g_ActiveStreamedPlaybackHandle == 0) {
    return 0;
  }
  g_StreamedFrameReadCursor = 0;
  g_StreamedWorkActiveBuffer = 0;
  UpdateStreamingVideoPlaybackFrame(&g_StreamedFrameReadCursor,&g_StreamedWorkActiveBuffer);
  return 0;
}

