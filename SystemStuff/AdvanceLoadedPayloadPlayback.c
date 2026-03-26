// Address: 0x004ABF10

undefined4 AdvanceLoadedPayloadPlayback(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0x10) < *(int *)(param_1 + 0x1c + iVar1 * 8)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    return *(undefined4 *)(param_1 + 0x20 + *(int *)(param_1 + 0xc) * 8);
  }
  *(undefined4 *)(param_1 + 0x10) = 1;
  if (iVar1 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0xc) = iVar1 + 1;
    return *(undefined4 *)(param_1 + 0x20 + (iVar1 + 1) * 8);
  }
  DAT_00533ff8._0_1_ = (byte)DAT_00533ff8 | 0x10;
  return *(undefined4 *)(param_1 + 0x20 + *(int *)(param_1 + 0xc) * 8);
}


