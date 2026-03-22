/* Address: 0x004B6571 */

LPVOID SafelyMemAlloc(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint _Size;
  LPVOID local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &DAT_004ba900;
  puStack_10 = &LAB_004b033c;
  local_14 = ExceptionList;
  uVar2 = param_1 * param_2;
  uVar3 = uVar2;
  ExceptionList = &local_14;
  if (uVar2 < 0xffffffe1) {
    if (uVar2 == 0) {
      uVar3 = 1;
    }
    uVar3 = uVar3 + 0xf & 0xfffffff0;
    ExceptionList = &local_14;
  }
  do {
    local_24 = (LPVOID)0x0;
    if (uVar3 < 0xffffffe1) {
      if (OsVerResult == 3) {
        if (uVar2 <= DAT_00c47240) {
          MemAllocOrEnterCS(9);
          local_8 = 0;
          local_24 = (LPVOID)FUN_004b2b34(uVar2);
          local_8 = 0xffffffff;
          FUN_004b660a();
          _Size = uVar2;
          if (local_24 == (void *)0x0) goto LAB_004b665e;
LAB_004b664d:
          fillstackbuffer(local_24,0,_Size);
        }
LAB_004b6659:
        if (local_24 != (LPVOID)0x0) {
          ExceptionList = local_14;
          return local_24;
        }
      }
      else {
        if ((OsVerResult != 2) || (DAT_0051b584 < uVar3)) goto LAB_004b6659;
        MemAllocOrEnterCS(9);
        local_8 = 1;
        local_24 = (LPVOID)FUN_004b32e1(uVar3 >> 4);
        local_8 = 0xffffffff;
        FUN_004b6693();
        _Size = uVar3;
        if (local_24 != (void *)0x0) goto LAB_004b664d;
      }
LAB_004b665e:
      local_24 = HeapAlloc(newHeapPTR,8,uVar3);
    }
    if (local_24 != (LPVOID)0x0) {
      ExceptionList = local_14;
      return local_24;
    }
    if (DAT_00c46d34 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
    iVar1 = FUN_004b360d(uVar3);
    if (iVar1 == 0) {
      ExceptionList = local_14;
      return (LPVOID)0x0;
    }
  } while( true );
}

