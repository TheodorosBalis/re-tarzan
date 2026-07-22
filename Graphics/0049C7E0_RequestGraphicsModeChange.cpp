#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C7E0
// Label: RequestGraphicsModeChange
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 RequestGraphicsModeChange(int graphicsObject)

{
  if (graphicsObject != 7) {
    if ((graphicsObject < 1) || (5 < graphicsObject)) {
      graphicsObject = 5;
    }
    g_RequestedGraphicsMode = -graphicsObject;
    if ((&g_GraphicsModeFailureReasonByMode)[graphicsObject] != 0) {
      return 0;
    }
  }
  g_RequestedGraphicsMode = graphicsObject;
  return 1;
}

