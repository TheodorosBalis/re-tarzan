#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B2F0
// Label: ProcessGameLogic
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessGameLogic(void)

{
  int value;
  int value2;
  DWORD dwMilliseconds;
  
  if ((bGameHasStarted & 1) == 0) {
    bGameHasStarted = bGameHasStarted | 1;
    GameTicks = GetTimeTicks();
  }
  value = VerifyGraphicsMode();
  if ((value == 0) && (IsDisplayOptionSupported == 0)) {
    SetFrameClearColor(0);
  }
  ResetRenderPacketCount();
  CGame::Process();
  DoNothing4(PrevFrameSleepMs,LoopCounter);
  RasterizeQueuedPacketsToFrameBuffer();
  ShowFrameAndUpdateAppTime();
  LoopCounter = 0;
  PrevFrameSleepMs = 0;
  bIsFrameRendered = 1;
  value = 0;
  do {
    value2 = GetTimeTicks();
    value2 = value2 - GameTicks;
    if (value2 < 40000) break;
    CGame::Process();
    GameTicks = GameTicks + 0x8235;
    value = value + 1;
    LoopCounter = LoopCounter + 1;
  } while (value < 3);
  dwMilliseconds = -((value2 + -0x8235) / 1000) - 1;
  bIsFrameRendered = 0;
  if (1 < (int)dwMilliseconds) {
    if (0x21 < (int)dwMilliseconds) {
      dwMilliseconds = 0x21;
    }
    PrevFrameSleepMs = PrevFrameSleepMs + dwMilliseconds;
    Sleep(dwMilliseconds);
  }
  GameTicks = GetTimeTicks();
  return;
}

