// Address: 0x0049B2F0

void ProcessGameLogic(void)

{
  int iVar1;
  int iVar2;
  DWORD dwMilliseconds;
  
  if ((bGameHasStarted & 1) == 0) {
    bGameHasStarted = bGameHasStarted | 1;
    GameTicks = GetTimeTicks();
  }
  iVar1 = VerifyGraphicsMode();
  if ((iVar1 == 0) && (IsDisplayOptionSupported == 0)) {
    unused1(0);
  }
  ResetRenderPacketCount();
  CGame__Process();
  DoNothing4(PrevFrameSleepMs,LoopCounter);
  GetAppTime_FillGraphicsBuffer();
  ShowFrameAndUpdateAppTime();
  LoopCounter = 0;
  PrevFrameSleepMs = 0;
  bIsFrameRendered = 1;
  iVar1 = 0;
  do {
    iVar2 = GetTimeTicks();
    iVar2 = iVar2 - GameTicks;
    if (iVar2 < 40000) break;
    CGame__Process();
    GameTicks = GameTicks + 0x8235;
    iVar1 = iVar1 + 1;
    LoopCounter = LoopCounter + 1;
  } while (iVar1 < 3);
  dwMilliseconds = -((iVar2 + -0x8235) / 1000) - 1;
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


