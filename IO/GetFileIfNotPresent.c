/* Address: 0x004AF426 */

undefined4 GetFileIfNotPresent(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = InitializeObjectTable();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = GetGameFileInfo(param_1,param_2,param_3,iVar1);
  LeaveCSForIndex(iVar1);
  return uVar2;
}

