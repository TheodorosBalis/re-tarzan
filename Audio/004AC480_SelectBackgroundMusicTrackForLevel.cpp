#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC480
// Label: SelectBackgroundMusicTrackForLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SelectBackgroundMusicTrackForLevel(int trackId)

{
  switch(g_CurrentLevelAudioProfileId) {
  case 1:
    g_CurrentBackgroundMusicTrackId = 3;
    InitBackgroundMusicTrack(3);
    return;
  case 2:
    g_CurrentBackgroundMusicTrackId = 4;
    InitBackgroundMusicTrack(4);
    return;
  case 3:
    g_CurrentBackgroundMusicTrackId = 5;
    InitBackgroundMusicTrack(5);
    return;
  case 4:
    g_CurrentBackgroundMusicTrackId = 9;
    InitBackgroundMusicTrack(9);
    return;
  case 5:
    g_CurrentBackgroundMusicTrackId = 6;
    InitBackgroundMusicTrack(6);
    return;
  case 6:
    g_CurrentBackgroundMusicTrackId = 8 - (uint)(trackId != 0);
    InitBackgroundMusicTrack(g_CurrentBackgroundMusicTrackId);
    return;
  case 7:
    g_CurrentBackgroundMusicTrackId = (trackId != 0) + 9;
    InitBackgroundMusicTrack(g_CurrentBackgroundMusicTrackId);
    return;
  case 8:
    g_CurrentBackgroundMusicTrackId = 0xb;
    InitBackgroundMusicTrack(0xb);
    return;
  case 9:
    g_CurrentBackgroundMusicTrackId = 0xc;
    InitBackgroundMusicTrack(0xc);
    return;
  case 10:
    g_CurrentBackgroundMusicTrackId = 0xd;
    InitBackgroundMusicTrack(0xd);
    return;
  case 0xb:
    g_CurrentBackgroundMusicTrackId = 0xf;
    InitBackgroundMusicTrack(0xf);
    return;
  case 0xc:
    g_CurrentBackgroundMusicTrackId = 0x10;
    InitBackgroundMusicTrack(0x10);
    return;
  case 0xd:
    g_CurrentBackgroundMusicTrackId = 0x11;
    InitBackgroundMusicTrack(0x11);
    return;
  case 0xe:
    g_CurrentBackgroundMusicTrackId = 0x12;
    InitBackgroundMusicTrack(0x12);
    return;
  case 0xf:
  case 0x15:
    g_CurrentBackgroundMusicTrackId = 0x13;
    InitBackgroundMusicTrack(0x13);
    return;
  case 0x10:
    g_CurrentBackgroundMusicTrackId = 0x14;
    InitBackgroundMusicTrack(0x14);
    return;
  default:
    g_CurrentBackgroundMusicTrackId = (-(uint)(trackId != 0) & 0xffffffed) + 0x15;
    InitBackgroundMusicTrack(g_CurrentBackgroundMusicTrackId);
    return;
  case 0x12:
  case 0x13:
  case 0x14:
    g_CurrentBackgroundMusicTrackId = 0xe;
    InitBackgroundMusicTrack(0xe);
    return;
  }
}

