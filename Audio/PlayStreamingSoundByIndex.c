// Address: 0x004AC650

void PlayStreamingSoundByIndex(int param_1)

{
  InitAudioLine();
  LoadAndPlayAudioLineById(param_1 + -0x8000,(g_AuxVolumePercent * 0x3c) / 100);
  return;
}


