#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C450
// Label: AdvanceProjectedTriangleVertex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AdvanceProjectedTriangleVertex(undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  g_ProjectScreenX0 = g_ProjectScreenX1;
  g_ProjectScreenX1 = g_ProjectScreenX2;
  g_ProjectScreenY0 = g_ProjectScreenY1;
  g_ProjectScreenY1 = g_ProjectScreenY2;
  g_ProjectCameraZ0 = g_ProjectCameraZ1;
  g_ProjectCameraZ1 = g_ProjectCameraZ2;
  _g_ProjectInputX2 = arg1;
  _g_ProjectInputY2 = arg2;
  _g_ProjectInputZ2 = arg3;
  return;
}

