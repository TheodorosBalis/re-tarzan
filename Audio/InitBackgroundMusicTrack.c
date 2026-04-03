// Address: 0x00494280

void InitBackgroundMusicTrack(int param_1)

{
  int iVar1;
  
  if ((param_1 == DAT_0053a310) && (iVar1 = IsBackgroundMusicPlaying(), iVar1 != 0)) {
    return;
  }
  ResetBackgroundMusicPlaybackState();
  if (((0 < param_1) && (iVar1 = LoadECMFilesAndInit(), iVar1 != 0)) &&
     (DAT_0053a314 = GetBackgroundMusicTrackLengthSeconds(param_1), DAT_0053a314 != 0)) {
    PlayEcmTrackFromSecond(param_1,0);
  }
  return;
}


