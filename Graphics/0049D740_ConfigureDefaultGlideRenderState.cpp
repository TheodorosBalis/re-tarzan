#include "tarzan_ghidra_types.hpp"

// Address: 0x0049D740
// Label: ConfigureDefaultGlideRenderState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ConfigureDefaultGlideRenderState(void)

{
  int value;
  
  (*g_GlideProcTable_Field0038)(0x3f800000);
  (*g_GlideProcTable_Field0034)(2);
  (*g_GlideProcTable_Field0024)(-(g_GlideSelectedDisplayMode != 0) & 2);
  (*g_GlideProcTable_Field002C)(g_GlideSelectedDisplayMode != 0);
  if (g_GlideSelectedDisplayMode != 0) {
    (*g_GlideProcTable_Field0028)(3);
  }
  value = 0;
  if (0 < g_GlideRenderStateColorCombine) {
    do {
      (*g_GlideTexCombineProc)(value,1,0,1,0,0,0);
      value = value + 1;
    } while (value < g_GlideRenderStateColorCombine);
  }
  (*g_GlideProcTable_Field0018)(3,1,0,1,0);
  (*g_GlideProcTable_Field0004)(3,1,0,1,0);
  (*g_GlideAlphaBlendFunctionProc)(1,5,0,0);
  (*g_GlideProcTable_Field0008)(4);
  (*g_GlideProcTable_Field000C)(0);
  value = 0;
  if (0 < g_GlideRenderStateColorCombine) {
    do {
      (*g_GlideTexClampModeProc)(value,1,1);
      value = value + 1;
    } while (value < g_GlideRenderStateColorCombine);
  }
  value = 0;
  if (0 < g_GlideRenderStateColorCombine) {
    do {
      (*g_GlideProcTable_Field007C)(value,0,0);
      value = value + 1;
    } while (value < g_GlideRenderStateColorCombine);
  }
  (*g_GlideProcTable_Field0020)(0);
  return;
}

