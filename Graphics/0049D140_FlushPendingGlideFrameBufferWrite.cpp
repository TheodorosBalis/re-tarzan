#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D140
// Label: FlushPendingGlideFrameBufferWrite
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FlushPendingGlideFrameBufferWrite(void)

{
  if ((g_GlideFrameBufferPtr != 0) && (g_GlideFrameBufferLockActive == 0)) {
    (*g_GlideClearDepth)(1);
  }
  return;
}

