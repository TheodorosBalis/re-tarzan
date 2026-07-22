#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9E90
// Label: PrepareWorldAndMenuRenderState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PrepareWorldAndMenuRenderState(void)

{
  g_RenderViewportWidth = *(undefined2 *)(g_RenderWorldSceneActive + 4);
  g_RenderViewportHeight = *(undefined2 *)(g_RenderWorldSceneActive + 6);
  g_RenderBlendMode = 0;
  SetFadeTintPtrOrDefault(0);
  UpdateRenderCameraState(&g_TransitionSceneAnchorSecondary);
  UpdateRenderCameraState(&g_CameraFocusX);
  return;
}

