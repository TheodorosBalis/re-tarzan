#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D0B0
// Label: BeginGlideFrameBufferWrite
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BeginGlideFrameBufferWrite(uint graphicsObject)

{
  if (g_GlideFrameBufferPtr == 0) {
    return;
  }
  if (g_GlideWindowStateNeedsRestore == 0) {
    if (g_GlideFrameBufferLockActive != 0) {
      return;
    }
    if (graphicsObject == 0xffffffff) {
      if (g_GlideSelectedDisplayMode == 0) {
        g_GlideCurrentTexturePageIndex = 0x80;
        g_GlideFrameBufferStride = 0x80;
        g_GlideCurrentTextureModulationMode = 0x80;
        g_GlideWindowStateNeedsRestore = 1;
        return;
      }
      graphicsObject = 0;
      (*g_GlideColorMaskProc)(0,1);
    }
    (*g_GlideClearColor)(graphicsObject & 0xffffff,0,0xffff);
    (*g_GlideColorMaskProc)(1,1);
    g_GlideWindowStateNeedsRestore = 1;
    g_GlideCurrentTextureModulationMode = 0x80;
    g_GlideFrameBufferStride = 0x80;
    g_GlideCurrentTexturePageIndex = 0x80;
    return;
  }
  return;
}

