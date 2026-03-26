// Address: 0x004AAFE0

void ProcessLevelLogo(int param_1)

{
  DWORD DVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  
  if (param_1 != 0) {
    CaptureKInputsInBuffer();
    GetAppTime_FillGraphicsBuffer();
    unused1(0);
    LoadingScreen(*(undefined4 *)(param_1 + 8));
    iVar3 = 0;
    do {
      UpdateLevelLogoFade(iVar3,0x1e);
      iVar3 = iVar3 + 0xf;
    } while (iVar3 < 0x100);
    DVar1 = timeGetTime();
    SelectLevelAudioProfile((int)g_LevelTransitionContext._2_1_ | 0x80000000);
    iVar3 = ScanForInputs();
    while ((iVar3 == 0 &&
           ((iVar3 = HasAudioLineBuffer(), iVar3 != 0 ||
            (DVar2 = timeGetTime(), DVar2 < DVar1 + 4000))))) {
      UpdateLevelLogoFade(0xff,0x1e);
      iVar3 = ScanForInputs();
    }
    uVar4 = 0xff;
    do {
      UpdateLevelLogoFade(uVar4,0x1e);
      uVar4 = uVar4 - 0xf;
    } while (uVar4 < 0x80000000);
    CaptureKInputsInBuffer();
  }
  return;
}


