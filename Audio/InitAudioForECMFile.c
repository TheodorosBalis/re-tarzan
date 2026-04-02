// Address: 0x00494280

void InitAudioForECMFile(int param_1)

{
  int iVar1;
  
  if ((param_1 == DAT_0053a310) && (iVar1 = IsCurrentEcmTrackPlaying(), iVar1 != 0)) {
    return;
  }
  ResetEcmAudioPlaybackState();
  if (((0 < param_1) && (iVar1 = LoadECMFilesAndInit(), iVar1 != 0)) &&
     (DAT_0053a314 = ReloadMciEcmAudio(param_1), DAT_0053a314 != 0)) {
    PlayEcmTrackFromSecond(param_1,0);
  }
  return;
}


