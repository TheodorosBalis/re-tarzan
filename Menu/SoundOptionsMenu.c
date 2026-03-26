// Address: 0x0049FE70

bool SoundOptionsMenu(void)

{
  uint uVar1;
  int iVar2;
  undefined **ppuVar3;
  uint uVar4;
  undefined **ppuVar5;
  char *pcVar6;
  
  if ((DAT_00724178 & 1) == 0) {
    DAT_00724178 = DAT_00724178 | 1;
    g_SoundOptionsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_SOUND_005166d0);
  }
  if (g_SoundOptionsMenuState == 0) {
    g_SoundOptionsMenuState = 2;
  }
  else if (g_SoundOptionsMenuState != 2) {
    if (g_SoundOptionsMenuState == 0x57) {
      g_SoundOptionsMenuState = 0;
    }
    goto switchD_0049ff68_caseD_3d;
  }
  uVar1 = GetUserInputInMenuAndProcessSound(1);
  uVar4 = uVar1 & 0x8000;
  if ((uVar4 == 0) && ((uVar1 & 1) != 0)) {
    g_SoundOptionsMenuCursor =
         SelectPreviousEnabledMenuItem(g_SoundOptionsMenuCursor,&PTR_s_SOUND_005166d0);
  }
  if (uVar4 == 0) {
    if ((uVar1 & 2) != 0) {
      g_SoundOptionsMenuCursor =
           SelectNextEnabledMenuItem(g_SoundOptionsMenuCursor,&PTR_s_SOUND_005166d0);
    }
    if ((uVar1 & 0x20) != 0) {
      g_SoundOptionsMenuState = 0x57;
    }
  }
  if (g_PendingOptionsMenuId != 0) {
    g_SoundOptionsMenuState = 0x57;
  }
  switch((&DAT_005166d4)[g_SoundOptionsMenuCursor * 4]) {
  case 0x38:
    if ((uVar4 == 0) && ((uVar1 & 0x1c) != 0)) {
      g_LegacyAudioModeEnabled = (uint)(g_LegacyAudioModeEnabled == 0);
      LegacyAudioCheck_DoNothing(-(g_LegacyAudioModeEnabled != 0) & 3);
    }
    break;
  case 0x39:
    ppuVar5 = (undefined **)(((int)g_AuxVolumePercent / 10) * 10);
    if (uVar4 == 0) {
      if ((uVar1 & 4) != 0) {
        ppuVar5 = (undefined **)((int)ppuVar5 + -10);
      }
      if ((uVar1 & 8) != 0) {
        ppuVar5 = (undefined **)((int)ppuVar5 + 10);
      }
    }
    if ((int)ppuVar5 < 10) {
      ppuVar5 = (undefined **)0xa;
    }
    else if (100 < (int)ppuVar5) {
      ppuVar5 = (undefined **)0x64;
    }
    if (ppuVar5 != g_AuxVolumePercent) {
      g_AuxVolumePercent = ppuVar5;
      SetAuxVolumePercent(ppuVar5);
    }
    break;
  case 0x3a:
    if ((uVar4 == 0) && ((uVar1 & 0x1c) != 0)) {
      g_SoundEffectsEnabled = (uint)(g_SoundEffectsEnabled == 0);
      if (g_SoundEffectsEnabled == 0) {
        OnlyonLegacyAudio();
        InitAudioLine();
      }
      else {
        FUN_004a8cd0();
      }
    }
    break;
  case 0x3b:
    ppuVar5 = (undefined **)(((int)g_MasterVolumePercent / 10) * 10);
    if (uVar4 == 0) {
      if ((uVar1 & 4) != 0) {
        ppuVar5 = (undefined **)((int)ppuVar5 + -10);
      }
      if ((uVar1 & 8) != 0) {
        ppuVar5 = (undefined **)((int)ppuVar5 + 10);
      }
    }
    if ((int)ppuVar5 < 10) {
      ppuVar5 = (undefined **)0xa;
    }
    else if (100 < (int)ppuVar5) {
      ppuVar5 = (undefined **)0x64;
    }
    if (ppuVar5 != g_MasterVolumePercent) {
      g_MasterVolumePercent = ppuVar5;
      SetVolumeForAllDevices(ppuVar5);
    }
    break;
  case 0x3c:
    if ((uVar4 == 0) && ((uVar1 & 0x1c) != 0)) {
      g_MusicEnabled = (uint)(g_MusicEnabled == 0);
      if (g_MusicEnabled == 0) {
        UpdateMciPlaybackStateIfNeeded();
      }
      else {
        FUN_00494210();
      }
    }
    break;
  case 0x57:
    if ((uVar4 == 0) && ((uVar1 & 0x10) != 0)) {
      g_SoundOptionsMenuState = 0x57;
    }
  }
switchD_0049ff68_caseD_3d:
  if (PTR_s_SOUND_005166d0 != (undefined *)0x0) {
    ppuVar5 = &PTR_s_SOUND_005166d0;
    do {
      switch(*(undefined2 *)(ppuVar5 + 1)) {
      case 0x38:
        iVar2 = FUN_004a79c0();
        uVar1 = g_LegacyAudioModeEnabled;
        if (iVar2 == 0) goto LAB_004a0140;
LAB_004a0135:
        if (uVar1 == 0) goto LAB_004a0163;
        ppuVar3 = (undefined **)&DAT_005175c4;
        break;
      case 0x39:
        pcVar6 = s__ld___005175c8;
        ppuVar3 = g_AuxVolumePercent;
        goto LAB_004a016e;
      case 0x3a:
        iVar2 = FUN_004a79e0();
        uVar1 = g_SoundEffectsEnabled;
        if (iVar2 != 0) goto LAB_004a0135;
LAB_004a0140:
        ppuVar3 = (undefined **)s_NOT_AVAILABLE_005175b4;
        break;
      case 0x3b:
        pcVar6 = s__ld___005175c8;
        ppuVar3 = g_MasterVolumePercent;
        goto LAB_004a016e;
      case 0x3c:
        ppuVar3 = (undefined **)&DAT_005175c4;
        if (g_MusicEnabled == 0) {
LAB_004a0163:
          ppuVar3 = &PTR_LAB_005175b0;
        }
        break;
      default:
        goto switchD_004a0102_default;
      }
      pcVar6 = &DAT_00515c68;
LAB_004a016e:
      DrawGraphicsTextinMem_2(&DAT_00723d38,pcVar6,ppuVar3);
      SetOptionsMenuEntryValueText(ppuVar5,&DAT_00723d38);
switchD_004a0102_default:
      ppuVar3 = ppuVar5 + 2;
      ppuVar5 = ppuVar5 + 2;
    } while (*ppuVar3 != (undefined *)0x0);
  }
  DrawOptionsMenu(&PTR_s_SOUND_005166d0,g_SoundOptionsMenuCursor);
  return g_SoundOptionsMenuState != 0;
}


