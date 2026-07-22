#include "tarzan_ghidra_types.hpp"

// Address: 0x00494380
// Label: PlayBackgroundMusicTrackFromSecond
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PlayBackgroundMusicTrackFromSecond(uint trackId,uint startSecond)

{
  MCIERROR mciResult2;
  DWORD mciResult;
  undefined1 localState3 [4];
  uint localState2;
  uint localState;
  undefined1 localState5 [4];
  undefined4 localState4;
  
  if ((int)startSecond < 0) {
    startSecond = 0;
  }
  startSecond = startSecond % g_CurrentBackgroundMusicTrackLengthSeconds;
  if (g_BackgroundMusicMusicDisabledPauseTickMs == 0) {
    localState4 = 10;
    mciSendCommandA(g_BackgroundMusicMciDeviceId,0x80d,0x400,(DWORD_PTR)localState5);
    localState2 = ((uint)(byte)((longlong)(int)startSecond % 0x3c) << 8 | (int)startSecond / 0x3c & 0xffffU) <<
               8 | trackId & 0xff;
    localState = ((uint)(byte)((ulonglong)g_CurrentBackgroundMusicTrackLengthSeconds % 0x3c) << 8 |
               g_CurrentBackgroundMusicTrackLengthSeconds / 0x3c & 0xffff) << 8 | trackId & 0xff;
    mciResult2 = mciSendCommandA(g_BackgroundMusicMciDeviceId,0x806,0xc,(DWORD_PTR)localState3);
    g_BackgroundMusicMciIsPlaying = (uint)(mciResult2 == 0);
  }
  else {
    g_BackgroundMusicMciIsPlaying = 0;
  }
  g_CurrentBackgroundMusicTrack = trackId;
  mciResult = timeGetTime();
  g_BackgroundMusicTrackStartTickMs = mciResult + startSecond * -1000;
  return;
}

