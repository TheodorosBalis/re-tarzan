#include "tarzan_ghidra_types.hpp"

// Address: 0x0049BD00
// Label: ProjectTriangleThirdVertex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProjectTriangleThirdVertex(void)

{
  g_ProjectCameraX2 =
       _g_ProjectInputX2 * g_ProjectMatrix00 +
       _g_ProjectInputY2 * g_ProjectMatrix01 + _g_ProjectInputZ2 * _g_ProjectMatrix02 +
       _g_ProjectTranslateX;
  g_ProjectCameraY2 =
       _g_ProjectInputX2 * _g_ProjectMatrix10 +
       _g_ProjectInputY2 * _g_ProjectMatrix11 + _g_ProjectInputZ2 * _g_ProjectMatrix12 +
       _g_ProjectTranslateY;
  g_ProjectCameraZ2 =
       _g_ProjectInputX2 * _g_ProjectMatrix20 +
       _g_ProjectInputY2 * _g_ProjectMatrix21 + _g_ProjectInputZ2 * _g_ProjectMatrix22 +
       _g_ProjectTranslateZ;
  if (_g_RenderNearClipDepth <= g_ProjectCameraZ2) {
    g_ProjectScreenX2 =
         g_ProjectCameraX2 * (g_ProjectionDepthScale / g_ProjectCameraZ2) +
         g_ProjectionScreenOriginX;
    g_ProjectScreenY2 =
         (g_ProjectionDepthScale / g_ProjectCameraZ2) * g_ProjectCameraY2 +
         _g_ProjectionScreenOriginY;
  }
  return;
}

