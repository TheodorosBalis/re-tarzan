// Address: 0x004942D0

int GetBackgroundMusicTrackLengthSeconds(undefined4 param_1)

{
  MCIERROR MVar1;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined1 local_10 [4];
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = 0x4001;
  local_4 = param_1;
  MVar1 = mciSendCommandA(DAT_0053a2f8,0x814,0x110,(DWORD_PTR)local_10);
  if ((MVar1 == 0) && (local_c == 0x440)) {
    local_18 = 2;
    mciSendCommandA(DAT_0053a2f8,0x80d,0x400,(DWORD_PTR)local_1c);
    local_8 = 1;
    local_4 = param_1;
    MVar1 = mciSendCommandA(DAT_0053a2f8,0x814,0x110,(DWORD_PTR)local_10);
    if (MVar1 == 0) {
      return (local_c >> 8 & 0xff) + (local_c & 0xff) * 0x3c;
    }
  }
  return 0;
}


