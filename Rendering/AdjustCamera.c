/* Address: 0x0040A5E0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void AdjustCamera(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_40 [2];
  undefined4 local_38;
  undefined1 local_30 [16];
  undefined1 local_20 [32];
  
  if (*(int *)(param_1 + 0x48) != 0) {
    *(int *)(param_1 + 0x48) = *(int *)(param_1 + 0x48) + -1;
  }
  FUN_004a2540(param_1 + 0x30,local_20);
  FUN_004a2420(local_20,param_1,local_40);
  iVar1 = param_1 + 0x68;
  local_40[0] = 0;
  local_38 = 0;
  FUN_004a2540(param_1 + 0x50,iVar1);
  if (*(int *)(param_1 + 100) != 0) {
    FUN_004a2b10(iVar1,param_1 + 0x58);
  }
  FUN_004a2420(iVar1,local_40,local_30);
  FUN_004a2c00(iVar1,local_20,iVar1);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x14);
  iVar1 = *(int *)(param_1 + 0xc) * *(int *)(param_1 + 0x58);
  *(int *)(param_1 + 0x7c) = (int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc;
  iVar1 = *(int *)(param_1 + 0x10) * *(int *)(param_1 + 0x5c);
  *(int *)(param_1 + 0x80) = (int)(iVar1 + (iVar1 >> 0x1f & 0xfffU)) >> 0xc;
  if (*(int *)(param_1 + 0x48) != 0) {
    iVar1 = FUN_00489f40(*(int *)(param_1 + 0x4c) << 2);
    iVar2 = FUN_00489f40(*(int *)(param_1 + 0x4c) << 1);
    *(int *)(param_1 + 0x80) = *(int *)(param_1 + 0x80) + (iVar1 - iVar2);
  }
  _DAT_005176a8 = *(undefined2 *)(param_1 + 0x58);
  _DAT_005176aa = 0;
  _DAT_005176ac = 0;
  _DAT_005176ae = 0;
  _DAT_005176b0 = *(undefined2 *)(param_1 + 0x5c);
  _DAT_005176b2 = 0;
  _DAT_005176b4 = 0;
  _DAT_005176b6 = 0;
  _DAT_005176b8 = *(undefined2 *)(param_1 + 0x60);
  FUN_004abc30(param_1);
  return;
}

