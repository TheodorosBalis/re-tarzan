#include "tarzan_ghidra_types.hpp"

// Address: 0x004AAFE0
// Label: ProcessLevelLogo
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessLevelLogo(int arg1)

{
  DWORD apiResult;
  DWORD apiResult2;
  int value;
  uint value2;
  
  if (arg1 != 0) {
    CaptureKInputsInBuffer();
    RasterizeQueuedPacketsToFrameBuffer();
    SetFrameClearColor(0);
    LoadingScreen(*(undefined4 *)(arg1 + 8));
    value = 0;
    do {
      UpdateLevelLogoFade(value,0x1e);
      value = value + 0xf;
    } while (value < 0x100);
    apiResult = timeGetTime();
    SelectLevelAudioProfile((int)*( undefined1 *)((int)&g_LevelTransitionContext + 2) | 0x80000000);
    value = ScanForInputs();
    while ((value == 0 &&
           ((value = HasAudioLineBuffer(), value != 0 ||
            (apiResult2 = timeGetTime(), apiResult2 < apiResult + 4000))))) {
      UpdateLevelLogoFade(0xff,0x1e);
      value = ScanForInputs();
    }
    value2 = 0xff;
    do {
      UpdateLevelLogoFade(value2,0x1e);
      value2 = value2 - 0xf;
    } while (value2 < 0x80000000);
    CaptureKInputsInBuffer();
  }
  return;
}

