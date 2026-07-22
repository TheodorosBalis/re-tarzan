#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8E70
// Label: PauseAudioLinePlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PauseAudioLinePlayback(void)

{
  DWORD mciResult;
  
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick == 0)) {
    mciResult = timeGetTime();
    g_AudioLinePauseStartTick = mciResult | 1;
    if (g_AudioLineSoundBuffer != (int *)0x0) {
      (**(code **)(*g_AudioLineSoundBuffer + 0x48))(g_AudioLineSoundBuffer);
    }
  }
  return;
}

