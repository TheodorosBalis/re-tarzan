/* Address: 0x0049DE10 */

void JoystickScanAndCaptureInput(void)

{
  MMRESULT MVar1;
  int iVar2;
  UINT uJoyID;
  tagJOYCAPSA *ptVar3;
  joyinfo_tag local_1a4;
  tagJOYCAPSA local_194;
  
  uJoyID = 0;
  DAT_00723d28 = 0;
  do {
    (&DAT_00723ce8)[uJoyID] = 0xffffffff;
    (&DAT_00723cd8)[uJoyID] = 0;
    MVar1 = joyGetPos(uJoyID,&local_1a4);
    if (MVar1 == 0) {
      ptVar3 = &local_194;
      for (iVar2 = 0x65; iVar2 != 0; iVar2 = iVar2 + -1) {
        ptVar3->wMid = 0;
        ptVar3->wPid = 0;
        ptVar3 = (tagJOYCAPSA *)ptVar3->szPname;
      }
      MVar1 = joyGetDevCapsA(uJoyID,&local_194,0x194);
      if (MVar1 == 0) {
        (&DAT_007237d4)[uJoyID] =
             (local_194.wYmax * 0x21 + local_194.wYmin * -0x21) / 100 + local_194.wYmin;
        (&DAT_00723c98)[uJoyID] =
             (local_194.wYmax * 0x42 + local_194.wYmin * -0x42) / 100 + local_194.wYmin;
        (&DAT_00723c54)[uJoyID] =
             (local_194.wXmax * 0x21 + local_194.wXmin * -0x21) / 100 + local_194.wXmin;
        DAT_00723d28 = DAT_00723d28 + 1;
        (&DAT_00723c14)[uJoyID] =
             (local_194.wXmax * 0x42 + local_194.wXmin * -0x42) / 100 + local_194.wXmin;
        (&DAT_00723cd8)[uJoyID] = (undefined1)local_194.wNumButtons;
      }
    }
    uJoyID = uJoyID + 1;
  } while ((int)uJoyID < 0x10);
  CaptureKInputsInBuffer();
  return;
}

