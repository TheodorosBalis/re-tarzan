undefined4 CWorld::Process(void)

{
  char cVar1;
  
  cVar1 = CWorld::ShouldRunGameplayTick();
  if (cVar1 == '\0') {
    CWorld::UpdateHudPhase_stub();
    CWorld::DoExitFromLevel();
    g_CameraYaw = g_CameraYaw & 0xfff;
    return 1;
  }
  if (g_LoadTransitionFlags._2_2_ != 0) {
    CWorld::UpdateNatureTerrain(&g_TransitionSceneContext,&g_CameraFocusX);
  }
  if (g_LevelTransitionContext._2_1_ == '\v') {
    CWorld::ProcessGameplayTick_stub();
    CWorld::DoExitFromLevel();
    g_CameraYaw = g_CameraYaw & 0xfff;
    return 1;
  }
  CWorld::ProcessGameplayTick();
  CWorld::DoExitFromLevel();
  g_CameraYaw = g_CameraYaw & 0xfff;
  return 1;
}