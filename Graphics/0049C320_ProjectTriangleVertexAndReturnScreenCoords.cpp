#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C320
// Label: ProjectTriangleVertexAndReturnScreenCoords
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProjectTriangleVertexAndReturnScreenCoords
               (undefined4 worldX,undefined4 worldY,undefined4 worldZ,undefined4 *outScreenX,
               undefined4 *outScreenY,undefined4 *outCameraZ)

{
  AdvanceProjectedTriangleVertex(worldX,worldY,worldZ);
  ProjectTriangleThirdVertex();
  *outScreenX = g_ProjectScreenX2;
  *outScreenY = g_ProjectScreenY2;
  *outCameraZ = g_ProjectCameraZ2;
  return;
}

