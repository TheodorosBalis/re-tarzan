// Address: 0x00494380

void PlayEcmTrackFromSecond(uint param_1,uint param_2)

{
  MCIERROR MVar1;
  DWORD DVar2;
  undefined1 local_18 [4];
  uint local_14;
  uint local_10;
  undefined1 local_c [4];
  undefined4 local_8;
  
  if ((int)param_2 < 0) {
    param_2 = 0;
  }
  param_2 = param_2 % DAT_0053a314;
  if (DAT_0053a308 == 0) {
    local_8 = 10;
    mciSendCommandA(DAT_0053a2f8,0x80d,0x400,(DWORD_PTR)local_c);
    local_14 = ((uint)(byte)((longlong)(int)param_2 % 0x3c) << 8 | (int)param_2 / 0x3c & 0xffffU) <<
               8 | param_1 & 0xff;
    local_10 = ((uint)(byte)((ulonglong)DAT_0053a314 % 0x3c) << 8 | DAT_0053a314 / 0x3c & 0xffff) <<
               8 | param_1 & 0xff;
    MVar1 = mciSendCommandA(DAT_0053a2f8,0x806,0xc,(DWORD_PTR)local_18);
    DAT_0053a304 = (uint)(MVar1 == 0);
  }
  else {
    DAT_0053a304 = 0;
  }
  DAT_0053a310 = param_1;
  DVar2 = timeGetTime();
  DAT_0053a300 = DVar2 + param_2 * -1000;
  return;
}


