// Address: 0x0049AEC0

void SetupGraphicsAudioEfGandECMFiles(undefined4 param_1)

{
  InitHighResolutionTimer();
  JoystickScanAndCaptureInput();
  EnsureTarzanFSDLoaded();
  EnsureTarzanCFGLoaded();
  FillUnknownAndFloatTables();
  FillArrayOfNumbers255(g_BrightnessPercent);
  DetermineSystemGSXRequirementsAndUpdateFrame(param_1);
  SetCurrentBitMapSlot(g_CurrentDisplayModeIndex);
  InitLegacyAudioAndQueryMixerControls();
  InitCdPlayerAndEMCFiles(param_1);
  SetVolumeForAllDevices(g_MasterVolumePercent);
  if (g_MusicEnabled == 0) {
    UpdateMciPlaybackStateIfNeeded();
  }
  InitDSound(param_1);
  SetAuxVolumePercent(g_AuxVolumePercent);
  LegacyAudioCheck_DoNothing(-(g_LegacyAudioModeEnabled != 0) & 3);
  if (g_SoundEffectsEnabled == 0) {
    OnlyonLegacyAudio();
  }
  InitDefaultGraphicsLookupTable();
  LoadAndPatchMenuTextureAtlas();
  ZeroSomeUnknownBuffer();
  SetActiveBitmapSlot(7);
  RunLegacyHandlersOrUpdateFrame();
  return;
}


