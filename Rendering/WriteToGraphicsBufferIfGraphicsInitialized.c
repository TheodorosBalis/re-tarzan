// Address: 0x0049B4A0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 WriteToGraphicsBufferIfGraphicsInitialized(uint param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  if ((((isGraphicsInitialized != 0) && (DAT_00722864 == 0)) && (param_2 != (int *)0x0)) &&
     (param_3 != (int *)0x0)) {
    *param_3 = 0x280;
    *param_2 = (int)lpvBitsColorDataPTR;
    DAT_00722864 = 1;
    if ((param_1 != 0xffffffff) && (lpvBitsColorDataPTR != (uint *)0x0)) {
      uVar1 = param_1 >> 3 & 0x1f0000 | param_1 & 0xf800;
      _DAT_00722820 = (uVar1 >> 3 | param_1 & 0xf8) >> 3;
      uVar1 = (uVar1 >> 3 | param_1 & 0xf8) >> 3;
      puVar3 = lpvBitsColorDataPTR;
      for (iVar2 = *param_3 * 0xf0 >> 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = uVar1 | uVar1 << 0x10;
        puVar3 = puVar3 + 1;
      }
    }
    return 1;
  }
  return 0;
}


