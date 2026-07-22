#include "tarzan_ghidra_types.hpp"

// Address: 0x004AA830
// Label: RenderSceneAssetIfVisible
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RenderSceneAssetIfVisible(int graphicsObject,uint source2)

{
  int entry;
  
  if (graphicsObject != 0) {
    if (((source2 & 0x800) == 0) &&
       (entry = ClassifyProjectedBoundsVisibility(*(int *)(graphicsObject + 0xc) + 0xc + graphicsObject),
       entry != 1)) {
      return;
    }
    RenderSceneAssetTriangles(graphicsObject);
  }
  return;
}

