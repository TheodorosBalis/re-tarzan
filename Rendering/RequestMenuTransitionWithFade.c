/* Address: 0x00452B50 */

void RequestMenuTransitionWithFade(int param_1)

{
  CaptureKInputsInBuffer();
  TimeIDLEinMenu = 0;
  if (param_1 != ptrToDecideWhichMenu2) {
    if (*(int *)(ptrToDecideWhichMenu + 0x1c) != -1) {
      LoadSoundFileAndInitAudio(*(int *)(ptrToDecideWhichMenu + 0x1c),0,0);
    }
    ptrToDecideWhichMenu2 = param_1;
    InitiateFade(2,0x400);
  }
  return;
}

