#include "tarzan_ghidra_types.hpp"

// Address: 0x004A18E0
// Label: FadeOutMasterAndAuxVolume
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FadeOutMasterAndAuxVolume(void)

{
  DWORD apiResult;
  undefined4 value;
  DWORD apiResult2;
  undefined4 localState;
  
  localState = 100;
  do {
    apiResult = timeGetTime();
    value = ConvertFpuTopToInt64();
    SetCdAudioAndWin9xAuxVolumePercent(value);
    value = ConvertFpuTopToInt64();
    SetWaveOutMixerVolumePercent(value);
    apiResult2 = timeGetTime();
    apiResult = apiResult + (10 - apiResult2);
    if (0 < (int)apiResult) {
      Sleep(apiResult);
    }
    localState = localState + -2;
  } while (-1 < localState);
  SetCdAudioAndWin9xAuxVolumePercent(0);
  SetWaveOutMixerVolumePercent(0);
  return;
}

