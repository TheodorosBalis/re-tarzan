#include "tarzan_ghidra_types.hpp"

// Address: 0x004942D0
// Label: GetBackgroundMusicTrackLengthSeconds
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int GetBackgroundMusicTrackLengthSeconds(undefined4 trackId)

{
  MCIERROR mciResult;
  undefined1 localState3 [4];
  undefined4 localState2;
  undefined1 localState [4];
  uint localState6;
  undefined4 localState5;
  undefined4 localState4;
  
  localState5 = 0x4001;
  localState4 = trackId;
  mciResult = mciSendCommandA(g_BackgroundMusicMciDeviceId,0x814,0x110,(DWORD_PTR)localState);
  if ((mciResult == 0) && (localState6 == 0x440)) {
    localState2 = 2;
    mciSendCommandA(g_BackgroundMusicMciDeviceId,0x80d,0x400,(DWORD_PTR)localState3);
    localState5 = 1;
    localState4 = trackId;
    mciResult = mciSendCommandA(g_BackgroundMusicMciDeviceId,0x814,0x110,(DWORD_PTR)localState);
    if (mciResult == 0) {
      return (localState6 >> 8 & 0xff) + (localState6 & 0xff) * 0x3c;
    }
  }
  return 0;
}

