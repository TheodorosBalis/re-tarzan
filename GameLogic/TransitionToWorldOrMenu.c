// Address: 0x004ABFD0

void TransitionToWorldOrMenu(int param_1)

{
  DAT_00534010 = DAT_00534010 & 0xfffffffb;
  bIsOnTransition = 1;
  if (param_1 != 1) {
    SetControlKeysOnlyMode(1);
    DAT_00c4604c = 0;
    LoadMenuOrAdvanceLevel(0);
    DAT_00c46050 = CMenu::Process;
    _CWorld__Render = CMenu::Render;
    return;
  }
  SetControlKeysOnlyMode(g_PendingTransitionPayload != 0);
  DAT_00c4604c = 1;
  LoadAndBuildWorldScene(0);
  DAT_00c46050 = CWorld__Process;
  _CWorld__Render = CWorld__Render;
  if (g_PendingTransitionPayload == 0) {
    UpdateCFGFile((int)g_LevelTransitionContext._2_1_,(int)g_LevelTransitionContext._1_1_);
  }
  return;
}


