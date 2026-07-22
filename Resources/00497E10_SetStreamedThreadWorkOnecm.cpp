#include "tarzan_ghidra_types.hpp"

// Address: 0x00497E10
// Label: SetStreamedThreadWorkOnecm
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint SetStreamedThreadWorkOnecm(undefined4 arg1,int *arg2,undefined4 arg3,uint arg4)

{
  int value;
  int value2;
  int value3;
  int *intCursor;
  undefined4 scratchBuffer6;
  undefined4 scratchBuffer5;
  undefined4 scratchBuffer4;
  undefined4 scratchBuffer3;
  undefined4 scratchBuffer2;
  undefined4 scratchBuffer;
  undefined4 scratchBuffer9;
  undefined4 scratchBuffer8;
  undefined4 *scratchBuffer7;
  
  ShutdownStreamingVideoPlayback();
  g_StreamingThreadStopRequested = 0;
  if ((int)arg4 < 1) {
    arg4 = 1;
  }
  g_StreamingMovieFile = fopen(arg1,&s_FileModeReadBinary);
  if (((g_StreamingMovieFile != 0) &&
      (value2 = fread(&g_StreamingVideoPlaybackState_Field0010,0xe18,1,g_StreamingMovieFile),
      value2 == 1)) && ((*(byte *)(g_StreamingMovieFile + 0xc) & 0x20) == 0)) {
    if (g_StreamingMovieReadBuffer % 0xf == 0) {
      g_StreamingMovieReadBuffer = g_StreamingMovieReadBuffer - 1;
    }
    if ((g_StreamingVideoPlaybackState_Field0010 == 0x24d4345) &&
       (arg4 < g_StreamingMovieReadBuffer)) {
      scratchBuffer8 = 0;
      scratchBuffer7 = &scratchBuffer6;
      _g_StreamingDirectSound = arg2;
      scratchBuffer6 = 0x10001;
      scratchBuffer5 = 0x5622;
      scratchBuffer3 = 0x100002;
      scratchBuffer4 = 0xac44;
      scratchBuffer2 = 0x14;
      scratchBuffer = 0x10090;
      scratchBuffer9 = 0x2b110;
      g_StreamingAudioBuffer = (int *)0x0;
      if ((arg2 != (int *)0x0) &&
         ((**(code **)(*arg2 + 0xc))(arg2,&scratchBuffer2,&g_StreamingAudioBuffer,0),
         intCursor = g_StreamingAudioBuffer, g_StreamingAudioBuffer != (int *)0x0)) {
        g_StreamingAudioBufferByteSize = ConvertFpuTopToInt64();
        (**(code **)(*intCursor + 0x34))(intCursor,0);
        (**(code **)(*g_StreamingAudioBuffer + 0x44))(g_StreamingAudioBuffer,0);
        (**(code **)(*g_StreamingAudioBuffer + 0x40))(g_StreamingAudioBuffer,0);
        (**(code **)(*g_StreamingAudioBuffer + 0x3c))
                  (g_StreamingAudioBuffer,g_StreamingAudioBufferByteSize);
        SetAudioLineVolumePercent(g_StreamingAudioBuffer,0);
      }
      g_StreamingMovieFrameIndex = arg4 - 1;
      value2 = (int)(arg4 - 1) / 0xf;
      if ((value2 != 0) && (value3 = 0, 0 < value2)) {
        intCursor = &DAT_00718f68;
        do {
          value = *intCursor;
          intCursor = intCursor + 1;
          value3 = value3 + value;
          value2 = value2 + -1;
        } while (value2 != 0);
        if (0 < value3) {
          fseek(g_StreamingMovieFile,value3,1);
        }
      }
      g_StreamingVideoWaitingForAudioBuffer = 0;
      g_StreamingMovieFirstFramePending = 1;
      g_StreamingWorkPending = 0xffffffff;
      g_StreamingWorkMode = 0;
      g_StreamingThreadStartupPending = 1;
      g_StreamingThreadHandle =
           CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,StreamedThreadEntry,(LPVOID)0x0,0,
                        (LPDWORD)&g_StreamingThreadId);
      if (g_StreamingThreadHandle == (HANDLE)0x0) {
        g_StreamingThreadStartupPending = 0;
        ShutdownStreamingVideoPlayback();
        return 0;
      }
      SynchronizeWithStreamedThread(1);
      value2 = 0;
      if (g_StreamingThreadStartupPending != 0) {
        do {
          if (4999 < value2) goto LAB_004980c1;
          Sleep(100);
          value2 = value2 + 100;
        } while (g_StreamingThreadStartupPending != 0);
        if (4999 < value2) {
LAB_004980c1:
          ShutdownStreamingVideoPlayback();
          return 0;
        }
      }
      return g_StreamingMovieReadBuffer;
    }
  }
  ShutdownStreamingVideoPlayback();
  return 0;
}

