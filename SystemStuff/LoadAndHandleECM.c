// Address: 0x004AC1D0

void LoadAndHandleECM(uint param_1)

{
  if (DAT_00517828 != 0) {
    DAT_00517828 = 0;
    LoadAndHandleMovie(0xffffffff,0);
    LoadAndHandleMovie(0xffffffff,0);
  }
  LoadAndHandleMovie(param_1 & 0xffff3fff,1);
  return;
}


