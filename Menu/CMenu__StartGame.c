// 0x452FD0
void CMenu__StartGame(void)

{
  InitiateFade(2,0x100);
  g_LevelTransitionContext._3_1_ =
       (&g_LevelTransitionTypeBySlot)[g_LevelTransitionContext._1_1_ * 2];
  g_LoadTransitionFlags._0_2_ = 0;
  gCurrentCoinsCollected = 0;
  g_SelectedLevelIndex = 0;
  ResetEcmAudioPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  return;
}