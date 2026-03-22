/* Address: 0x004AFE05 */

void AllocOrFreeMemOnHeapPTR(LPVOID param_1)

{
  int iVar1;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004ba4b8;
  puStack_10 = &LAB_004b033c;
  local_14 = ExceptionList;
  if (param_1 == (LPVOID)0x0) {
    return;
  }
  if (OsVerResult == 3) {
    ExceptionList = &local_14;
    MemAllocOrEnterCS(9);
    local_8 = 0;
    local_20 = FUN_004b27e0(param_1);
    if (local_20 != 0) {
      FUN_004b280b(local_20,param_1);
    }
    local_8 = 0xffffffff;
    FUN_004afe6f();
    iVar1 = local_20;
  }
  else {
    ExceptionList = &local_14;
    if (OsVerResult != 2) goto LAB_004afed1;
    ExceptionList = &local_14;
    MemAllocOrEnterCS(9);
    local_8 = 1;
    local_28 = FUN_004b3245(param_1,&local_2c,&local_24);
    if (local_28 != 0) {
      FUN_004b329c(local_2c,local_24,local_28);
    }
    local_8 = 0xffffffff;
    FUN_004afec7();
    iVar1 = local_28;
  }
  if (iVar1 != 0) {
    ExceptionList = local_14;
    return;
  }
LAB_004afed1:
  HeapFree(newHeapPTR,0,param_1);
  ExceptionList = local_14;
  return;
}

