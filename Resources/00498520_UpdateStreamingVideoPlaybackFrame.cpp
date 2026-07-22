#include "tarzan_ghidra_types.hpp"

// Address: 0x00498520
// Label: UpdateStreamingVideoPlaybackFrame
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint UpdateStreamingVideoPlaybackFrame(uint arg1,int arg2)

{
  DWORD apiResult;
  int value;
  int value2;
  uint value3;
  
  value2 = arg2;
  if (g_StreamingMovieFile == 0) {
    return 0;
  }
  if (g_StreamingMovieFrameIndex < g_StreamingMovieReadBuffer) {
    if (arg1 == 0) {
      return 0;
    }
    if (arg2 == 0) {
      return 0;
    }
    SynchronizeWithStreamedThread(1);
    if (g_StreamingVideoWaitingForAudioBuffer != 0) {
      g_StreamingVideoWaitingForAudioBuffer = 0;
      apiResult = timeGetTime();
      value = ConvertFpuTopToInt64();
      _g_StreamingVideoPlaybackState_Field0004 = apiResult - value;
      g_StreamingMovieFrameTimeMs = 0;
      g_StreamingVideoPlaybackState_Field0008 = 0;
    }
    if ((g_StreamingMovieFrameIndex % 0xf == 0) && (g_StreamingThreadHandle != (HANDLE)0x0)) {
      ResumeThread(g_StreamingThreadHandle);
    }
    if (g_StreamingWorkPending < (int)g_StreamingWorkMode) {
      g_StreamingVideoWaitingForAudioBuffer = g_StreamingVideoWaitingForAudioBuffer + 1;
      if (g_StreamingAudioBuffer != (int *)0x0) {
        (**(code **)(*g_StreamingAudioBuffer + 0x48))(g_StreamingAudioBuffer);
      }
      value = 0;
      if (g_StreamingWorkPending < (int)g_StreamingWorkMode) {
        do {
          if (4999 < value) goto LAB_004987d1;
          Sleep(10);
          value = value + 10;
        } while (g_StreamingWorkPending < (int)g_StreamingWorkMode);
        if (4999 < value) goto LAB_004987d1;
      }
    }
    if (g_StreamingThreadStopRequested == 0) {
      value3 = g_StreamingWorkMode & 0x80000003;
      if ((int)value3 < 0) {
        value3 = (value3 - 1 | 0xfffffffc) + 1;
      }
      value2 = DecodeMpcCutsceneFrameBlock
                        (&DAT_005561a0 + value3 * 0x5ab5c,g_StreamingMovieFrameIndex % 0xf,value2,
                         arg1);
      if (value2 != 0) {
        return 0;
      }
      apiResult = timeGetTime();
      apiResult = (g_StreamingMovieFrameTimeMs - apiResult) - 1;
      if (0 < (int)apiResult) {
        Sleep(apiResult);
      }
      if ((g_StreamingAudioBuffer != (int *)0x0) &&
         ((**(code **)(*g_StreamingAudioBuffer + 0x24))(g_StreamingAudioBuffer,&arg1),
         (arg1 & 1) == 0)) {
        (**(code **)(*g_StreamingAudioBuffer + 0x3c))
                  (g_StreamingAudioBuffer,g_StreamingAudioBufferByteSize);
        (**(code **)(*g_StreamingAudioBuffer + 0x34))
                  (g_StreamingAudioBuffer,(g_StreamingMovieFrameIndex * 0xb7c) % 0x2b110);
        (**(code **)(*g_StreamingAudioBuffer + 0x30))(g_StreamingAudioBuffer,0,0,1);
      }
      if (g_StreamingMovieFirstFramePending != 0) {
        _g_StreamingVideoPlaybackState_Field0004 = timeGetTime();
        g_StreamingMovieFirstFramePending = 0;
      }
      value3 = g_StreamingMovieFrameIndex;
      value2 = ConvertFpuTopToInt64();
      g_StreamingMovieFrameTimeMs = value2 + _g_StreamingVideoPlaybackState_Field0004;
      if ((((g_StreamingVideoPlaybackState_Field0008 == 0) &&
           (apiResult = timeGetTime(), value3 = g_StreamingMovieFrameIndex,
           g_StreamingMovieFrameTimeMs <= apiResult)) && (g_StreamingMovieFrameIndex != 0)) &&
         (g_StreamingMovieFrameIndex != g_StreamingMovieReadBuffer - 1)) {
        g_StreamingVideoPlaybackState_Field0008 = 1;
      }
      else {
        g_StreamingVideoPlaybackState_Field0008 = 0;
      }
      value3 = value3 + 1;
      g_StreamingMovieFrameIndex = value3;
      g_StreamingWorkMode = value3 / 0xf;
      if (g_StreamingVideoPlaybackState_Field0008 != 0) {
        value3 = -value3;
      }
      return value3;
    }
  }
LAB_004987d1:
  ShutdownStreamingVideoPlayback();
  return 0;
}

