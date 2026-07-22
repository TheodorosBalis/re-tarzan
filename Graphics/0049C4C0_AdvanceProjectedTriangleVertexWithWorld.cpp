#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C4C0
// Label: AdvanceProjectedTriangleVertexWithWorld
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AdvanceProjectedTriangleVertexWithWorld
               (undefined4 arg1,undefined4 arg2,undefined4 arg3)

{
  g_ProjectScreenX0 = g_ProjectScreenX1;
  g_ProjectScreenX1 = g_ProjectScreenX2;
  g_ProjectScreenY0 = g_ProjectScreenY1;
  g_ProjectScreenY1 = g_ProjectScreenY2;
  _g_ProjectCameraX0 = g_ProjectCameraX1;
  g_ProjectCameraX1 = g_ProjectCameraX2;
  _g_ProjectCameraY0 = g_ProjectCameraY1;
  g_ProjectCameraY1 = g_ProjectCameraY2;
  g_ProjectCameraZ0 = g_ProjectCameraZ1;
  g_ProjectCameraZ1 = g_ProjectCameraZ2;
  _g_ProjectInputX2 = arg1;
  _g_ProjectInputY2 = arg2;
  _g_ProjectInputZ2 = arg3;
  return;
}

