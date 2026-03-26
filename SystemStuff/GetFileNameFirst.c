// Address: 0x004948E0

undefined1 * GetFileNameFirst(void)

{
  char cVar1;
  DWORD DVar2;
  uint uVar3;
  char *pcVar4;
  
  DVar2 = GetModuleFileNameA((HMODULE)0x0,&DAT_0053a3ec,0x400);
  if (DVar2 == 0) {
    return (undefined1 *)0x0;
  }
  uVar3 = 0xffffffff;
  pcVar4 = &DAT_0053a3ec;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  (&DAT_0053a3e8)[~uVar3] = 99;
  uVar3 = 0xffffffff;
  pcVar4 = &DAT_0053a3ec;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  (&DAT_0053a3e9)[~uVar3] = 0x66;
  uVar3 = 0xffffffff;
  pcVar4 = &DAT_0053a3ec;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  (&DAT_0053a3ea)[~uVar3] = 0x67;
  return &DAT_0053a3ec;
}


