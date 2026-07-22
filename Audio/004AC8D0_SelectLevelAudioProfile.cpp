#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC8D0
// Label: SelectLevelAudioProfile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SelectLevelAudioProfile(uint soundId)

{
  undefined *bufferCursor;
  undefined *bufferCursor2;
  undefined4 soundMask;
  
  g_CurrentLevelAudioProfileId = soundId & 0x7fffffff;
  bufferCursor2 = (undefined *)0x0;
  switch(g_CurrentLevelAudioProfileId) {
  case 1:
    bufferCursor2 = &DAT_005179fc;
    break;
  case 2:
    bufferCursor2 = &DAT_00517b20;
    break;
  case 3:
    bufferCursor2 = &DAT_00517c58;
    break;
  case 4:
    bufferCursor2 = &DAT_00517d6c;
    break;
  case 5:
    bufferCursor2 = &DAT_00517e18;
    break;
  case 6:
    bufferCursor2 = &DAT_00517f58;
    break;
  case 7:
    bufferCursor2 = &DAT_00518088;
    break;
  case 8:
    bufferCursor2 = &DAT_00518138;
    break;
  case 9:
    bufferCursor2 = &DAT_0051825c;
    break;
  case 10:
    bufferCursor2 = &DAT_005183a4;
    break;
  case 0xb:
    bufferCursor2 = &DAT_00518580;
    break;
  case 0xc:
    bufferCursor2 = &DAT_00518678;
    break;
  case 0xd:
    bufferCursor2 = &DAT_005187b8;
    break;
  case 0xe:
    bufferCursor2 = &DAT_005188a0;
    break;
  case 0xf:
    bufferCursor2 = &DAT_005189b0;
    break;
  case 0x10:
    bufferCursor2 = &DAT_00518a98;
    break;
  case 0x12:
    bufferCursor2 = &DAT_005184e4;
    break;
  case 0x13:
    bufferCursor2 = &DAT_00518c54;
    break;
  case 0x14:
    bufferCursor2 = &DAT_00518b60;
    break;
  case 0x16:
    bufferCursor2 = &DAT_00518d38;
  }
  if (-1 < (int)soundId) {
    if (((g_CurrentLevelAudioProfileId == 0x16) && (-1 < g_SelectedLevelIndex)) &&
       ((short)g_LevelTransitionRequestFlags == -0x7fff)) {
      soundMask = 1;
    }
    else {
      soundMask = 0;
    }
    SelectBackgroundMusicTrackForLevel(soundMask);
  }
  bufferCursor = g_CurrentLevelSoundIdList;
  if (bufferCursor2 != g_CurrentLevelSoundIdList) {
    if (bufferCursor2 != (undefined *)0x0) {
      MarkSoundIdListPersistent(bufferCursor2);
    }
    if (g_CurrentLevelSoundIdList != (undefined *)0x0) {
      ReleaseSoundIdList(g_CurrentLevelSoundIdList);
    }
    bufferCursor = bufferCursor2;
    if (bufferCursor2 != (undefined *)0x0) {
      LoadSoundIdListAndSetDefaultVolume(bufferCursor2);
      ClearSoundIdListPersistent(bufferCursor2);
    }
  }
  g_CurrentLevelSoundIdList = bufferCursor;
  return;
}

