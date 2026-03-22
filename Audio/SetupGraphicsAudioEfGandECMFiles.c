/* Address: 0x0049AEC0 */

void SetupGraphicsAudioEfGandECMFiles(undefined4 param_1)

{
  InitHighResolutionTimer();
  JoystickScanAndCaptureInput();
  EnsureTarzanFSDLoaded();
  EnsureTarzanCFGLoaded();
  FillUnknownAndFloatTables();
  FillArrayOfNumbers255(DAT_0053a354);
  DetermineSystemGSXRequirementsAndUpdateFrame(param_1);
  SetCurrentBitMapSlot(DAT_0053a350);
  InitLegacyAudioAndQueryMixerControls();
  InitCdPlayerAndEMCFiles(param_1);
  SetVolumeForAllDevices(DAT_0053a340);
  if (DAT_0053a33c == 0) {
    UpdateMciPlaybackStateIfNeeded();
  }
  InitDSound(param_1);
  SetAuxVolumePercent(DAT_0053a348);
  LegacyAudioCheck_DoNothing(-(DAT_0053a34c != 0) & 3);
  if (DAT_0053a344 == 0) {
    OnlyonLegacyAudio();
  }
  InitDefaultGraphicsLookupTable();
  LoadAndProcessMenu_Efg();
  ZeroSomeUnknownBuffer();
  SetActiveBitmapSlot(7);
  RunLegacyHandlersOrUpdateFrame();
  return;
}

