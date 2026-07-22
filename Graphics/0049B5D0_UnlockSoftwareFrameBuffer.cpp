#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B5D0
// Label: UnlockSoftwareFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlockSoftwareFrameBuffer(void)

{
  if ((isGraphicsInitialized != 0) && (g_SoftwareFrameBufferLocked != 0)) {
    g_SoftwareFrameBufferLocked = 0;
  }
  return;
}

