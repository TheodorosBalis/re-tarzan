// 0x004332d0

void RespawnAndReinitializeGameplayWorld(void)

{
  g_HudCollectedTARZANslotSlideTicks = 0x78;
  g_HudCollectedSketchSlideTicks = 0x78;
  _DAT_005321a8 = 0x78;
  ResetRespawnRuntimeListsAndEntries();
  RebuildLoadedWorldSceneState();
  ResetGameplayRuntimeState();
  RefreshGameplaySceneCallbacks();
  return;
}