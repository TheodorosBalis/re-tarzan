// Address: 0x00494080

bool IsCurrentEcmTrackPlaying(void)

{
  MCIERROR MVar1;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_10 = 0;
  local_4 = 0;
  local_8 = 4;
  MVar1 = mciSendCommandA(DAT_0053a2f8,0x814,0x102,(DWORD_PTR)&local_10);
  if (MVar1 != 0) {
    return false;
  }
  return local_c == 0x20e;
}


