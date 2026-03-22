/* Address: 0x004B0C57 */

undefined4 CheckToCloseHandle(uint param_1)

{
  int iVar1;
  int iVar2;
  HANDLE hObject;
  BOOL BVar3;
  DWORD DVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_004b694d(param_1);
  if (iVar1 != -1) {
    if ((param_1 == 1) || (param_1 == 2)) {
      iVar1 = FUN_004b694d(2);
      iVar2 = FUN_004b694d(1);
      if (iVar2 == iVar1) goto LAB_004b0ca5;
    }
    hObject = (HANDLE)FUN_004b694d(param_1);
    BVar3 = CloseHandle(hObject);
    if (BVar3 == 0) {
      DVar4 = GetLastError();
      goto LAB_004b0ca7;
    }
  }
LAB_004b0ca5:
  DVar4 = 0;
LAB_004b0ca7:
  FUN_004b68ce(param_1);
  *(undefined1 *)((&DAT_00c47260)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) = 0;
  if (DVar4 == 0) {
    uVar5 = 0;
  }
  else {
    FUN_004b157d(DVar4);
    uVar5 = 0xffffffff;
  }
  return uVar5;
}

