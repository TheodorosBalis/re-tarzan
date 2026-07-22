#include "tarzan_ghidra_types.hpp"

// Address: 0x00454BE0
// Label: RenderInterpolatedModelHierarchy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RenderInterpolatedModelHierarchy
               (int graphicsObject,int source2,undefined2 dest,undefined4 *width,uint height)

{
  int value;
  undefined4 *dataCursor;
  undefined4 *dataCursor2;
  
  ResetRenderScratchPacketCount();
  if (width == &g_ModelHierarchyTransformStackBase) {
    g_ModelHierarchyTransformStackCursor = &g_ModelHierarchyTransformStackBase;
    g_ModelHierarchyPackedTransformCursor = graphicsObject + 0x14;
    dataCursor = &g_ModelHierarchyTransformStackBase;
    dataCursor2 = &g_ModelHierarchyTransformStackBase;
    for (value = 8; value != 0; value = value + -1) {
      *dataCursor2 = *dataCursor;
      dataCursor = dataCursor + 1;
      dataCursor2 = dataCursor2 + 1;
    }
    _g_ModelHierarchyInterpolationScratch = 0;
    if (((height & 0x800) == 0) && (value = ClassifyLocalBoundsVisibility(graphicsObject + 8), value == 0)
       ) {
      return;
    }
    g_ModelHierarchyCommandEnd = source2 + 0x14;
    g_ModelHierarchyBlendAmount = dest;
    RenderInterpolatedModelCommandStream();
  }
  return;
}

