// Address: 0x00494C50

void SetCurrentDirectoryToExePath(void)

{
  char cVar1;
  char *pcVar2;
  DWORD DVar3;
  uint uVar4;
  int iVar5;
  CHAR local_400 [1024];
  
  DVar3 = GetModuleFileNameA((HMODULE)0x0,local_400,0x400);
  if (DVar3 != 0) {
    uVar4 = 0xffffffff;
    pcVar2 = local_400;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    for (iVar5 = ~uVar4 - 2; 0 < iVar5; iVar5 = iVar5 + -1) {
      if (local_400[iVar5] == '\\') {
        local_400[iVar5] = '\0';
        break;
      }
    }
    SetCurrentDirectoryA(local_400);
  }
  return;
}


