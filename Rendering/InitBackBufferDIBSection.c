// Address: 0x0049B5F0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitBackBufferDIBSection(HWND param_1)

{
  HDC hdc;
  int iVar1;
  undefined4 *puVar2;
  
  if (isGraphicsInitialized != 0) {
    return 1;
  }
  if (param_1 == (HWND)0x0) {
    return 0;
  }
  DAT_00722864 = 0;
  DAT_00722860 = param_1;
  hdc = GetDC(param_1);
  BitMapInfo_Struct = hdc;
  if (hdc == (HDC)0x0) {
    FUN_0049b6b0();
    isGraphicsInitialized = 0;
    return 0;
  }
  puVar2 = &DAT_00722830;
  for (iVar1 = 0xb; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  DAT_00722830 = 0x28;
  _DAT_0072283c = 1;
  _DAT_0072283e = 0x10;
  _DAT_00722840 = 0;
  DAT_00722834 = 0x140;
  _DAT_00722838 = 0xffffff10;
  lpvBitsColorDataPTR = 0;
  DAT_00722828 = CreateDIBSection(hdc,(BITMAPINFO *)&DAT_00722830,0,(void **)&lpvBitsColorDataPTR,
                                  (HANDLE)0x0,0);
  isGraphicsInitialized = 1;
  return 1;
}


