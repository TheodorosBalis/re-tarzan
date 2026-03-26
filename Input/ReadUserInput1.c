// Address: 0x004AEA70

void ReadUserInput1(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [32];
  
  if (g_MainWindowActivationState != 2) {
    return;
  }
  if (DAT_00724ed0 == 0) {
    iVar1 = IsGamePaused();
    if ((iVar1 == 0) && (iVar1 = GetUserInput_stub(0x1b), iVar1 != 0)) {
      iVar1 = ShouldBeInMainMenu();
      if (iVar1 == 0) {
        uVar5 = 8;
      }
      else {
        uVar5 = 0xd;
      }
      SetOptionsMenu(uVar5);
    }
    iVar1 = GetUserInput_stub(0x70);
    if (iVar1 != 0) {
      SetOptionsMenu(1);
    }
    iVar1 = GetUserInput_stub(0x71);
    if (iVar1 != 0) {
      SetOptionsMenu(2);
    }
    iVar1 = GetUserInput_stub(0x73);
    if (iVar1 != 0) {
      SetOptionsMenu(8);
    }
    iVar1 = GetUserInput_stub(0x72);
    if (iVar1 != 0) {
      if ((((DAT_00c46c5c < 0) && (iVar1 = FUN_004abd30(), iVar1 != 0)) &&
          (iVar1 = IsControlBindingPressed(0x11), iVar1 != 0)) &&
         (iVar1 = IsControlBindingPressed(0x10), iVar1 != 0)) {
        DAT_00c46c5c = 10;
        FUN_004abcf0();
        InitSoundAndNewGameStateFile(0xac);
        PlaySoundID(0xac,100,0,0,0x3fb33333);
      }
      else {
        SetOptionsMenu(0xc);
      }
      DAT_00c46c5c = DAT_00c46c5c + -1;
    }
  }
  iVar1 = GetUserInput_stub(0x74);
  uVar4 = (uint)(iVar1 != 0);
  iVar1 = GetUserInput_stub(0x75);
  if (iVar1 != 0) {
    uVar4 = 2;
  }
  iVar1 = GetUserInput_stub(0x77);
  if (iVar1 != 0) {
    uVar4 = 3;
  }
  iVar1 = GetUserInput_stub(0x78);
  if (iVar1 != 0) {
    uVar4 = 4;
  }
  iVar1 = GetUserInput_stub(0x79);
  if (iVar1 == 0) {
    if (uVar4 == 0) goto LAB_004aebfd;
  }
  else {
    uVar4 = 5;
  }
  uVar2 = CurrentGraphicsMode();
  if (uVar2 != uVar4) {
    SetActiveBitmapSlot(uVar4);
  }
LAB_004aebfd:
  iVar1 = GetUserInput_stub(0x2c);
  if ((iVar1 != 0) &&
     (iVar1 = LoadSoundOrUpdateGraphixBufferForCutscene(0,&local_28,&local_2c,&local_30,local_24),
     iVar1 != 0)) {
    PauseAudioLinePlayback();
    StopActiveStreamedWork();
    uVar5 = GetWindowWidth();
    uVar3 = GetWindowHeight();
    DAT_00c46c60 = DAT_00c46c60 + 1;
    if (999 < DAT_00c46c60) {
      DAT_00c46c60 = 1;
    }
    DrawGraphicsTextinMem_2(local_20,s_grab_03ld_bmp_00518ea0,DAT_00c46c60);
    FUN_00493d00(local_20,local_28,local_2c,uVar5,uVar3,local_30);
    ConfirmGraphicsInitialised();
    MessageBeep(0xffffffff);
  }
  return;
}


