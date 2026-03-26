// Address: 0x004B56F4

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void GetGamePathAndFillCPBuffers(void)

{
  void *pvVar1;
  char *pcVar2;
  int local_c;
  int local_8;
  
  if (DAT_00c4838c == 0) {
    ConvertStringBuffersIfNeeded();
  }
  GetModuleFileNameA((HMODULE)0x0,&DAT_00c46d3c,0x104);
  _DAT_00c46ca0 = &DAT_00c46d3c;
  pcVar2 = &DAT_00c46d3c;
  if (*EXEfilePath != '\0') {
    pcVar2 = EXEfilePath;
  }
  ScanFilePath(pcVar2,0,0,&local_8,&local_c);
  pvVar1 = AllocateIfNullThenInit_stub(local_c + local_8 * 4);
  if (pvVar1 == (void *)0x0) {
    __amsg_exit(8);
  }
  ScanFilePath(pcVar2,pvVar1,(void *)((int)pvVar1 + local_8 * 4),&local_8,&local_c);
  _DAT_00c46c88 = pvVar1;
  _DAT_00c46c84 = local_8 + -1;
  return;
}


