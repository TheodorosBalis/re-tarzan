/* Address: 0x004B16DA */

uint LoadEfGinMemSafely(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) == 0) {
      param_1[3] = uVar2 | 1;
      if ((uVar2 & 0x10c) == 0) {
        FUN_004b6a10(param_1);
      }
      else {
        *param_1 = param_1[2];
      }
      iVar3 = LoadGameFileviaCS(param_1[4],param_1[2],param_1[6]);
      param_1[1] = iVar3;
      if ((iVar3 != 0) && (iVar3 != -1)) {
        if ((param_1[3] & 0x82) == 0) {
          uVar2 = param_1[4];
          if (uVar2 == 0xffffffff) {
            puVar4 = &DAT_00519468;
          }
          else {
            puVar4 = (undefined *)((&DAT_00c47260)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
          }
          if ((puVar4[4] & 0x82) == 0x82) {
            param_1[3] = param_1[3] | 0x2000;
          }
        }
        if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
          param_1[6] = 0x1000;
        }
        param_1[1] = iVar3 + -1;
        bVar1 = *(byte *)*param_1;
        *param_1 = (byte *)*param_1 + 1;
        return (uint)bVar1;
      }
      param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
      param_1[1] = 0;
    }
    else {
      param_1[3] = uVar2 | 0x20;
    }
  }
  return 0xffffffff;
}

