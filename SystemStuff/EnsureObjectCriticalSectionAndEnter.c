// Address: 0x004B698F

void EnsureObjectCriticalSectionAndEnter(uint param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (param_1 & 0x1f) * 0x24;
  iVar1 = (&DAT_00c47260)[(int)param_1 >> 5] + iVar2;
  if (*(int *)(iVar1 + 8) == 0) {
    MemAllocOrEnterCS(0x11);
    if (*(int *)(iVar1 + 8) == 0) {
      InitializeCriticalSection((LPCRITICAL_SECTION)(iVar1 + 0xc));
      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    }
    LeaveCSforObjectInTable(0x11);
  }
  EnterCriticalSection((LPCRITICAL_SECTION)((&DAT_00c47260)[(int)param_1 >> 5] + 0xc + iVar2));
  return;
}


