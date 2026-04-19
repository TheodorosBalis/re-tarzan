// 0x0042da50

void CWorld::DoExitFromLevel(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((ushort)g_GameplayStateFlags & 0x10) != 0) {
    InitAudioLine__stub();
    g_GameplayStateFlags._0_2_ = 0;
    SuspendAllSound();
    ResetEntitySoundSlotLists();
    Empty_stub();
    LoadFonts(&PTR_DAT_00502d48,&DAT_00c4602c);
    if (g_PendingTransitionPayload == 0) {
      iVar1 = (int)g_SelectedLevelIndex;
      iVar2 = iVar1 * 0x3c;
      if ((short)g_LoadTransitionFlags == -0x7fff) {
        if (((byte)DAT_00534010 & 1) != 0) {
          g_CollectedTARZANLetterMask6 = 0x3f;
        }
        if ((g_CollectedTARZANLetterMask6 & 0x3f) == 0x3f) {
          *(byte *)((int)&DAT_00534030 + (int)g_LevelTransitionContext._2_1_) =
               *(byte *)((int)&DAT_00534030 + (int)g_LevelTransitionContext._2_1_) |
               '\x01' << (g_LevelTransitionContext._1_1_ & 0x1f);
        }
        if ((&DAT_004f26a4)[iVar1 * 0xf] == -1) {
          PlayAudioById(*(undefined4 *)(&DAT_004ebfc4 + (char)g_LevelTransitionContext._1_1_ * 4),0,
                        0);
          ProcessMovieClipOrLogo(0x4004,0x78,0,0xffff);
        }
        ProcessMovieClipOrLogo(*(undefined4 *)(&DAT_004f2690 + iVar2),0x5a,0,0xffff);
        ProcessMovieClipOrLogo
                  (*(undefined4 *)(iVar2 + 0x4f2694 + (char)g_LevelTransitionContext._1_1_ * 4),0x5a
                   ,0,0xffff);
        ProcessMovieClipOrLogo(*(undefined4 *)(&DAT_004f26a0 + iVar2),0x5a,0,0xffff);
        TransitionToWorldOrMenu(0);
        return;
      }
      if ((g_LoadTransitionFlags & 0x8080) == 0x8080) {
        iVar1 = RandomModulo(2,0x5a,0,0xffff);
        ProcessMovieClipOrLogo(*(undefined4 *)(iVar2 + 0x4f2688 + iVar1 * 4));
        if (g_SelectedLevelIndex < '\f') {
          iVar2 = RandomModulo(5,0,0);
          uVar3 = *(undefined4 *)(&DAT_004ebf9c + iVar2 * 4);
        }
        else {
          iVar2 = RandomModulo(5,0,0);
          uVar3 = *(undefined4 *)(&DAT_004ebfb0 + iVar2 * 4);
        }
        PlayAudioById(uVar3);
        SetActiveMenuContext(&g_MenuSceneContext);
        ProcessLevelLogo(&DAT_004e57e0);
        InitAudioLine_stub();
        TransitionToWorldOrMenu(0);
        return;
      }
    }
    SetActiveMenuContext(&g_MenuSceneContext);
    TransitionToWorldOrMenu(0);
  }
  return;
}