// Address: 0x004A9E90

void PrepareWorldAndMenuRenderState(void)

{
  g_RenderViewportWidth = *(undefined2 *)(DAT_0051c58c + 4);
  g_RenderViewportHeight = *(undefined2 *)(DAT_0051c58c + 6);
  g_RenderBlendMode = 0;
  SetFadeTintPtrOrDefault(0);
  UpdateRenderCameraState(&g_TransitionSceneAnchorSecondary);
  UpdateRenderCameraState(&g_TransitionSceneAnchorPrimary);
  return;
}


