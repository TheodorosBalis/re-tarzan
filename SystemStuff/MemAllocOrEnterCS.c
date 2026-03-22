/* Address: 0x004B1C6C */

void MemAllocOrEnterCS(int param_1)

{
  int *piVar1;
  LPCRITICAL_SECTION lpCriticalSection;
  
  piVar1 = (int *)(&DAT_0051948c + param_1 * 4);
  if (*(int *)(&DAT_0051948c + param_1 * 4) == 0) {
    lpCriticalSection = AllocateIfNullThenInit_stub(0x18);
    if (lpCriticalSection == (LPCRITICAL_SECTION)0x0) {
      __amsg_exit(0x11);
    }
    MemAllocOrEnterCS(0x11);
    if (*piVar1 == 0) {
      InitializeCriticalSection(lpCriticalSection);
      *piVar1 = (int)lpCriticalSection;
    }
    else {
      AllocOrFreeMemOnHeapPTR();
    }
    LeaveCSforObjectInTable(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)*piVar1);
  return;
}

