#include "tarzan_ghidra_types.hpp"

// Address: 0x00498190
// Label: StreamedThreadEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StreamedThreadEntry(void)

{
  bool flagByte;
  uint value2;
  uint value3;
  int value;
  uint savedEsi;
  undefined4 *bufferCursor;
  undefined4 scratchBuffer2;
  uint scratchBuffer;
  undefined4 *scratchBuffer5;
  undefined4 scratchBuffer4;
  undefined4 scratchBuffer3;
  
  scratchBuffer3 = 0;
  flagByte = false;
  do {
    g_StreamingThreadStartupPending = 1;
    for (; (g_StreamingThreadStopRequested == 0 &&
           (g_StreamingWorkPending - g_StreamingWorkMode < 3));
        g_StreamingWorkPending = g_StreamingWorkPending + 1) {
      if (g_StreamingWorkPending < (int)(g_StreamingMovieReadBuffer / 0xf)) {
        if (((uint)(&g_StreamingVideoPlaybackState_Field001C)[g_StreamingWorkPending] < 0x5ab5d) &&
           (value = fread(&g_StreamedThreadLargeBufferState_Field0008,
                          (&g_StreamingVideoPlaybackState_Field001C)[g_StreamingWorkPending],1,
                          g_StreamingMovieFile), value == 1)) {
          value3 = g_StreamingWorkPending + 1U & 0x80000003;
          if ((int)value3 < 0) {
            value3 = (value3 - 1 | 0xfffffffc) + 1;
          }
          *(undefined4 *)(&g_StreamedThreadState_Field0008 + value3 * 0x5ab5c) =
               g_StreamedThreadLargeBufferState_Field0008;
          value3 = g_StreamingWorkPending + 1U & 0x80000003;
          if ((int)value3 < 0) {
            value3 = (value3 - 1 | 0xfffffffc) + 1;
          }
          value = DecodeStreamedEdlPayloadToBuffer(&DAT_006c0f10,&DAT_005561a0 + value3 * 0x5ab5c);
          if (value != 0x58044) {
            g_StreamingThreadStopRequested = -2;
          }
        }
        else {
          g_StreamingThreadStopRequested = -1;
        }
      }
      else {
        flagByte = true;
      }
      if ((g_StreamingThreadStopRequested == 0) && (g_StreamingAudioBuffer != (int *)0x0)) {
        scratchBuffer5 = (undefined4 *)0x0;
        scratchBuffer = 0;
        scratchBuffer2 = 0;
        scratchBuffer4 = 0;
        value3 = g_StreamingWorkPending + 1U & 0x80000003;
        if ((int)value3 < 0) {
          value3 = (value3 - 1 | 0xfffffffc) + 1;
        }
        value3 = value3 * 0xac44;
        value = (**(code **)(*g_StreamingAudioBuffer + 0x10))
                          (g_StreamingAudioBuffer,&scratchBuffer2,&scratchBuffer4);
        value2 = 0xffffffff;
        while ((((value == 0 && (value2 != savedEsi)) && (value3 <= savedEsi)) &&
               (savedEsi <= value3 + 0xac44))) {
          Sleep(5);
          value = (**(code **)(*g_StreamingAudioBuffer + 0x10))
                            (g_StreamingAudioBuffer,&stack0xffffffe0,&scratchBuffer2);
          value2 = savedEsi;
        }
        value = (**(code **)(*g_StreamingAudioBuffer + 0x2c))
                          (g_StreamingAudioBuffer,value3,0xac44,&stack0xffffffe8,&stack0xffffffe4,0,0
                           ,0);
        if (value == -0x7787ff6a) {
          (**(code **)(*g_StreamingAudioBuffer + 0x50))(g_StreamingAudioBuffer);
          (**(code **)(*g_StreamingAudioBuffer + 0x48))(g_StreamingAudioBuffer);
          (**(code **)(*g_StreamingAudioBuffer + 0x2c))
                    (g_StreamingAudioBuffer,0,0xac44,&scratchBuffer2,&stack0xffffffe8,0,0,0);
          flagByte = true;
        }
        if ((scratchBuffer5 != (undefined4 *)0x0) && (scratchBuffer != 0)) {
          if (flagByte) {
            bufferCursor = scratchBuffer5;
            for (value3 = scratchBuffer >> 2; value3 != 0; value3 = value3 - 1) {
              *bufferCursor = 0;
              bufferCursor = bufferCursor + 1;
            }
            for (value3 = scratchBuffer & 3; value3 != 0; value3 = value3 - 1) {
              *(undefined1 *)bufferCursor = 0;
              bufferCursor = (undefined4 *)((int)bufferCursor + 1);
            }
          }
          else {
            DecodeImaAdpcmNibblesToPcm(&DAT_006be3fc,scratchBuffer5,0xac44,&scratchBuffer3);
          }
          (**(code **)(*g_StreamingAudioBuffer + 0x4c))
                    (g_StreamingAudioBuffer,scratchBuffer5,scratchBuffer,0,0);
        }
        flagByte = false;
      }
    }
    g_StreamingThreadStartupPending = 0;
    if (g_StreamingThreadHandle != (HANDLE)0x0) {
      SuspendThread(g_StreamingThreadHandle);
    }
  } while( true );
}

