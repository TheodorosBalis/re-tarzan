// Address: 0x004AC210

int LoadAndHandleMovie(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  iVar4 = 0;
  InitAudioLine();
  GetAppTime_FillGraphicsBuffer();
  FUN_004a8d20();
  ResetEcmAudioPlaybackState();
  CaptureKInputsInBuffer();
  iVar1 = IsGamePaused();
  if ((iVar1 == 0) && (iVar1 = GetAndLoadBlankECMfile(param_1), iVar1 != 0)) {
    if (g_SoundEffectsEnabled == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_004a8000();
    }
    SetStreamedThreadWorkOnFile(iVar1,uVar2,(g_AuxVolumePercent * 0x5c) / 100,0);
    iVar1 = HandleTheStreamedThread();
    while (((iVar1 != 0 && (iVar4 = CaptureInputsInCutscene(param_2), iVar4 == 0)) &&
           ((iVar3 = CurrentGraphicsMode(), iVar3 != 5 || (IsDisplayOptionSupported != 0))))) {
      if (-1 < iVar1) {
        iVar1 = LoadSoundOrUpdateGraphixBufferForCutscene(1,&local_4,&local_8,&local_c,&local_10);
        if (iVar1 != 0) {
          ZeroHugeDynamicBuffer(local_4,local_8,local_c,local_10);
          ConfirmGraphicsInitialised();
          ShowFrameOnScreen();
        }
        DoNothing2();
        WinMessageLoop();
      }
      iVar1 = HandleTheStreamedThread();
    }
    FUN_004a1a00();
  }
  CaptureKInputsInBuffer();
  return -(uint)(iVar4 != 0);
}


