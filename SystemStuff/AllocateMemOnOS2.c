// Address: 0x004AFF2C

void AllocateMemOnOS2(uint param_1)

{
  int iVar1;
  uint dwBytes;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004ba4d0;
  puStack_10 = &LAB_004b033c;
  local_14 = ExceptionList;
  if (OsVerResult == 3) {
    ExceptionList = &local_14;
    if (param_1 <= DAT_00c47240) {
      ExceptionList = &local_14;
      MemAllocOrEnterCS(9);
      local_8 = 0;
      iVar1 = FUN_004b2b34(param_1);
      local_8 = 0xffffffff;
      FUN_004aff93();
      if (iVar1 != 0) {
        ExceptionList = local_14;
        return;
      }
    }
  }
  else {
    ExceptionList = &local_14;
    if (OsVerResult == 2) {
      if (param_1 == 0) {
        dwBytes = 0x10;
      }
      else {
        dwBytes = param_1 + 0xf & 0xfffffff0;
      }
      ExceptionList = &local_14;
      if (dwBytes <= DAT_0051b584) {
        ExceptionList = &local_14;
        MemAllocOrEnterCS(9);
        local_8 = 1;
        iVar1 = FUN_004b32e1(dwBytes >> 4);
        local_8 = 0xffffffff;
        FUN_004afff2();
        if (iVar1 != 0) {
          ExceptionList = local_14;
          return;
        }
      }
      goto LAB_004b000b;
    }
  }
  if (param_1 == 0) {
    param_1 = 1;
  }
  dwBytes = param_1 + 0xf & 0xfffffff0;
LAB_004b000b:
  HeapAlloc(newHeapPTR,0,dwBytes);
  ExceptionList = local_14;
  return;
}


