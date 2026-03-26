// Address: 0x004A3C50

void FillArrayOfNumbers255(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (param_1 ^ (int)param_1 >> 0x1f) - ((int)param_1 >> 0x1f);
  if (iVar4 < 0x3d) {
    if (iVar4 < 10) {
      iVar4 = 10;
    }
  }
  else {
    iVar4 = 0x46;
  }
  iVar1 = 0;
  iVar3 = 0;
  do {
    iVar2 = iVar3 / 0x32;
    if (0xfe < iVar2) {
      iVar2 = 0xff;
    }
    (&arrayofnumbers255)[iVar1] = (char)iVar2;
    iVar1 = iVar1 + 1;
    iVar3 = iVar3 + iVar4;
  } while (iVar1 < 0x100);
  g_IsBrightnessLookupIdentity = (uint)(iVar4 == 0x32);
  return;
}


