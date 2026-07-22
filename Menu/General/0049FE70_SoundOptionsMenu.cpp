#include "tarzan_ghidra_types.hpp"

// Address: 0x0049FE70
// Label: SoundOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool SoundOptionsMenu(void)

{
  uint soundMask;
  int menuIndex;
  undefined **dataCursor;
  uint soundMask2;
  undefined **dataCursor2;
  char *stringCursor;
  
  if ((g_SoundOptionsMenuInitializedFlag & 1) == 0) {
    g_SoundOptionsMenuInitializedFlag = g_SoundOptionsMenuInitializedFlag | 1;
    g_SoundOptionsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&g_SoundOptionsMenuEntryTable);
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
  soundMask = GetUserInputInMenuAndProcessSound(1);
  soundMask2 = soundMask & 0x8000;
  if ((soundMask2 == 0) && ((soundMask & 1) != 0)) {
    g_SoundOptionsMenuCursor =
         SelectPreviousEnabledMenuItem(g_SoundOptionsMenuCursor,&g_SoundOptionsMenuEntryTable);
  }
  if (soundMask2 == 0) {
    if ((soundMask & 2) != 0) {
      g_SoundOptionsMenuCursor =
           SelectNextEnabledMenuItem(g_SoundOptionsMenuCursor,&g_SoundOptionsMenuEntryTable);
    }
    if ((soundMask & 0x20) != 0) {
      g_SoundOptionsMenuState = 0x57;
    }
  }
  if (g_PendingOptionsMenuId != 0) {
    g_SoundOptionsMenuState = 0x57;
  }
  switch((&g_SoundOptionsMenuEntryIdTable)[g_SoundOptionsMenuCursor * 4]) {
  case 0x38:
    if ((soundMask2 == 0) && ((soundMask & 0x1c) != 0)) {
      g_LegacyAudioModeEnabled = (uint)(g_LegacyAudioModeEnabled == 0);
      LegacyAudioCheck_DoNothing(-(g_LegacyAudioModeEnabled != 0) & 3);
    }
    break;
  case 0x39:
    dataCursor2 = (undefined **)(((int)g_AuxVolumePercent / 10) * 10);
    if (soundMask2 == 0) {
      if ((soundMask & 4) != 0) {
        dataCursor2 = (undefined **)((int)dataCursor2 + -10);
      }
      if ((soundMask & 8) != 0) {
        dataCursor2 = (undefined **)((int)dataCursor2 + 10);
      }
    }
    if ((int)dataCursor2 < 10) {
      dataCursor2 = (undefined **)0xa;
    }
    else if (100 < (int)dataCursor2) {
      dataCursor2 = (undefined **)0x64;
    }
    if (dataCursor2 != g_AuxVolumePercent) {
      g_AuxVolumePercent = dataCursor2;
      SetWaveOutMixerVolumePercent(dataCursor2);
    }
    break;
  case 0x3a:
    if ((soundMask2 == 0) && ((soundMask & 0x1c) != 0)) {
      g_SoundEffectsEnabled = (uint)(g_SoundEffectsEnabled == 0);
      if (g_SoundEffectsEnabled == 0) {
        DisableSoundEffectsPlayback();
        InitAudioLine();
      }
      else {
        EnableSoundEffectsPlayback();
      }
    }
    break;
  case 0x3b:
    dataCursor2 = (undefined **)(((int)g_MasterVolumePercent / 10) * 10);
    if (soundMask2 == 0) {
      if ((soundMask & 4) != 0) {
        dataCursor2 = (undefined **)((int)dataCursor2 + -10);
      }
      if ((soundMask & 8) != 0) {
        dataCursor2 = (undefined **)((int)dataCursor2 + 10);
      }
    }
    if ((int)dataCursor2 < 10) {
      dataCursor2 = (undefined **)0xa;
    }
    else if (100 < (int)dataCursor2) {
      dataCursor2 = (undefined **)0x64;
    }
    if (dataCursor2 != g_MasterVolumePercent) {
      g_MasterVolumePercent = dataCursor2;
      SetCdAudioAndWin9xAuxVolumePercent(dataCursor2);
    }
    break;
  case 0x3c:
    if ((soundMask2 == 0) && ((soundMask & 0x1c) != 0)) {
      g_MusicEnabled = (uint)(g_MusicEnabled == 0);
      if (g_MusicEnabled == 0) {
        UpdateMciPlaybackStateIfNeeded();
      }
      else {
        ResumeBackgroundMusicIfSoundOptionsChanged();
      }
    }
    break;
  case 0x57:
    if ((soundMask2 == 0) && ((soundMask & 0x10) != 0)) {
      g_SoundOptionsMenuState = 0x57;
    }
  }
switchD_0049ff68_caseD_3d:
  if (g_SoundOptionsMenuEntryTable != (undefined *)0x0) {
    dataCursor2 = &g_SoundOptionsMenuEntryTable;
    do {
      switch(*(undefined2 *)(dataCursor2 + 1)) {
      case 0x38:
        menuIndex = IsEaxSoundAvailable();
        soundMask = g_LegacyAudioModeEnabled;
        if (menuIndex == 0) goto LAB_004a0140;
LAB_004a0135:
        if (soundMask == 0) goto LAB_004a0163;
        dataCursor = (undefined **)&DAT_005175c4;
        break;
      case 0x39:
        stringCursor = s__ld___005175c8;
        dataCursor = g_AuxVolumePercent;
        goto LAB_004a016e;
      case 0x3a:
        menuIndex = IsDirectSoundAvailable();
        soundMask = g_SoundEffectsEnabled;
        if (menuIndex != 0) goto LAB_004a0135;
LAB_004a0140:
        dataCursor = (undefined **)s_NOT_AVAILABLE_005175b4;
        break;
      case 0x3b:
        stringCursor = s__ld___005175c8;
        dataCursor = g_MasterVolumePercent;
        goto LAB_004a016e;
      case 0x3c:
        dataCursor = (undefined **)&DAT_005175c4;
        if (g_MusicEnabled == 0) {
LAB_004a0163:
          dataCursor = &PTR_LAB_005175b0;
        }
        break;
      default:
        goto switchD_004a0102_default;
      }
      stringCursor = &DAT_00515c68;
LAB_004a016e:
      LoadSFX(&DAT_00723d38,stringCursor,dataCursor);
      SetOptionsMenuEntryValueText(dataCursor2,&DAT_00723d38);
switchD_004a0102_default:
      dataCursor = dataCursor2 + 2;
      dataCursor2 = dataCursor2 + 2;
    } while (*dataCursor != (undefined *)0x0);
  }
  DrawOptionsMenu(&g_SoundOptionsMenuEntryTable,g_SoundOptionsMenuCursor);
  return g_SoundOptionsMenuState != 0;
}

