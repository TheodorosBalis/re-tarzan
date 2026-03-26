// Address: 0x004291E0

undefined4 CWorld__Process(void)

{
  char cVar1;
  
  cVar1 = FUN_004493c0();
  if (cVar1 == '\0') {
    thunk_FUN_00444560();
    FUN_0042da50();
    DAT_0051c51a = DAT_0051c51a & 0xfff;
    return 1;
  }
  if (g_LoadTransitionFlags._2_2_ != 0) {
    DrawNatureTerrain(&g_TransitionSceneContext,&g_TransitionSceneAnchorPrimary);
  }
  if (g_LevelTransitionContext._2_1_ == '\v') {
    thunk_FUN_00438bb0();
    FUN_0042da50();
    DAT_0051c51a = DAT_0051c51a & 0xfff;
    return 1;
  }
  FUN_00438bb0();
  FUN_0042da50();
  DAT_0051c51a = DAT_0051c51a & 0xfff;
  return 1;
}


