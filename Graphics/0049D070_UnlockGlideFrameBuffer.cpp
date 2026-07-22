#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D070
// Label: UnlockGlideFrameBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlockGlideFrameBuffer(void)

{
  if ((g_GlideFrameBufferPtr != 0) && (g_GlideFrameBufferLockActive != 0)) {
    (*g_GlideLfbUnlockProc)(g_GlideFrameBufferLockActive == 2,g_GlideLfbLockWriteFlag != 0);
    g_GlideFrameBufferLockActive = 0;
  }
  return;
}

