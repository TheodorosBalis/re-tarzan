// Address: 0x004A15C0

void InitLegacyAudioAndQueryMixerControls(void)

{
  InitLegacyAudioIfOldWindows();
  QueryMixerControlDetails(&DAT_007246a0,0x1005);
  QueryMixerControlDetails(&DAT_00724278,0x1008);
  return;
}


