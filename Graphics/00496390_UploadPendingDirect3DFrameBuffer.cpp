#include "tarzan_ghidra_types.hpp"

// Address: 0x00496390
// Label: UploadPendingDirect3DFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UploadPendingDirect3DFrameBuffer(void)

{
  if (0 < g_Direct3DViewport) {
    if (g_Direct3DDevice != (int *)0x0) {
      g_Direct3DLastResult =
           (**(code **)(*g_Direct3DDevice + 0x74))
                     (g_Direct3DDevice,4,3,&g_Direct3DQueuedTriangleV0,g_Direct3DViewport * 3,8);
    }
    g_Direct3DViewport = 0;
  }
  return;
}

