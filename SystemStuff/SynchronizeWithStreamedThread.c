// Address: 0x004980E0

void SynchronizeWithStreamedThread(char param_1)

{
  HANDLE pvVar1;
  DWORD DVar2;
  int iVar3;
  
  if (param_1 == '\0') {
    if (DAT_00719db4 != 0) {
      DVar2 = DAT_00719dac;
      pvVar1 = GetCurrentProcess();
      SetPriorityClass(pvVar1,DVar2);
      iVar3 = DAT_00719db0;
      pvVar1 = GetCurrentThread();
      SetThreadPriority(pvVar1,iVar3);
      DAT_00719db4 = 0;
    }
  }
  else if (DAT_00719db4 == 0) {
    pvVar1 = GetCurrentProcess();
    DAT_00719dac = GetPriorityClass(pvVar1);
    pvVar1 = GetCurrentThread();
    DAT_00719db0 = GetThreadPriority(pvVar1);
    DVar2 = 0x80;
    pvVar1 = GetCurrentProcess();
    SetPriorityClass(pvVar1,DVar2);
    iVar3 = 2;
    pvVar1 = GetCurrentThread();
    SetThreadPriority(pvVar1,iVar3);
    if (DAT_00719d9c != (HANDLE)0x0) {
      SetThreadPriority(DAT_00719d9c,-2);
    }
    DAT_00719db4 = 1;
    return;
  }
  return;
}


