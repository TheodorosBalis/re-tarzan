#include "tarzan_ghidra_types.hpp"

// Address: 0x004AB0A0
// Label: UpdateLevelLogoFade
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateLevelLogoFade(uint arg1,uint arg2)

{
  DWORD apiResult;
  DWORD apiResult2;
  uint dwMilliseconds;
  
  apiResult = timeGetTime();
  WinMessageLoop();
  ManageAudioStream();
  UpdateBackgroundMusic();
  DoNothing2();
  ProcessPendingChunkStream();
  if (0xff < (int)arg1) {
    arg1 = 0xff;
  }
  arg1 = ((arg1 | 0xffffff00) << 8 | arg1) << 8 | arg1;
  ResetRenderPacketCount();
  DrawTexturedQuad(0,0,0xff,0x1e0,0,0,0xff,0xf0,0xe,arg1,0,0,0,1);
  DrawTexturedQuad(0xff,0,0xff,0x1e0,0,0,0xff,0xf0,0xd,arg1,0,0,0,1);
  DrawTexturedQuad(0x1fe,0,0x82,0x1e0,0,0,0x82,0xf0,0xc,arg1,0,0,0,1);
  RasterizeQueuedPacketsToFrameBuffer();
  ShowFrameAndUpdateAppTime();
  apiResult2 = timeGetTime();
  dwMilliseconds = apiResult + (arg2 - apiResult2);
  if (arg2 < dwMilliseconds) {
    dwMilliseconds = arg2;
  }
  if (dwMilliseconds != 0) {
    Sleep(dwMilliseconds);
  }
  return;
}

