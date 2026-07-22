#include "tarzan_ghidra_types.hpp"

// Address: 0x00454C60
// Label: RenderModelHierarchy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderModelHierarchy(int graphicsObject,int source2,uint dest)

{
  int value;
  
  ResetRenderScratchPacketCount();
  g_ModelHierarchyTransformStackCursor = &g_ModelHierarchyTransformStackBase;
  g_ModelHierarchyPackedTransformCursor = source2 + 0x14;
  if ((dest & 0x800) == 0) {
    value = ClassifyLocalBoundsVisibility(graphicsObject + 8);
    if (value == 0) {
      return;
    }
  }
  if (g_RenderModelCurrentFlags != 0) {
    RenderAnimatedModelCommandStream();
    return;
  }
  RenderModelCommandStream();
  return;
}

