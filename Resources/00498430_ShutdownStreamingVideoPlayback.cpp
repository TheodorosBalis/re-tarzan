#include "tarzan_ghidra_types.hpp"

// Address: 0x00498430
// Label: ShutdownStreamingVideoPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ShutdownStreamingVideoPlayback(void)

{
  int value;
  undefined4 *bufferCursor;
  
  if (g_StreamingAudioBuffer != (int *)0x0) {
    (**(code **)(*g_StreamingAudioBuffer + 0x48))(g_StreamingAudioBuffer);
  }
  if (g_StreamingThreadHandle != (HANDLE)0x0) {
    for (value = 0; (g_StreamingThreadStartupPending != 0 && (value < 5000)); value = value + 100) {
      Sleep(100);
    }
    Sleep(100);
    TerminateThread(g_StreamingThreadHandle,0);
    CloseHandle(g_StreamingThreadHandle);
    g_StreamingThreadHandle = (HANDLE)0x0;
  }
  if (g_StreamingAudioBuffer != (int *)0x0) {
    (**(code **)(*g_StreamingAudioBuffer + 8))(g_StreamingAudioBuffer);
    g_StreamingAudioBuffer = (int *)0x0;
  }
  bufferCursor = &g_StreamingVideoPlaybackState_Field0010;
  for (value = 0x386; value != 0; value = value + -1) {
    *bufferCursor = 0;
    bufferCursor = bufferCursor + 1;
  }
  SynchronizeWithStreamedThread(0);
  if (g_StreamingMovieFile != 0) {
    fclose(g_StreamingMovieFile);
  }
  g_StreamingMovieFile = 0;
  return;
}

