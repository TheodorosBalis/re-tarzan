#include "tarzan_ghidra_types.hpp"

// Address: 0x004984F0
// Label: StopAndSynchronizeStreamedWork
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopAndSynchronizeStreamedWork(void)

{
  g_StreamingVideoWaitingForAudioBuffer = g_StreamingVideoWaitingForAudioBuffer + 1;
  if (g_StreamingAudioBuffer != (int *)0x0) {
    (**(code **)(*g_StreamingAudioBuffer + 0x48))(g_StreamingAudioBuffer);
  }
  SynchronizeWithStreamedThread(0);
  return;
}

