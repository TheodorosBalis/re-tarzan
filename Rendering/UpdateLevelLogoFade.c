/* Address: 0x004AB0A0 */

void UpdateLevelLogoFade(uint param_1,uint param_2)

{
  DWORD DVar1;
  DWORD DVar2;
  uint dwMilliseconds;
  
  DVar1 = timeGetTime();
  WinMessageLoop();
  ProcessSoundEffectsInGameOrOptions();
  ProcessCutsceneIfNeeded();
  DoNothing2();
  CheckIfEfgFileNeedsLoading();
  if (0xff < (int)param_1) {
    param_1 = 0xff;
  }
  param_1 = ((param_1 | 0xffffff00) << 8 | param_1) << 8 | param_1;
  ResetTheRenderFrameInChunksCounter();
  SetFontBrightness(0,0,0xff,0x1e0,0,0,0xff,0xf0,0xe,param_1,0,0,0,1);
  SetFontBrightness(0xff,0,0xff,0x1e0,0,0,0xff,0xf0,0xd,param_1,0,0,0,1);
  SetFontBrightness(0x1fe,0,0x82,0x1e0,0,0,0x82,0xf0,0xc,param_1,0,0,0,1);
  GetAppTime_FillGraphicsBuffer();
  ShowFrameAndUpdateAppTime();
  DVar2 = timeGetTime();
  dwMilliseconds = DVar1 + (param_2 - DVar2);
  if (param_2 < dwMilliseconds) {
    dwMilliseconds = param_2;
  }
  if (dwMilliseconds != 0) {
    Sleep(dwMilliseconds);
  }
  return;
}

