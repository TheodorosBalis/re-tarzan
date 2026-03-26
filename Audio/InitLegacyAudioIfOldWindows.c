// Address: 0x004A15F0

void InitLegacyAudioIfOldWindows(void)

{
  UINT_PTR uDeviceID;
  MMRESULT MVar1;
  int iVar2;
  _OSVERSIONINFOA *p_Var3;
  tagAUXCAPSA local_c4;
  _OSVERSIONINFOA local_94;
  
  p_Var3 = &local_94;
  for (iVar2 = 0x25; iVar2 != 0; iVar2 = iVar2 + -1) {
    p_Var3->dwOSVersionInfoSize = 0;
    p_Var3 = (_OSVERSIONINFOA *)&p_Var3->dwMajorVersion;
  }
  DAT_00724ac8 = 0;
  local_94.dwOSVersionInfoSize = 0x94;
  GetVersionExA(&local_94);
  if (local_94.dwPlatformId != 2) {
    uDeviceID = auxGetNumDevs();
    while ((uDeviceID = uDeviceID - 1, -1 < (int)uDeviceID && (DAT_00724ac8 < 8))) {
      MVar1 = auxGetDevCapsA(uDeviceID,&local_c4,0x30);
      if ((MVar1 == 0) && (((byte)local_c4.wTechnology & 3) != 0)) {
        iVar2 = DAT_00724ac8 * 8;
        (&DAT_00724238)[DAT_00724ac8 * 2] = uDeviceID;
        auxGetVolume(uDeviceID,(LPDWORD)(&DAT_0072423c + iVar2));
        DAT_00724ac8 = DAT_00724ac8 + 1;
      }
    }
  }
  return;
}


