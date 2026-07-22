#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AEC0
// Label: SetupGraphicsAudioEfGandECMFiles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetupGraphicsAudioEfGandECMFiles(undefined4 windowHandle)

{
  InitHighResolutionTimer();
  JoystickScanAndCaptureInput();
  EnsureTarzanFSDLoaded();
  EnsureTarzanCFGLoaded();
  InitializeSoftwareRasterizerLookupTables();
  BuildBrightnessLookupTable(g_BrightnessPercent);
  InitializeGraphicsModeManager(windowHandle);
  SetPreferredGraphicsMode(g_CurrentDisplayModeIndex);
  InitAudioMixerVolumeControls();
  InitCdPlayerAndEMCFiles(windowHandle);
  SetCdAudioAndWin9xAuxVolumePercent(g_MasterVolumePercent);
  if (g_MusicEnabled == 0) {
    UpdateMciPlaybackStateIfNeeded();
  }
  InitDSound(windowHandle);
  SetWaveOutMixerVolumePercent(g_AuxVolumePercent);
  LegacyAudioCheck_DoNothing(-(g_LegacyAudioModeEnabled != 0) & 3);
  if (g_SoundEffectsEnabled == 0) {
    DisableSoundEffectsPlayback();
  }
  InitDefaultGraphicsLookupTable();
  LoadAndPatchMenuTextureAtlas();
  ResetProjectionState();
  RequestGraphicsModeChange(7);
  ApplyRequestedGraphicsModeWithFallback();
  return;
}

