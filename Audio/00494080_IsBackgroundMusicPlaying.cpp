#include "tarzan_ghidra_types.hpp"

// Address: 0x00494080
// Label: IsBackgroundMusicPlaying
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool IsBackgroundMusicPlaying(void)

{
  MCIERROR mciResult;
  undefined4 localState;
  int localState4;
  undefined4 localState3;
  undefined4 localState2;
  
  localState4 = 0;
  localState = 0;
  localState2 = 0;
  localState3 = 4;
  mciResult = mciSendCommandA(g_BackgroundMusicMciDeviceId,0x814,0x102,(DWORD_PTR)&localState);
  if (mciResult != 0) {
    return false;
  }
  return localState4 == 0x20e;
}

