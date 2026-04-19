void CWorld::ProcessGameplayTick(void)

{
  RebuildModelHeapStats(&g_ModelLoadHeapState);
  if ((g_DeathRespawnFadeState & 8) == 0) {
    RunDormantPhase2Pass();
  }
  else {
    CEntities::UpdateStreaming();
    CPlayerHero::Update();
    CEntities::Process();
  }
  CWorld::ReInitOnDeath();
  CCamera::Update(0);
  TotalGameLoopTicks = TotalGameLoopTicks + 1;
  return;
}