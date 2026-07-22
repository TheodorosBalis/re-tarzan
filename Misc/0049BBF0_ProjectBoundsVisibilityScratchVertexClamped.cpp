#include "tarzan_ghidra_types.hpp"

// Address: 0x0049BBF0
// Label: ProjectBoundsVisibilityScratchVertexClamped
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void ProjectBoundsVisibilityScratchVertexClamped(int arg1)

{
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
  (&g_ProjectCameraZ0)[arg1] = value;
  if (value < _g_RenderNearClipDepth) {
    (&g_ProjectCameraZ0)[arg1] = 0x3f800000;
  }
  if (_g_RenderNearClipDepth <= (float)(&g_ProjectCameraZ0)[arg1]) {
    value = g_ProjectionDepthScale / (float)(&g_ProjectCameraZ0)[arg1];
    (&g_ProjectScreenX0)[arg1] =
         *(float *)(&g_ProjectCameraX0 + arg1 * 4) * value + g_ProjectionScreenOriginX;
    (&g_ProjectScreenY0)[arg1] =
         value * *(float *)(&g_ProjectCameraY0 + arg1 * 4) + _g_ProjectionScreenOriginY;
  }
  return;
}

