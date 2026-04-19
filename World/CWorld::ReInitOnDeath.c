// 0x0042d8f0

void CWorld::ReInitOnDeath(void)

{
  switch(_g_DeathRespawnFadeState) {
  case 8:
    if ((g_LoadTransitionFlags & 0x8000) != 0) {
      ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0xb4);
      g_GameplayStateFlags._0_1_ = (byte)g_GameplayStateFlags | 8;
      _g_DeathRespawnFadeState = 10;
      return;
    }
    break;
  case 9:
    if ((ram0x00534026 & 0x8000) == 0) {
      _g_DeathRespawnFadeState = 8;
      return;
    }
    break;
  case 10:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      if ((short)g_LoadTransitionFlags == -0x7ffe) {
        g_GameplayStateFlags._0_1_ = (byte)g_GameplayStateFlags | 0x10;
        return;
      }
      if ((short)g_LoadTransitionFlags != -0x7fff) {
        if (((DAT_00534010 & 0x100) == 0) &&
           (g_LevelTransitionContext._3_1_ = g_LevelTransitionContext._3_1_ + -1,
           g_LevelTransitionContext._3_1_ < '\0')) {
          g_LoadTransitionFlags = CONCAT22(g_LoadTransitionFlags._2_2_,0x8080);
        }
        g_DeathRespawnBlackScreenDelayTicks = 0x1e;
        _g_DeathRespawnFadeState = 0x10;
        return;
      }
      if ((DAT_00534010 & 2) != 0) {
        g_CollectedSketchPieceMask4 = g_CollectedSketchPieceMask4 | 0xf;
      }
      g_GameplayStateFlags._0_1_ = (byte)g_GameplayStateFlags | 0x10;
      return;
    }
    break;
  case 0x10:
    if (g_DeathRespawnBlackScreenDelayTicks != 0) {
      g_DeathRespawnBlackScreenDelayTicks = g_DeathRespawnBlackScreenDelayTicks + -1;
      return;
    }
    if ((short)g_LoadTransitionFlags == -0x7f80) {
      g_GameplayStateFlags._0_1_ = (byte)g_GameplayStateFlags | 0x10;
      return;
    }
    RespawnAndReinitializeGameplayWorld();
    InitiateFade(1,0xb4);
    g_LoadTransitionFlags = g_LoadTransitionFlags & 0xffff0000;
    _g_DeathRespawnFadeState = 9;
  }
  return;
}