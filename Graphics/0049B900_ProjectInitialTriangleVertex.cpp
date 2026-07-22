#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B900
// Label: ProjectInitialTriangleVertex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProjectInitialTriangleVertex(int arg1)

{
  bool flagByte;
  float value;
  
  *(float *)(&g_ProjectCameraX0 + arg1 * 4) =
       g_ProjectMatrix00 * *(float *)(&g_ProjectInputX0 + arg1 * 4) +
       _g_ProjectMatrix02 * *(float *)(&g_ProjectInputZ0 + arg1 * 4) +
       g_ProjectMatrix01 * *(float *)(&g_ProjectInputY0 + arg1 * 4) + _g_ProjectTranslateX;
  *(float *)(&g_ProjectCameraY0 + arg1 * 4) =
       _g_ProjectMatrix10 * *(float *)(&g_ProjectInputX0 + arg1 * 4) +
       _g_ProjectMatrix12 * *(float *)(&g_ProjectInputZ0 + arg1 * 4) +
       _g_ProjectMatrix11 * *(float *)(&g_ProjectInputY0 + arg1 * 4) + _g_ProjectTranslateY;
  value = _g_ProjectMatrix20 * *(float *)(&g_ProjectInputX0 + arg1 * 4) +
          _g_ProjectMatrix22 * *(float *)(&g_ProjectInputZ0 + arg1 * 4) +
          _g_ProjectMatrix21 * *(float *)(&g_ProjectInputY0 + arg1 * 4) + _g_ProjectTranslateZ;
  flagByte = _g_RenderNearClipDepth <= value;
  (&g_ProjectCameraZ0)[arg1] = value;
  if (flagByte) {
    value = g_ProjectionDepthScale / value;
    (&g_ProjectScreenX0)[arg1] =
         *(float *)(&g_ProjectCameraX0 + arg1 * 4) * value + g_ProjectionScreenOriginX;
    (&g_ProjectScreenY0)[arg1] =
         value * *(float *)(&g_ProjectCameraY0 + arg1 * 4) + _g_ProjectionScreenOriginY;
    return;
  }
  return;
}

