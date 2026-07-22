#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D160
// Label: TryInitGlideGraphicsMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 TryInitGlideGraphicsMode(int graphicsObject,int source2,int dest)

{
  float floatValue;
  float *floatCursor;
  float *floatCursor2;
  int value;
  uint value4;
  int value2;
  int value3;
  uint value5;
  undefined4 *dataCursor2;
  uint *dataCursor;
  
  if (dest != 0) {
    return 4;
  }
  if (g_GlideFrameBufferPtr != 0) {
    return 0;
  }
  if (graphicsObject == 0) {
    return 3;
  }
  SetGlideGammaEnvironmentVariablesForGlideInit();
  g_GlideFullscreenMode = graphicsObject;
  g_GlideSelectedDisplayMode = (uint)(source2 != 0);
  g_GlideFrameBufferLockActive = 0;
  g_GlideWindowStateNeedsRestore = 0;
  g_GlideFrameBufferStride = 0;
  g_GlideViewportLeft = 0;
  _g_GlideTextureUploadPageIndex = 0;
  g_GlideViewportTop = 0;
  g_GlideViewportWidth = 3;
  g_GlideViewportHeight = 0xb;
  dest = 0;
  floatCursor2 = (float *)&g_GlideTriangleVertexScratch;
  do {
    floatValue = (float)dest;
    floatCursor = floatCursor2 + 1;
    dest = dest + 1;
    *floatCursor2 = floatValue;
    floatCursor2 = floatCursor;
  } while ((int)floatCursor < 0x723704);
  dest = 0;
  floatCursor2 = (float *)&DAT_00722e68;
  do {
    floatValue = (float)dest;
    floatCursor = floatCursor2 + 1;
    dest = dest + 1;
    *floatCursor2 = floatValue;
    floatCursor2 = floatCursor;
  } while ((int)floatCursor < 0x723268);
  dest = 0;
  floatCursor2 = (float *)&DAT_007229a8;
  do {
    floatValue = (float)dest;
    floatCursor = floatCursor2 + 1;
    dest = dest + 1;
    *floatCursor2 = floatValue + _g_FloatRenderHalfPixelOffset;
    floatCursor2 = floatCursor;
  } while ((int)floatCursor < 0x722da8);
  g_GlideGammaTable = (undefined *)&DAT_007229a8;
  value = LoadGlide2xLibraryEntryPoints();
  if (value != 0) {
    dataCursor2 = &g_GlideInitScratch_Field08C8;
    for (value = 0x25; value != 0; value = value + -1) {
      *dataCursor2 = 0;
      dataCursor2 = dataCursor2 + 1;
    }
    value = (*g_GlideInitScratch_Field0DF4)(&g_GlideInitScratch_Field08C8);
    if ((value == 1) && (0 < g_GlideInitScratch_Field08C8)) {
      SaveWindowStateBeforeGlideModeChange(g_GlideFullscreenMode);
      (*g_GlideInitScratch_Field0DE0)();
      g_GlideWindowModePending = 1;
      value = (*g_GlideInitScratch_Field0DF8)(&g_GlideInitScratch_Field08C8);
      if ((value == 1) &&
         (g_GlideRenderStateColorCombine = g_GlideInitScratch_Field08D8,
         0 < g_GlideInitScratch_Field08D8)) {
        if (2 < g_GlideInitScratch_Field08D8) {
          g_GlideRenderStateColorCombine = 2;
        }
        (*g_GlideInitScratch_Field0DFC)(0);
        value = (*g_GlideInitScratch_Field0E08)
                          (g_GlideViewportLeft,g_GlideViewportTop,g_GlideViewportWidth,
                           g_GlideViewportHeight);
        value5 = 0;
        source2 = 0;
        if (0 < g_GlideRenderStateColorCombine) {
          do {
            value3 = 0;
            value4 = (*g_GlideTexMaxAddressProc)(value5);
            value2 = (*g_GlideTexMinAddressProc)(value5);
            if (value4 <= (uint)(value2 + (8 - value))) {
              dataCursor = (uint *)(&g_GlideTextureMemoryRanges + source2 * 8);
              do {
                dataCursor[-1] = value5;
                *dataCursor = value4;
                dataCursor = dataCursor + 2;
                source2 = source2 + 1;
                if (0x722e6b < (int)dataCursor) goto LAB_0049d3c6;
                value3 = value3 + value;
                value2 = (*g_GlideTexMaxAddressProc)(value5);
                value4 = value2 + value3;
                value2 = (*g_GlideTexMinAddressProc)(value5);
              } while (value4 <= (uint)(value2 + (8 - value)));
            }
            value5 = value5 + 1;
          } while ((int)value5 < g_GlideRenderStateColorCombine);
LAB_0049d3c6:
          if (source2 == 0x10) {
            SetGlideFullscreenDisplayMode(1);
            (*g_GlideInitScratch_Field0DD4)();
            value = 3;
            do {
              (*g_GlideClearColor)(0,0,0xffff);
              (*g_GlideClearDepth)(0);
              value = value + -1;
            } while (value != 0);
            ConfigureDefaultGlideRenderState();
            g_GlideFrameBufferPtr = 1;
            return 0;
          }
        }
      }
      DoReconfigurationStuffOnWindow();
      return 3;
    }
  }
  DoReconfigurationStuffOnWindow();
  return 1;
}

