#include "tarzan_ghidra_types.hpp"

// Address: 0x00496350
// Label: FlushPendingDirect3DFrame
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FlushPendingDirect3DFrame(void)

{
  if (((g_Direct3DFrameDirty != 0) && (g_Direct3DFrameDirty = 0, g_Direct3DRendererInitialized != 0)
      ) && (g_Direct3DFrameBufferLocked == 0)) {
    UploadPendingDirect3DFrameBuffer();
    if (g_Direct3DDevice != (int *)0x0) {
      g_Direct3DLastResult = (**(code **)(*g_Direct3DDevice + 0x2c))(g_Direct3DDevice);
    }
  }
  return;
}

