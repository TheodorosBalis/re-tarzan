#include "tarzan_ghidra_types.hpp"

// Address: 0x0049AF80
// Label: ShutdownGameRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShutdownGameRuntime(void)

{
  PreShutdownNoOp();
  SampleAppTimeBeforeShutdown();
  ForceSoftwareGraphicsMode();
  ShutdownGraphicsModeManager_Stub();
  ShutdownTarzanCFGAndSave();
  ReleaseInputDevices_Stub();
  ReleaseGraphicsModeResources_Stub();
  FadeOutMasterAndAuxVolume();
  FreeDSound();
  StopMciCdAudioAndResetPlayback();
  RestoreStartupMixerVolumeLevels();
  ReleaseKeyboardInputState_Stub();
  ReleaseTarzanFsdArchive();
  EndHighResolutionTimerPeriod();
  return;
}

