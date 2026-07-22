#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8EA0
// Label: ResumeAudioLinePlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResumeAudioLinePlayback(void)

{
  DWORD mciResult;
  int value;
  
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick != 0)) {
    (**(code **)(*g_AudioLineSoundBuffer + 0x30))(g_AudioLineSoundBuffer,0,0,1);
    mciResult = timeGetTime();
    value = mciResult - g_AudioLinePauseStartTick;
    g_AudioLinePauseStartTick = 0;
    g_AudioLineNextRefillTick = g_AudioLineNextRefillTick + value;
  }
  return;
}

