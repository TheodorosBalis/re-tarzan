/* Address: 0x004B17B6 */

undefined4 LoadGameFileviaCS(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 < DAT_00c47360) &&
     ((*(byte *)((&DAT_00c47260)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    EnsureObjectCriticalSectionAndEnter(param_1);
    uVar1 = LoadGameFileInMem(param_1,param_2,param_3);
    LeaveCSforObjectInTable2(param_1);
    return uVar1;
  }
  puVar2 = (undefined4 *)GetOrCreateTlsBlock_Stub2();
  *puVar2 = 9;
  puVar2 = (undefined4 *)GetOrCreateTlsBlock_stub3();
  *puVar2 = 0;
  return 0xffffffff;
}

