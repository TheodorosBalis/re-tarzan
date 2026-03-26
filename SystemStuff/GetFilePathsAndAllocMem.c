// Address: 0x004B563B

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetFilePathsAndAllocMem(void)

{
  char cVar1;
  size_t sVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  
  if (DAT_00c4838c == 0) {
    ConvertStringBuffersIfNeeded();
  }
  iVar5 = 0;
  for (pcVar6 = DAT_00c46cb4; *pcVar6 != '\0'; pcVar6 = pcVar6 + sVar2 + 1) {
    if (*pcVar6 != '=') {
      iVar5 = iVar5 + 1;
    }
    sVar2 = FastStrlen(pcVar6);
  }
  puVar3 = AllocateIfNullThenInit_stub(iVar5 * 4 + 4);
  _DAT_00c46c90 = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = *DAT_00c46cb4;
  pcVar6 = DAT_00c46cb4;
  while (cVar1 != '\0') {
    sVar2 = FastStrlen(pcVar6);
    if (*pcVar6 != '=') {
      pvVar4 = AllocateIfNullThenInit_stub(sVar2 + 1);
      *puVar3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      CopyFilePathsToMem(*puVar3,pcVar6);
      puVar3 = puVar3 + 1;
    }
    pcVar6 = pcVar6 + sVar2 + 1;
    cVar1 = *pcVar6;
  }
  AllocOrFreeMemOnHeapPTR(DAT_00c46cb4);
  DAT_00c46cb4 = (char *)0x0;
  *puVar3 = 0;
  _DAT_00c48388 = 1;
  return;
}


