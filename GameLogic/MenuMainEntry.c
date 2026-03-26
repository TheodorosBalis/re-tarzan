// Address: 0x00452BC0

undefined4 MenuMainEntry(void)

{
  TotalGameLoopTicks = TotalGameLoopTicks + 1;
  IsOnMainMenu();
  IsKeyOnMenuPressed();
  if (ptrToDecideWhichMenu == (int *)0x0) {
    if (ptrToDecideWhichMenu2 == (int *)0x0) {
      return 1;
    }
  }
  else if (ptrToDecideWhichMenu == ptrToDecideWhichMenu2) goto LAB_00452c78;
  if ((FadeBrightness == 0) && (3 < FadeStatus)) {
    if ((ptrToDecideWhichMenu != (int *)0x0) && (*ptrToDecideWhichMenu != 0)) {
      ReleaseMenuTextBlockIfUnused(*ptrToDecideWhichMenu + 4,0xffffffff);
    }
    ptrToDecideWhichMenu = ptrToDecideWhichMenu2;
    if (ptrToDecideWhichMenu2[6] != -1) {
      LoadSoundFileAndInitAudio(ptrToDecideWhichMenu2[6],0,0);
    }
    if ((code *)ptrToDecideWhichMenu[5] != (code *)0x0) {
      (*(code *)ptrToDecideWhichMenu[5])(ptrToDecideWhichMenu);
    }
    InitiateFade(1,0x400);
    TimeIDLEinMenu = 0;
  }
  if (ptrToDecideWhichMenu != ptrToDecideWhichMenu2) {
    return 1;
  }
LAB_00452c78:
  if ((code *)ptrToDecideWhichMenu[4] != (code *)0x0) {
    (*(code *)ptrToDecideWhichMenu[4])(ptrToDecideWhichMenu);
  }
  return 1;
}


