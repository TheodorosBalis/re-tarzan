#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC210
// Label: LoadAndHandleMovie
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int LoadAndHandleMovie(undefined4 arg1,undefined4 arg2)

{
  int value;
  undefined4 value4;
  int value2;
  int value3;
  undefined4 scratchBuffer;
  undefined4 scratchBuffer4;
  undefined4 scratchBuffer3;
  undefined4 scratchBuffer2;
  
  scratchBuffer2 = 0;
  scratchBuffer3 = 0;
  scratchBuffer4 = 0;
  scratchBuffer = 0;
  value3 = 0;
  InitAudioLine();
  RasterizeQueuedPacketsToFrameBuffer();
  StopSoundChannelsAllowedWhenSoundEffectsMuted();
  ResetBackgroundMusicPlaybackState();
  CaptureKInputsInBuffer();
  value = IsGamePaused();
  if ((value == 0) && (value = GetAndLoadBlankECMfile(arg1), value != 0)) {
    if (g_SoundEffectsEnabled == 0) {
      value4 = 0;
    }
    else {
      value4 = GetDirectSoundInterface();
    }
    SetStreamedThreadWorkOnFile(value,value4,(g_AuxVolumePercent * 0x5c) / 100,0);
    value = HandleTheStreamedThread();
    while (((value != 0 && (value3 = CaptureInputsInCutscene(arg2), value3 == 0)) &&
           ((value2 = CurrentGraphicsMode(), value2 != 5 || (IsDisplayOptionSupported != 0))))) {
      if (-1 < value) {
        value = LockCurrentFrameBuffer(1,&scratchBuffer2,&scratchBuffer3,&scratchBuffer4,&scratchBuffer);
        if (value != 0) {
          ZeroHugeDynamicBuffer(scratchBuffer2,scratchBuffer3,scratchBuffer4,scratchBuffer);
          UnlockCurrentFrameBuffer();
          ShowFrameOnScreen();
        }
        DoNothing2();
        WinMessageLoop();
      }
      value = HandleTheStreamedThread();
    }
    StopAndClearActiveStreamedMovieWork();
  }
  CaptureKInputsInBuffer();
  return -(uint)(value3 != 0);
}

