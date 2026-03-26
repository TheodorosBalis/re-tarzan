// Address: 0x004AC730

void RefreshAudioListenerAndChannelMask(void)

{
  g_ActiveAudioChannelMask = GetPlayingSoundChannelMask();
  UpdateRenderCameraState(&g_TransitionSceneAnchorPrimary);
  SetTransformBasisFromRef(&DAT_0051c530);
  return;
}


