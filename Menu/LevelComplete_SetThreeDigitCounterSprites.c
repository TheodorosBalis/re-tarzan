/* Address: 0x0045E490 */

void CMenu::LevelComplete_SetThreeDigitCounterSprites(int param_1,int param_2,short param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2 / 100;
  iVar2 = 2;
  if (0 < iVar1) {
    iVar2 = 1;
    param_2 = param_2 % 100;
    *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 0x80;
    *(short *)(param_1 + 0xc) = (short)iVar1 + param_3;
    param_1 = param_1 + 0x144;
  }
  if ((0 < param_2 / 10) || (iVar2 != 2)) {
    *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 0x80;
    *(short *)(param_1 + 0xc) = (short)(param_2 / 10) + param_3;
    param_1 = param_1 + 0x144;
    param_2 = param_2 % 10;
    iVar2 = iVar2 + -1;
  }
  *(byte *)(param_1 + 0xf) = *(byte *)(param_1 + 0xf) | 0x80;
  iVar1 = param_1 + 0xe;
  *(short *)(param_1 + 0xc) = (short)param_2 + param_3;
  for (; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(ushort *)(iVar1 + 0x144) = *(ushort *)(iVar1 + 0x144) & 0x7fff;
    iVar1 = iVar1 + 0x144;
  }
  return;
}

