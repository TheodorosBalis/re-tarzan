#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B740
// Label: ProjectInitialTriangleEdgeVertices
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProjectInitialTriangleEdgeVertices(void)

{
  _g_ProjectCameraX0 =
       _g_ProjectInputX0 * g_ProjectMatrix00 +
       _g_ProjectInputY0 * g_ProjectMatrix01 + _g_ProjectInputZ0 * _g_ProjectMatrix02 +
       _g_ProjectTranslateX;
  _g_ProjectCameraY0 =
       _g_ProjectInputX0 * _g_ProjectMatrix10 +
       _g_ProjectInputY0 * _g_ProjectMatrix11 + _g_ProjectInputZ0 * _g_ProjectMatrix12 +
       _g_ProjectTranslateY;
  g_ProjectCameraZ0 =
       _g_ProjectInputX0 * _g_ProjectMatrix20 +
       _g_ProjectInputY0 * _g_ProjectMatrix21 + _g_ProjectInputZ0 * _g_ProjectMatrix22 +
       _g_ProjectTranslateZ;
  if (_g_RenderNearClipDepth <= g_ProjectCameraZ0) {
    g_ProjectScreenX0 =
         _g_ProjectCameraX0 * (g_ProjectionDepthScale / g_ProjectCameraZ0) +
         g_ProjectionScreenOriginX;
    g_ProjectScreenY0 =
         (g_ProjectionDepthScale / g_ProjectCameraZ0) * _g_ProjectCameraY0 +
         _g_ProjectionScreenOriginY;
  }
  g_ProjectCameraX1 =
       _g_ProjectInputX1 * g_ProjectMatrix00 +
       _g_ProjectInputY1 * g_ProjectMatrix01 + _g_ProjectInputZ1 * _g_ProjectMatrix02 +
       _g_ProjectTranslateX;
  g_ProjectCameraY1 =
       _g_ProjectInputX1 * _g_ProjectMatrix10 +
       _g_ProjectInputY1 * _g_ProjectMatrix11 + _g_ProjectInputZ1 * _g_ProjectMatrix12 +
       _g_ProjectTranslateY;
  g_ProjectCameraZ1 =
       _g_ProjectInputX1 * _g_ProjectMatrix20 +
       _g_ProjectInputY1 * _g_ProjectMatrix21 + _g_ProjectInputZ1 * _g_ProjectMatrix22 +
       _g_ProjectTranslateZ;
  if (_g_RenderNearClipDepth <= g_ProjectCameraZ1) {
    g_ProjectScreenX1 =
         g_ProjectCameraX1 * (g_ProjectionDepthScale / g_ProjectCameraZ1) +
         g_ProjectionScreenOriginX;
    g_ProjectScreenY1 =
         (g_ProjectionDepthScale / g_ProjectCameraZ1) * g_ProjectCameraY1 +
         _g_ProjectionScreenOriginY;
  }
  ProjectInitialTriangleVertex(2);
  return;
}

