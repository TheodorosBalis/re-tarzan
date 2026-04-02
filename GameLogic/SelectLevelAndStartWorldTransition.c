// Address: 0x004AC080

void SelectLevelAndStartWorldTransition(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (g_LevelTransitionContext._2_1_ == '\x16') {
    iVar3 = 0;
    if (g_LevelTransitionEntries != -1) {
      puVar2 = &g_LevelTransitionEntries;
      iVar1 = g_LevelTransitionEntries;
      do {
        if ((iVar1 == param_1) && (puVar2[1] == param_2)) break;
        iVar1 = puVar2[0xf];
        puVar2 = puVar2 + 0xf;
        iVar3 = iVar3 + 1;
      } while (iVar1 != -1);
    }
    if ((&g_LevelTransitionEntries)[iVar3 * 0xf] != -1) {
      g_SelectedLevelIndex = (undefined1)iVar3;
      g_LevelTransitionContext._3_1_ =
           (&g_LevelTransitionTypeBySlot)[g_LevelTransitionContext._1_1_ * 2];
      g_LoadTransitionFlags._0_2_ = 0;
      gCurrentCoinsCollected = 0;
      ResetEcmAudioPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0x100);
      MenuState = 2;
    }
  }
  return;
}


