// Address: 0x004B6A7D

uint AllocMemAndFetchGameFile(LPCSTR param_1,uint param_2,uint param_3,uint param_4)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  HANDLE hFile;
  DWORD DVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  _SECURITY_ATTRIBUTES local_20;
  DWORD local_14;
  DWORD local_10;
  DWORD local_c;
  byte local_5;
  
  bVar9 = (param_2 & 0x80) == 0;
  local_20.nLength = 0xc;
  local_20.lpSecurityDescriptor = (LPVOID)0x0;
  if (bVar9) {
    local_5 = 0;
  }
  else {
    local_5 = 0x10;
  }
  local_20.bInheritHandle = (BOOL)bVar9;
  if (((param_2 & 0x8000) == 0) && (((param_2 & 0x4000) != 0 || (DAT_00c46ea4 != 0x8000)))) {
    local_5 = local_5 | 0x80;
  }
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_10 = 0x80000000;
  }
  else if (uVar2 == 1) {
    local_10 = 0x40000000;
  }
  else {
    if (uVar2 != 2) goto LAB_004b6b81;
    local_10 = 0xc0000000;
  }
  if (param_3 == 0x10) {
    local_14 = 0;
  }
  else if (param_3 == 0x20) {
    local_14 = 1;
  }
  else if (param_3 == 0x30) {
    local_14 = 2;
  }
  else {
    if (param_3 != 0x40) goto LAB_004b6b81;
    local_14 = 3;
  }
  uVar2 = param_2 & 0x700;
  if (uVar2 < 0x401) {
    if ((uVar2 == 0x400) || (uVar2 == 0)) {
      local_c = 3;
    }
    else if (uVar2 == 0x100) {
      local_c = 4;
    }
    else {
      if (uVar2 == 0x200) goto LAB_004b6b9b;
      if (uVar2 != 0x300) goto LAB_004b6b81;
      local_c = 2;
    }
  }
  else {
    if (uVar2 != 0x500) {
      if (uVar2 == 0x600) {
LAB_004b6b9b:
        local_c = 5;
        goto LAB_004b6bab;
      }
      if (uVar2 != 0x700) {
LAB_004b6b81:
        puVar4 = (undefined4 *)GetOrCreateTlsBlock_Stub2();
        *puVar4 = 0x16;
        puVar4 = (undefined4 *)GetOrCreateTlsBlock_stub3();
        *puVar4 = 0;
        return 0xffffffff;
      }
    }
    local_c = 1;
  }
LAB_004b6bab:
  uVar2 = 0x80;
  if (((param_2 & 0x100) != 0) && ((~DAT_00c46c70 & param_4 & 0x80) == 0)) {
    uVar2 = 1;
  }
  if ((param_2 & 0x40) != 0) {
    uVar2 = uVar2 | 0x4000000;
    local_10 = CONCAT13(local_10._3_1_,0x10000);
  }
  if ((param_2 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x100;
  }
  if ((param_2 & 0x20) == 0) {
    if ((param_2 & 0x10) != 0) {
      uVar2 = uVar2 | 0x10000000;
    }
  }
  else {
    uVar2 = uVar2 | 0x8000000;
  }
  uVar3 = AllocateObjectSlot();
  if (uVar3 == 0xffffffff) {
    puVar4 = (undefined4 *)GetOrCreateTlsBlock_Stub2();
    *puVar4 = 0x18;
    puVar4 = (undefined4 *)GetOrCreateTlsBlock_stub3();
    *puVar4 = 0;
    return 0xffffffff;
  }
  hFile = CreateFileA(param_1,local_10,local_14,&local_20,local_c,uVar2,(HANDLE)0x0);
  if (hFile != (HANDLE)0xffffffff) {
    DVar5 = GetFileType(hFile);
    if (DVar5 != 0) {
      if (DVar5 == 2) {
        local_5 = local_5 | 0x40;
      }
      else if (DVar5 == 3) {
        local_5 = local_5 | 8;
      }
      SetOsHandleForFileDescriptor(uVar3,hFile);
      iVar8 = (uVar3 & 0x1f) * 0x24;
      param_1._3_1_ = local_5 & 0x48;
      *(byte *)((&DAT_00c47260)[(int)uVar3 >> 5] + 4 + iVar8) = local_5 | 1;
      if ((((local_5 & 0x48) == 0) && ((local_5 & 0x80) != 0)) && ((param_2 & 2) != 0)) {
        local_14 = FUN_004b1667(uVar3,0xffffffff,2);
        if (local_14 == 0xffffffff) {
          piVar6 = (int *)GetOrCreateTlsBlock_stub3();
          if (*piVar6 == 0x83) goto LAB_004b6d25;
        }
        else {
          param_3 = param_3 & 0xffffff;
          iVar7 = LoadGameFileInMem(uVar3,(int)&param_3 + 3,1);
          if ((((iVar7 != 0) || (param_3._3_1_ != '\x1a')) ||
              (iVar7 = FUN_004b8682(uVar3,local_14), iVar7 != -1)) &&
             (iVar7 = FUN_004b1667(uVar3,0,0), iVar7 != -1)) goto LAB_004b6d25;
        }
        CheckToCloseHandleWithCS(uVar3);
        uVar2 = 0xffffffff;
      }
      else {
LAB_004b6d25:
        uVar2 = uVar3;
        if ((param_1._3_1_ == 0) && ((param_2 & 8) != 0)) {
          pbVar1 = (byte *)((&DAT_00c47260)[(int)uVar3 >> 5] + 4 + iVar8);
          *pbVar1 = *pbVar1 | 0x20;
        }
      }
      goto LAB_004b6d3e;
    }
    CloseHandle(hFile);
  }
  DVar5 = GetLastError();
  FUN_004b157d(DVar5);
  uVar2 = 0xffffffff;
LAB_004b6d3e:
  LeaveCSforObjectInTable2(uVar3);
  return uVar2;
}


